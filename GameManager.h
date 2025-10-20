#pragma once

#pragma once

enum GameStatus {
	WAITING,
	RUNNING,
	ENDING
};

struct DrawObject {
	int x;
	int y;
	int type; //〇：0、×：1、何もない：-1
	int alive;
};

int initGame();

//ゲームの情報
extern GameStatus status;
extern int timer;

extern bool playerType; //0：〇、1：×
extern int result;

//マップ
const int MAP_PIXEL = 40;
const int MAP_WIDTH = 16;
const int MAP_HEIGHT = 16;
extern int MAP[MAP_HEIGHT][MAP_WIDTH];

//描画
extern struct DrawObject draw_obj[9];
