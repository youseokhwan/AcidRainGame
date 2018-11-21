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

void gameStart(struct _record* record); // 게임시작

struct _gameStatus { // 게임을 전반적으로 총괄하는 struct
	int life; // 남은 목숨(최초 5개)
	int stage; // 스테이지
	int score; // 스코어
	int correctAnswer; // 해당 스테이지에서 맞춘 정답의 수
	int printCount; // 현재 true인 word.isPrint의 개수
	int updateCount; // 해당 스테이지에서 pulse된 횟수(단어 업데이트된 횟수)
	int startClock; // 해당 스테이지를 시작한 시간
	int dropSpeed[STAGE]; // 단어 떨어지는 속도값 저장
};

struct _word { // 단어 struct
	char* text; // 단어 문자열
	bool isPrint; // 단어가 화면에 나타나고 있는지 여부(true가 출력, false가 비출력)
	int x, y; // 해당 단어의 x, y 좌표 - gotoxy()의 인자로 사용
};

#endif
