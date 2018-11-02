#ifndef __RANKING_H__
#define __RANKING_H__

#include "console.h"

#define THE_NUMBER_OF_USER 10
#define BUFFER_OF_NAME 10
#define BUFFER_OF_TIME 20

void rankingFromMenu();
void rankingFromGame();

struct _user {
	int rank; // 순위
	char name[BUFFER_OF_NAME]; // 이름
	int stage; // 스테이지
	int score; // 점수
	char time[BUFFER_OF_TIME]; // 등록시간
}user[THE_NUMBER_OF_USER];

#endif