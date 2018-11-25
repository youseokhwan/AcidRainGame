#include "ranking.h"

int recordIndex = 0;

/*
	알파벳 목록 출력하는 함수
*/
void printAlphabetTable() {
	for (int i = 0; i < 4; i++) {
		gotoxy(0, 7 + i); printf("                                                 ");
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 7; j++) {
			gotoxy(2 + (j * 4), 7 + i); printf("%c", 'A' + (i * 7) + j);
		}
	}

	gotoxy(22, 10); printf("_              ");
	gotoxy(26, 10); printf("완료");
}

/*
	알파벳 목록에서 화살표 출력하는 함수
*/
void printAlphabetArrow(int x, int y) {
	setColor(YELLOW);
	gotoxy(0 + x * 4, 7 + y); printf("→");
	setColor(WHITE);
}

/*
	이름 등록하는 함수
*/
void registerName(struct _record* record) {
	char name[NAME_BUFFER] = "";
	int nameIndex = 0;
	int x = 0, y = 0;

	gotoxy(0, 5); printf("이름 입력:                          ");
	printAlphabetTable();
	printAlphabetArrow(x, y);

	while (true) {
		int keyboardInput = _getch();

		if (keyboardInput == ARROW) {
			keyboardInput = _getch();

			if (keyboardInput == UP_ARROW) {
				if (y == 0) {
					// empty!!
				}
				else {
					y--;
					printAlphabetTable();
					printAlphabetArrow(x, y);
				}
			}
			else if (keyboardInput == DOWN_ARROW) {
				if (y == 3) {
					// empty!!
				}
				else {
					y++;
					printAlphabetTable();
					printAlphabetArrow(x, y);
				}
			}
			else if (keyboardInput == LEFT_ARROW) {
				if (x == 0) {
					// empty!!
				}
				else {
					x--;
					printAlphabetTable();
					printAlphabetArrow(x, y);
				}
			}
			else if (keyboardInput == RIGHT_ARROW) {
				if (x == 6) {
					// empty!!
				}
				else {
					x++;
					printAlphabetTable();
					printAlphabetArrow(x, y);
				}
			}
			else {
				// empty!!
			}
		}
		else if (keyboardInput == ENTER) {
#ifndef ISSUE
			_getch(); // 입력 스트림 비우기
#endif

			if (x == 6 && y == 3 && nameIndex <= 3) {
				strcpy_s(record[recordIndex].name, NAME_BUFFER, name);
				
				break;
			}
			else if (nameIndex >= 3) {
				gotoxy(0, 12); printf("더 이상 입력할 수 없습니다. \"완료\"를 눌러주세요.");
			}
			else {
				if (x == 5 && y == 3) {
					name[nameIndex] = '_';
				}
				else {
					name[nameIndex] = 'A' + (x + y * 7);
				}
				gotoxy(11 + nameIndex, 5);
				printf("%c", name[nameIndex]);
				nameIndex++;
			}
		}
		else {
#ifndef ISSUE
			_getch(); // 입력 스트림 비우기
#endif
		}
	}
}

/*
	랭킹 추가하는 함수
*/
void addRecord(struct _gameStatus* gameStatus, struct _record* record) {
	/*
		랭킹 10개 이상 입력 불가
		추후 수정해야 할 부분
	*/
	if (recordIndex > RECORD) {
		gotoxy(0, 5); printf("레코드가 꽉 차서 더 이상 랭킹등록을 할 수 없습니다.");

		return;
	}

	//gotoxy(0, 5); printf("이름 입력:                          ");
	//gotoxy(0, 7); printf("※ 알파벳 대문자 5글자 이내로 입력해주세요! ex) YSH");

	//gotoxy(11, 5); scanf_s("%s", record[recordIndex].name, NAME_BUFFER);

	registerName(record);

	addLog("register a ranking(name: ", false);
	addLog(record[recordIndex].name, true);
	addLog(")\n", true);

	/*
		rank값 우선 맨 밑으로 넣어두고 밑에서 sort 진행
	*/
	record[recordIndex].rank = recordIndex + 1;
	record[recordIndex].stage = gameStatus->stage;
	record[recordIndex].score = gameStatus->score;

	/*
		현재 시간으로 초기화
	*/
	record[recordIndex].presentTime = time(NULL);
	localtime_s(&record[recordIndex].timeStruct, &record[recordIndex].presentTime);

	record[recordIndex].time.year = (record[recordIndex].timeStruct.tm_year + 1900) % 2000;
	record[recordIndex].time.month = record[recordIndex].timeStruct.tm_mon + 1;
	record[recordIndex].time.day = record[recordIndex].timeStruct.tm_mday;
	record[recordIndex].time.hour = record[recordIndex].timeStruct.tm_hour;
	record[recordIndex].time.min = record[recordIndex].timeStruct.tm_min;
	record[recordIndex].time.sec = record[recordIndex].timeStruct.tm_sec;

	/*
		각 record의 rank값 초기화
	*/
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

/*
	랭킹 출력하는 함수
*/
void printRecords(struct _record* record) {
	system("cls");
	PlaySound(TEXT(SOUND_SELECT), NULL, SND_FILENAME | SND_ASYNC); // select.wav 재생

	setColor(YELLOW);
	gotoxy(0, 0); printf("● RANKING");
	setColor(WHITE);
	gotoxy(0, 2); printf("Rank");
	gotoxy(8, 2); printf("Name");
	gotoxy(18, 2); printf("Stage");
	gotoxy(29, 2); printf("Score");
	gotoxy(46, 2); printf("Time");

	printSingleBorderLine(3);

	/*
		저장된 랭크가 한 개도 없을 경우
	*/
	if (recordIndex < 1) {
		gotoxy(0, 4); printf("※ 저장된 기록이 없습니다!");
	}
	else {
		for (int i = 0; i < recordIndex; i++) {
			gotoxy(1, record[i].rank + 3); printf("%d", record[i].rank);
			gotoxy(8, record[i].rank + 3); printf("%s", record[i].name);
			gotoxy(20, record[i].rank + 3); printf("%d", record[i].stage);
			gotoxy(29, record[i].rank + 3); printf("%d", record[i].score);

			gotoxy(40, record[i].rank + 3);
			printf("%02d-%02d-%02d %02d:%02d:%02d", record[i].time.year, record[i].time.month, record[i].time.day, record[i].time.hour, record[i].time.min, record[i].time.sec);
		}
	}

	system("pause>nul");
}

/*
	메인 화면에서 랭킹 메뉴 진입
*/
void rankingFromMenu(struct _record* record) {
	printRecords(record);
}

/*
	게임에서 랭킹 메뉴 진입
*/
void rankingFromGame(struct _gameStatus* gameStatus, struct _record* record) {
	addRecord(gameStatus, record);
	printRecords(record);
}
