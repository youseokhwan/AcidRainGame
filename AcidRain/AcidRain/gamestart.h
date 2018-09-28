#ifndef __GAMESTART_H__
#define __GAMESTART_H__

#include <pthread.h>

void gotoxy(int x, int y); // 콘솔에서 커서 이동시키는 함수

void gameStart(); // "1. 게임시작" 눌렀을 때 진입하는 함수

struct _gameStatus {
	int leftLife; // 남은 목숨(최초 5개)
	int stage;
	int score;
	int correctInputCount; // 정답 입력한 횟수
};

struct word {
	char* word; // 단어
	int isPrint; // 단어가 화면에 나타나고 있는지 여부(true가 출력, false가 출력X)
	int printCount; // 단어가 현재 몇 번째 줄에 위치하는지에 대한 값
};

// ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ 쓰레드 관련 선언 ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
void* topThreadFunc(void* arg); // topThread에서 사용될 함수
void* bottomThreadFunc(void* arg); // bottomThread에서 사용될 함수

pthread_t topThread, bottomThread; // 쓰레드 선언
int intTemp; // pthread_join()에 넣을 인자(딱히 사용 안함)
void* voidPointerTemp;
// ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ 쓰레드 관련 선언 ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲


#endif