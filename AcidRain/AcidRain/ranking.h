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
	char name[NAME_BUFFER];
	int rank;
	int stage;
	int score;

	time_t presentTime;
	struct tm timeStruct;
	struct _time time;
} record[RECORD];

void addRecord(struct _gameStatus* gameStatus, struct _record* record);
void printRecords(struct _record* record);

void rankingFromMenu(struct _record* record);
void rankingFromGame(struct _gameStatus* gameStatus, struct _record* record);

#endif
