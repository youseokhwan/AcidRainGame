#include "log.h"

//#define ADD_LOG_FOR_TEST

void addLog(char* newLog, bool fromRank) { // 로그저장
	FILE *fp;
	fopen_s(&fp, "dataFile\\game_log.txt", "at");

	time_t presentTime = time(NULL);
	struct tm timeStruct;
	struct _time time;

	if (fromRank == true) {
		// empty!!
	}
	else {
		// 시간 값 설정
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

void showLog() { // 로그보기
	clearScreen();

#ifdef ADD_LOG_FOR_TEST
	addLog("log test\n", false);
#endif

	FILE *fp;
	fopen_s(&fp, "dataFile\\game_log.txt", "rt");

	PlaySound(TEXT(SOUND_SELECT), NULL, SND_FILENAME | SND_ASYNC);

	setColor(YELLOW);
	gotoxy(0, 0); printf("● LOG");
	setColor(WHITE);
	gotoxy(0, 2); printf("No.");
	gotoxy(11, 2); printf("Time");
	gotoxy(25, 2); printf("Content");

	printSingleBorderLine(3);

	int logNumber = 0;
	int logIterator = 0;
	int pageIterator = 0;

	gotoxy(0, logIterator + 4); printf("%d", logIterator + 1);
	gotoxy(5, logIterator + 4);

	char temp = fgetc(fp);
	while (true) {
		if (temp == EOF) {
			break;
		}
		else if (temp == '\n') {
			logIterator++;

			if (logIterator % 20 == 0) {
				pageIterator++;
				gotoxy(10, 25); printf("%d페이지", pageIterator);
				system("pause>nul");

				clearLog();
			}

			gotoxy(0, logIterator + 4 - pageIterator * 20); printf("%d", logIterator + 1);
			gotoxy(5, logIterator + 4 - pageIterator * 20);

			temp = fgetc(fp);
			if (temp == EOF) {
				gotoxy(0, logIterator + 4 - pageIterator * 20); printf("    ");
				gotoxy(10, 25); printf("%d페이지", pageIterator+1);

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
