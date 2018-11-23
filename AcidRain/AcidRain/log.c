#include "log.h"

/*
	로그 창 지우기 위한 함수
	페이지 넘기면서 내용 업데이트하기 위함
*/
void clearLog() {
	for (int i = 4; i <= 24; i++) {
		gotoxy(0, i); printf("                                                             ");
	}
}

/*
	로그 추가하는 함수
	fromRank 값이 false일 경우 시간 값 추가하지 않음
*/
void addLog(char* newLog, bool fromRank) {
	FILE *fp;
	fopen_s(&fp, "dataFile\\game_log.txt", "at");

	time_t presentTime = time(NULL);
	struct tm timeStruct;
	struct _time time;

	if (fromRank == true) {
		// empty!!
	}
	else {
		/*
			현재 시간으로 초기화
		*/
		localtime_s(&timeStruct, &presentTime);
		time.year = (timeStruct.tm_year + 1900) % 2000;
		time.month = timeStruct.tm_mon + 1;
		time.day = timeStruct.tm_mday;
		time.hour = timeStruct.tm_hour;
		time.min = timeStruct.tm_min;
		time.sec = timeStruct.tm_sec;

		fprintf(fp, "%02d-%02d-%02d %02d:%02d:%02d   ", time.year, time.month, time.day, time.hour, time.min, time.sec);
	}
	fprintf(fp, newLog);

	fclose(fp);
}

/*
	로그 목록 출력하는 함수
*/
void showLog() {
	system("cls");

	FILE *fp;
	fopen_s(&fp, "dataFile\\game_log.txt", "rt");

	PlaySound(TEXT(SOUND_SELECT), NULL, SND_FILENAME | SND_ASYNC); // select.wav 재생

	setColor(YELLOW);
	gotoxy(0, 0); printf("● LOG");
	setColor(WHITE);
	gotoxy(0, 2); printf("No.");
	gotoxy(11, 2); printf("Time");
	gotoxy(25, 2); printf("Content");

	printSingleBorderLine(3);

	int logNumber = 0;
	int logIndex = 0;
	int pageIndex = 0;

	gotoxy(0, logIndex + 4); printf("%d", logIndex + 1);
	gotoxy(5, logIndex + 4);

	char temp = fgetc(fp);
	while (true) {
		if (temp == EOF) {
			break;
		}
		else if (temp == '\n') {
			logIndex++;

			if (logIndex % 20 == 0) {
				pageIndex++;
				gotoxy(10, 25); printf("%d페이지", pageIndex);
				system("pause>nul");

				clearLog();
			}

			gotoxy(0, logIndex + 4 - pageIndex * 20); printf("%d", logIndex + 1);
			gotoxy(5, logIndex + 4 - pageIndex * 20);

			temp = fgetc(fp);
			if (temp == EOF) {
				gotoxy(0, logIndex + 4 - pageIndex * 20); printf("    ");
				gotoxy(10, 25); printf("%d페이지", pageIndex+1);

				break;
			}
		}
		else if (temp == '\0') {
			temp = fgetc(fp);
		}
		else {
			printf("%c", temp);
			temp = fgetc(fp);
		}
	}

	fclose(fp);

	system("pause>nul");
}
