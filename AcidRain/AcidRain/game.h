#ifndef GAME_H
#define GAME_H

#include "console.h"

#define WORD 100
#define STAGE 10
#define INPUT_BUFFER 10
#define WORD_IN_STAGE 10
#define FILE_BUFFER 1000

#define ENTER 13
#define SPACEBAR 32
#define BACKSPACE 8

#define ARROW 224
#define UP_ARROW 72
#define DOWN_ARROW 80
#define LEFT_ARROW 75
#define RIGHT_ARROW 77

void gameStart(struct _record* record, struct _gameStatus* gameStatus);

struct _gameStatus {
	int life;
	int stage;
	int score;
	int correctAnswer;
	int printCount;
	int updateCount;
	int startClock;
	int dropSpeed[STAGE];
};

struct _word {
	char* text;
	bool isPrint;
	int x, y;
};

#endif
