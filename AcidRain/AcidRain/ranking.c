#include "ranking.h"

int recordIndex = 0;

void addRecord() { // 랭킹 추가
	if (recordIndex > RECORD - 1) { // 레코드 10개 꽉차면 Error 출력 및 종료! -> 추후 수정
		printf("Error!!");

		return;
	}

	gotoxy(0, 5); printf("이름 입력: ");
	gotoxy(0, 7); printf("※ 알파벳 대문자 5글자 이내로 입력해주세요! ex) YSH");
	gotoxy(11, 5); scanf_s("%s", record[recordIndex].name, NAME_BUFFER);

	record[recordIndex].rank = recordIndex + 1; // 우선 맨 밑에 넣어두고 나중에 sort
	record[recordIndex].stage = gameStatus.stage;
	record[recordIndex].score = gameStatus.score;

	// 시간 값 설정
	record[recordIndex].presentTime = time(NULL); // 현재 시간 대입(초 단위)
	record[recordIndex].timeStruct = *localtime(&(record[recordIndex].presentTime));

	record[recordIndex].time.year = (record[recordIndex].timeStruct.tm_year + 1900) % 2000;
	record[recordIndex].time.month = record[recordIndex].timeStruct.tm_mon + 1;
	record[recordIndex].time.day = record[recordIndex].timeStruct.tm_mday;
	record[recordIndex].time.hour = record[recordIndex].timeStruct.tm_hour;
	record[recordIndex].time.min = record[recordIndex].timeStruct.tm_min;
	record[recordIndex].time.sec = record[recordIndex].timeStruct.tm_sec;

	recordIndex++;
}

void printRecords() { // 랭킹 출력
	system("cls");

	gotoxy(0, 0); printf("<< Ranking >>");
	gotoxy(0, 2); printf("Rank");
	gotoxy(8, 2); printf("Name");
	gotoxy(18, 2); printf("Stage");
	gotoxy(29, 2); printf("Score");
	gotoxy(40, 2); printf("Time");

	gotoxy(0, 3); printf("===============================================================");

	if (recordIndex < 1) { // 저장된 레코드가 한 개도 없을 경우
		gotoxy(0, 4); printf("※ 저장된 기록이 없습니다!");
	}
	else {
		for (int i = 0; i < recordIndex; i++) {
			gotoxy(1, record[i].rank + 3); printf("%d", record[i].rank);
			gotoxy(8, record[i].rank + 3); printf("%s", record[i].name);
			gotoxy(20, record[i].rank + 3); printf("%d", record[i].stage);
			gotoxy(29, record[i].rank + 3); printf("%d", record[i].score);

			// 시간 출력
			gotoxy(40, record[i].rank + 3);
			printf("%d-%d-%d %d:%d:%d", record[i].time.year, record[i].time.month, record[i].time.day, record[i].time.hour, record[i].time.min, record[i].time.sec);
		}
	}

	system("pause>nul");
}

void rankingFromMenu() { // 랭킹(메뉴에서 진입)
	printRecords();
}

void rankingFromGame() { // 랭킹(게임에서 진입)
	addRecord();
	printRecords();
}