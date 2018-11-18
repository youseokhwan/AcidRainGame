#ifndef RANKING_H
#define RANKING_H

#include "console.h"

#define RECORD 10
#define NAME_BUFFER 10

struct _time {
	int year;
	int month;
	int day;
	int hour;
	int min;
	int sec;
};

struct _record {
	char name[NAME_BUFFER]; // 이름
	int rank; // 순위
	int stage; // 최종 스테이지
	int score; // 최종 점수

	time_t presentTime; // 현재 시간
	struct tm timeStruct; // 각 시간 가공하기 위해 사용하는 struct (time.h 참조)
	struct _time time; // 가공된 각 시간 값들을 저장
} record[RECORD];

void addRecord(struct _gameStatus* gameStatus, struct _record* record); // 랭킹 등록
void printRecords(struct _record* record); // 랭킹 출력

void rankingFromMenu(struct _record* record); // 랭킹(메뉴에서 진입)
void rankingFromGame(struct _gameStatus* gameStatus, struct _record* record); // 랭킹(게임에서 진입)

#endif