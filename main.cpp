#define _CRT_SECURE_NO_WARNINGS
#include "DxLib.h"
#include "main.h"
#include "GameManager.h"
#include "DrawUtil.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    SetWindowText("éOñ⁄ï¿Ç◊");
    SetGraphMode(WIDTH, HEIGHT, COLORBIT);
    ChangeWindowMode(true);
    if (DxLib_Init() == -1) {
        return -1;
    }
    SetBackgroundColor(255, 255, 255);
    SetDrawScreen(DX_SCREEN_BACK);
    initGame();

    int mouseX = 0, mouseY = 0;
    while (true) {
        ClearDrawScreen();
        timer++;
        GetMousePoint(&mouseX, &mouseY);
        int screenMouseMapX = mouseX / MAP_PIXEL;
        int screenMouseMapY = mouseY / MAP_PIXEL;

        switch (status) {
        case GameStatus::WAITING:
            if (CheckHitKey(KEY_INPUT_SPACE)) {
                status = GameStatus::RUNNING;
                timer = 0;
            }

            if (timer % 200 < 100) drawText(DrawType::CENTER, WIDTH * 0.5, HEIGHT * 0.5, 30, "ÉQÅ[ÉÄÇäJénÇ∑ÇÈÇ…ÇÕÉXÉyÅ[ÉXÉLÅ[", GetColor(255, 255, 255), GetColor(0, 0, 0));
            break;
        case GameStatus::RUNNING:

            //ï\
            for (int x = 0; x < MAP_WIDTH; x++) {
                for (int y = 0; y < MAP_HEIGHT; y++) {
                    int screenX = x * MAP_PIXEL;
                    int screenY = y * MAP_PIXEL;
                    if (MAP[y][x] >= 1) {
                        DrawBox(screenX, screenY, screenX + MAP_PIXEL, screenY + MAP_PIXEL, 0xCCE5FF, true);
                    }
                    if (MAP[y][x] == 1) {
                        DrawBox(screenX, screenY, screenX + MAP_PIXEL, screenY + MAP_PIXEL, GetColor(0, 0, 0), true);

                    }

                }
            }

            char location_text[200];
            sprintf(location_text, "èÍèäÅF(%d, %d)ÅAílÅF%dÅAÉ^ÉCÉvÅF%d", screenMouseMapX, screenMouseMapY, (MAP[screenMouseMapY][screenMouseMapX]), playerType);
            drawText(DrawType::LEFT, 0, 0, 30, location_text, GetColor(255, 255, 255), GetColor(0, 0, 0));

            if ((GetMouseInput() & MOUSE_INPUT_LEFT) == 1) {
                int index = (MAP[screenMouseMapY][screenMouseMapX]) - 10;
                if (0 <= index && index <= 8) {
                    draw_obj[index].alive = 1;
                    draw_obj[index].type = playerType;
                    //playerType = !playerType;
                }
            }

            //óDèüîªíËÅiâ°Åj
            if ((draw_obj[0].type == 0 && draw_obj[1].type == 0 && draw_obj[2].type == 0) ||
                (draw_obj[3].type == 0 && draw_obj[4].type == 0 && draw_obj[5].type == 0) ||
                (draw_obj[6].type == 0 && draw_obj[7].type == 0 && draw_obj[8].type == 0)) {
                drawText(DrawType::LEFT, 0, 30, 20, "ÅZÇÃóDèüÅiâ°Åj", GetColor(255, 255, 255), GetColor(0, 0, 0));
                status = GameStatus::ENDING;
                result = 0;
                timer = 0;
            }
            if ((draw_obj[0].type == 1 && draw_obj[1].type == 1 && draw_obj[2].type == 1) ||
                (draw_obj[3].type == 1 && draw_obj[4].type == 1 && draw_obj[5].type == 1) ||
                (draw_obj[6].type == 1 && draw_obj[7].type == 1 && draw_obj[8].type == 1)) {
                drawText(DrawType::LEFT, 0, 60, 20, "Å~ÇÃóDèüÅiâ°Åj", GetColor(255, 255, 255), GetColor(0, 0, 0));
                status = GameStatus::ENDING;
                result = 1;
                timer = 0;
            }

            //óDèüîªíËÅiècÅj
            if ((draw_obj[0].type == 0 && draw_obj[3].type == 0 && draw_obj[6].type == 0) ||
                (draw_obj[1].type == 0 && draw_obj[4].type == 0 && draw_obj[7].type == 0) ||
                (draw_obj[2].type == 0 && draw_obj[5].type == 0 && draw_obj[8].type == 0)) {
                drawText(DrawType::LEFT, 0, 90, 20, "ÅZÇÃóDèüÅiècÅj", GetColor(255, 255, 255), GetColor(0, 0, 0));
                status = GameStatus::ENDING;
                result = 0;
                timer = 0;
            }
            if ((draw_obj[0].type == 1 && draw_obj[3].type == 1 && draw_obj[6].type == 1) ||
                (draw_obj[1].type == 1 && draw_obj[4].type == 1 && draw_obj[7].type == 1) ||
                (draw_obj[2].type == 1 && draw_obj[5].type == 1 && draw_obj[8].type == 1)) {
                status = GameStatus::ENDING;
                result = 1;
                timer = 0;
                drawText(DrawType::LEFT, 0, 120, 20, "Å~ÇÃóDèüÅiècÅj", GetColor(255, 255, 255), GetColor(0, 0, 0));
            }

            for (int n = 0; n < 9; n++) {
                //ï`âÊ
                if (draw_obj[n].alive == 1 && draw_obj[n].type != -1) {
                    //Ç∑Ç≈Ç…Ç†ÇÈÇ∆Ç±ÇÎÇ…ï`âÊ
                    if (draw_obj[n].type == 0) {
                        drawText(DrawType::LEFT, draw_obj[n].x, draw_obj[n].y, 50, "ÅZ", GetColor(255, 255, 255), GetColor(0, 0, 0));
                    }
                    else {
                        drawText(DrawType::LEFT, draw_obj[n].x, draw_obj[n].y, 50, "Å~", GetColor(255, 255, 255), GetColor(0, 0, 0));
                    }
                }
            }

            if (CheckHitKey(KEY_INPUT_0)) {
                playerType = 0;
            }
            if (CheckHitKey(KEY_INPUT_1)) {
                playerType = 1;
            }

            break;
        case GameStatus::ENDING:
            if (result == 0) {
                drawText(DrawType::CENTER, WIDTH * 0.5, HEIGHT * 0.5, 30, "ÅZÇÃóDèüÇ≈Ç∑", GetColor(255, 255, 255), GetColor(0, 0, 0));
            }
            if (result == 1) {
                drawText(DrawType::CENTER, WIDTH * 0.5, HEIGHT * 0.5, 30, "Å~ÇÃóDèüÇ≈Ç∑", GetColor(255, 255, 255), GetColor(0, 0, 0));
            }

            if (timer >= 100) {
                initGame();
            }
            break;
        }

        ScreenFlip();
        WaitTimer(1000 / FPS);
        if (ProcessMessage() == -1) {
            break;
        }
    }
    DxLib_End();
    return 0;
}