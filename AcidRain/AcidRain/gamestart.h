#ifndef __GAMESTART_H__
#define __GAMESTART_H__

#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <pthread.h>
#include "consoleprint.h"

#define THE_NUMBER_OF_WORDS 50
#define MAX_STAGE 10
#define THE_NUMBER_OF_WORDS_IN_STAGE 10

#define BACKSPACE_KEY 8
#define ENTER_KEY 13
#define SPACEBAR_KEY 32

void gameStart(); // "1. 게임시작" 눌렀을 때 진입하는 함수

struct _gameStatus {
	int life; // 남은 목숨(최초 5개)
	int stage;
	int score;
	int correctAnswerCount; // 현재 스테이지에서 정답 입력한 횟수
	int pulseCount; // 단어 내려가는 작업이 진행된 횟수
	int isPrintCount; // 단어 모두 지워졌을 때를 나타내기 위한 변수(입력해서 사라졌거나, 바닥에 도달해서 사라졌거나)
} gameStatus;

struct word {
	char* word; // 단어
	bool isPrint; // 단어가 화면에 나타나고 있는지 여부(true가 출력, false가 출력X)
	int x, y; // 해당 단어의 x, y 좌표 - gotoxy()의 인자로 사용
} wordInCurrentStage[THE_NUMBER_OF_WORDS_IN_STAGE];

// ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ 쓰레드 관련 선언 ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
pthread_t topThread, bottomThread; // 쓰레드 선언

void* topThreadFunc(void* arg); // topThread에서 사용될 함수
void* bottomThreadFunc(void* arg); // bottomThread에서 사용될 함수
// ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ 쓰레드 관련 선언 ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲

#endif