#include "ranking.h"

int recordIndex = 0; // record iterator

void addRecord(struct _gameStatus* gameStatus, struct _record* record) { // 랭킹 추가
	if (recordIndex > RECORD) { // 레코드 10개 꽉차면 Error 출력 및 입력과정 생략
		gotoxy(0, 5); printf("레코드가 꽉 차서 더 이상 랭킹등록을 할 수 없습니다.");

		return;
	}

	gotoxy(0, 5); printf("이름 입력:                          ");
	gotoxy(0, 7); printf("※ 알파벳 대문자 5글자 이내로 입력해주세요! ex) YSH");

	gotoxy(11, 5); scanf_s("%s", record[recordIndex].name, NAME_BUFFER);

	addLog("register a ranking(name: ", false);
	addLog(record[recordIndex].name, true);
	addLog(")\n", true);

	record[recordIndex].rank = recordIndex + 1; // 우선 맨 밑에 넣어두고 add한 record와 함께 rank값 다시 초기화
	record[recordIndex].stage = gameStatus->stage;
	record[recordIndex].score = gameStatus->score;

	// 시간 값 설정
	record[recordIndex].presentTime = time(NULL); // 현재 시간 대입(초 단위)
	localtime_s(&record[recordIndex].timeStruct, &record[recordIndex].presentTime);

	record[recordIndex].time.year = (record[recordIndex].timeStruct.tm_year + 1900) % 2000;
	record[recordIndex].time.month = record[recordIndex].timeStruct.tm_mon + 1;
	record[recordIndex].time.day = record[recordIndex].timeStruct.tm_mday;
	record[recordIndex].time.hour = record[recordIndex].timeStruct.tm_hour;
	record[recordIndex].time.min = record[recordIndex].timeStruct.tm_min;
	record[recordIndex].time.sec = record[recordIndex].timeStruct.tm_sec;

	// rank값 초기화(sort)
	for (int i = 0; i <= recordIndex; i++) {
		int rankCount = 1;
		for (int j = 0; j <= recordIndex; j++) {
			if (record[i].score < record[j].score) {
				rankCount++;
			}
		}

		record[i].rank = rankCount;
	}

	recordIndex++;
}

void printRecords(struct _record* record) { // 랭킹 출력
	clearScreen();
	PlaySound(TEXT(SOUND_SELECT), NULL, SND_FILENAME | SND_ASYNC); // select.wav 재생

	setColor(YELLOW);
	gotoxy(0, 0); printf("● RANKING");
	setColor(WHITE);
	gotoxy(0, 2); printf("Rank");
	gotoxy(8, 2); printf("Name");
	gotoxy(18, 2); printf("Stage");
	gotoxy(29, 2); printf("Score");
	gotoxy(46, 2); printf("Time");

	printSingleBorderLine(3); // 경계선 출력

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
			printf("%02d-%02d-%02d %02d:%02d:%02d", record[i].time.year, record[i].time.month, record[i].time.day, record[i].time.hour, record[i].time.min, record[i].time.sec);
		}
	}

	system("pause>nul");
}

void rankingFromMenu(struct _record* record) { // 랭킹(메뉴에서 진입)
	printRecords(record);
}

void rankingFromGame(struct _gameStatus* gameStatus, struct _record* record) { // 랭킹(게임에서 진입)
	addRecord(gameStatus, record);
	printRecords(record);
}
