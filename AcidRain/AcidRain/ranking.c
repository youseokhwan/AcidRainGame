#include "ranking.h"

recordIndex = 0;

void addRecord() {
	if (recordIndex > THE_NUMBER_OF_RECORDS - 1) {
		printf("Error!!"); // 10개 리코드 꽉 차면 추가 못하도록 함

		return;
	}

	gotoxy(0, 5); printf("Enter a name: ");
	scanf_s("%s", record[recordIndex].name, 10);
	fflush(stdin);

	record[recordIndex].rank = recordIndex + 1;
	record[recordIndex].stage = gameStatus.stage - 1;
	record[recordIndex].score = gameStatus.score;
	record[recordIndex].time = 0; // 나중에 수정

	recordIndex++;
}

void printRecords() {
	system("cls");

	gotoxy(0, 0); printf("<< Ranking >>");
	gotoxy(0, 2); printf("Rank");
	gotoxy(9, 2); printf("Name");
	gotoxy(30, 2); printf("Stage");
	gotoxy(41, 2); printf("Score");
	gotoxy(52, 2); printf("Time");

	gotoxy(0, 3); printf("===============================================================");

	for (int i = 0; i < THE_NUMBER_OF_RECORDS; i++) {
		gotoxy(0, record[i].rank + 4); printf("%d", record[i].rank);
		gotoxy(9, record[i].rank + 4); printf("%s", record[i].name);
		gotoxy(30, record[i].rank + 4); printf("%d", record[i].stage);
		gotoxy(41, record[i].rank + 4); printf("%d", record[i].score);
		gotoxy(52, record[i].rank + 4); printf("%d", record[i].time);
	}

	system("pause>nul");

	system("cls");
	selectMenu();
}

void enterRankingFromMenu() {
	printRecords();
}

void enterRankingFromGamePlay() {
	addRecord();
	printRecords();
}