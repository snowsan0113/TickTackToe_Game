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
	int type; //�Z�F0�A�~�F1�A�����Ȃ��F-1
	int alive;
};

int initGame();

//�Q�[���̏��
extern GameStatus status;
extern int timer;

extern bool playerType; //0�F�Z�A1�F�~
extern int result;

//�}�b�v
const int MAP_PIXEL = 40;
const int MAP_WIDTH = 16;
const int MAP_HEIGHT = 16;
extern int MAP[MAP_HEIGHT][MAP_WIDTH];

//�`��
extern struct DrawObject draw_obj[9];
