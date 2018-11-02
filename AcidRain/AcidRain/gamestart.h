#ifndef __GAMESTART_H__
#define __GAMESTART_H__

#include "console.h"

#define THE_NUMBER_OF_WORDS 50
#define MAX_STAGE 10
#define THE_NUMBER_OF_WORDS_IN_STAGE 10

void gameStart();

struct _gameStatus {
	int life; // 남은 목숨(최초 5개)
	int stage;
	int score;
	int correctAnswerCount; // 해당 스테이지에서 맞춘 정답의 수
	int printCount; // 현재 true인 word.isPrint의 개수
	int updateCount; // 현재 스테이지에서 pulse된 횟수
} gameStatus;

struct word {
	char* word; // 단어
	bool isPrint; // 단어가 화면에 나타나고 있는지 여부(true가 출력, false가 출력X)
	int x, y; // 해당 단어의 x, y 좌표 - gotoxy()의 인자로 사용
} wordInStage[THE_NUMBER_OF_WORDS_IN_STAGE];

#endif