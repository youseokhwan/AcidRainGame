#ifndef GAME_H
#define GAME_H

#include "console.h"

#define WORD 50 // 나중에 파일 입출력으로 다시 구성
#define STAGE 10
#define WORD_IN_STAGE 10
#define BUFFER 10

#define BACKSPACE 8
#define ENTER 13
#define SPACEBAR 32
//#define UP_ARROW 72
//#define DOWN_ARROW 80

void gameStart(); // 게임시작

struct _gameStatus {
	int life; // 남은 목숨(최초 5개)
	int stage;
	int score;
	int correctAnswer; // 해당 스테이지에서 맞춘 정답의 수
	int printCount; // 현재 true인 word.isPrint의 개수
	int updateCount; // update된 횟수
	int startClock; // 해당 스테이지 시작한 시간
} gameStatus;

struct word {
	char* word; // 단어 문자열
	bool isPrint; // 단어가 화면에 나타나고 있는지 여부(true가 출력, false가 출력X)
	int x, y; // 해당 단어의 x, y 좌표 - gotoxy()의 인자로 사용
} wordInStage[WORD_IN_STAGE];

#endif