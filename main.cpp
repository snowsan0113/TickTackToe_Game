#define _CRT_SECURE_NO_WARNINGS
#include "DxLib.h"
#include "main.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    SetWindowText("ŽO–Ú•À‚×");
    SetGraphMode(WIDTH, HEIGHT, COLORBIT);
    ChangeWindowMode(true);
    if (DxLib_Init() == -1) {
        return -1;
    }
    SetBackgroundColor(255, 255, 255);
    SetDrawScreen(DX_SCREEN_BACK);

    int mouseX = 0, mouseY = 0;
    while (true) {
        ClearDrawScreen();
        GetMousePoint(&mouseX, &mouseY);

        ScreenFlip();
        WaitTimer(1000 / FPS);
        if (ProcessMessage() == -1) {
            break;
        }
    }
    DxLib_End();
    return 0;
}