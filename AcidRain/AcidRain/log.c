#include "log.h"

//#define LOG_TEST

void addLog(char* newLog, bool fromRank) { // 로그저장
	FILE *fp;
	fp = fopen("dataFile\\game_log.txt", "at");

	time_t presentTime = time(NULL);
	struct tm timeStruct;
	struct _time time;

	if (fromRank == true) {
		// empty!!
	}
	else {
		// 시간 값 설정
		timeStruct = *localtime(&presentTime);
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
	system("cls");

#ifdef LOG_TEST
	addLog("log test\n", false);
#endif

	FILE *fp;
	fp = fopen("dataFile\\game_log.txt", "rt");

	PlaySound(TEXT(SOUND_SELECT), NULL, SND_FILENAME | SND_ASYNC);

	setColor(YELLOW);
	gotoxy(0, 0); printf("● LOG");
	setColor(WHITE);
	gotoxy(0, 2); printf("No.");
	gotoxy(11, 2); printf("Time");
	gotoxy(25, 2); printf("Content");

	printSingleBorderLine();

	int logNumber = 0;
	int logIterator = 1;

	gotoxy(0, logIterator + 3); printf("%2d", logIterator);
	gotoxy(5, logIterator + 3);

	char temp = fgetc(fp);
	while (true) {
		if (temp == EOF) {
			break;
		}
		else if (temp == '\n') {
			logIterator++;
			gotoxy(0, logIterator + 3); printf("%2d", logIterator);
			gotoxy(5, logIterator + 3);

			temp = fgetc(fp);
			if (temp == EOF) {
				gotoxy(0, logIterator + 3); printf("    ");

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
