#ifndef __RANKING_H__
#define __RANKING_H__

#include "consolecontrol.h"

#define THE_NUMBER_OF_RECORDS 10

int recordIndex;

struct _record {
	char name[10]; // 이름
	int rank; // 순위
	int stage; // 클리어한 최종 스테이지
	int score; // 최종 점수
	int time; // 등록된 시간
} record[THE_NUMBER_OF_RECORDS];

void addRecord(); // 랭킹 등록
void printRecords(); // 랭킹 리스트 출력

void enterRankingFromMenu(); // 랭킹메뉴 진입(메뉴에서)
void enterRankingFromGamePlay(); // 랭킹메뉴 진입(게임끝나고)

#endif