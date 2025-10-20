#include "DxLib.h"
#include "GameManager.h"

int initGame();

//�Q�[���̏��
GameStatus status = GameStatus::WAITING;
int timer = 0;

bool playerType = 0; //0�F�Z�A1�F�~
int result = 0;

DrawObject draw_obj[9];

//�e�}�X�F10�`19
//�}�b�v
int MAP[MAP_HEIGHT][MAP_WIDTH] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
	{0, 1, 10, 10, 10, 1, 11, 11, 11, 1, 12, 12, 12, 1, 0, 0},
	{0, 1, 10, 10, 10, 1, 11, 11, 11, 1, 12, 12, 12, 1, 0, 0},
	{0, 1, 10, 10, 10, 1, 11, 11, 11, 1, 12, 12, 12, 1, 0, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
	{0, 1, 13, 13, 13, 1, 14, 14, 14, 1, 15, 15, 15, 1, 0, 0},
	{0, 1, 13, 13, 13, 1, 14, 14, 14, 1, 15, 15, 15, 1, 0, 0},
	{0, 1, 13, 13, 13, 1, 14, 14, 14, 1, 15, 15, 15, 1, 0, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
	{0, 1, 16, 16, 16, 1, 17, 17, 17, 1, 18, 18, 18, 1, 0, 0},
	{0, 1, 16, 16, 16, 1, 17, 17, 17, 1, 18, 18, 18, 1, 0, 0},
	{0, 1, 16, 16, 16, 1, 17, 17, 17, 1, 18, 18, 18, 1, 0, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

int initGame() {
	status = GameStatus::WAITING;
	timer = 0;

	draw_obj[0] = { 3 * MAP_PIXEL, 3 * MAP_PIXEL, -1, };
	draw_obj[1] = { 7 * MAP_PIXEL, 3 * MAP_PIXEL, -1, };
	draw_obj[2] = { 11 * MAP_PIXEL, 3 * MAP_PIXEL, -1, };
	draw_obj[3] = { 3 * MAP_PIXEL, 7 * MAP_PIXEL, -1, };
	draw_obj[4] = { 7 * MAP_PIXEL, 7 * MAP_PIXEL, -1, };
	draw_obj[5] = { 11 * MAP_PIXEL, 7 * MAP_PIXEL, -1, };
	draw_obj[6] = { 3 * MAP_PIXEL, 11 * MAP_PIXEL, -1, };
	draw_obj[7] = { 7 * MAP_PIXEL, 11 * MAP_PIXEL, -1, };
	draw_obj[8] = { 11 * MAP_PIXEL, 11 * MAP_PIXEL, -1, };

	return 0;
}