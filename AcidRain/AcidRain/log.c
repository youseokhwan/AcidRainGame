#include "log.h"

/*
	�α� â ����� ���� �Լ�
	������ �ѱ�鼭 ���� ������Ʈ�ϱ� ����
*/
void clearLog() {
	for (int i = 4; i <= 24; i++) {
		gotoxy(0, i); printf("                                                             ");
	}
}

/*
	�α� �߰��ϴ� �Լ�
	fromRank ���� false�� ��� �ð� �� �߰����� ����
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
			���� �ð����� �ʱ�ȭ
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
	�α� ��� ����ϴ� �Լ�
*/
void showLog() {
	system("cls");

	FILE *fp;
	fopen_s(&fp, "dataFile\\game_log.txt", "rt");

	PlaySound(TEXT(SOUND_SELECT), NULL, SND_FILENAME | SND_ASYNC); // select.wav ���

	setColor(YELLOW);
	gotoxy(0, 0); printf("�� LOG");
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
				gotoxy(10, 25); printf("%d������", pageIndex);
				system("pause>nul");

				clearLog();
			}

			gotoxy(0, logIndex + 4 - pageIndex * 20); printf("%d", logIndex + 1);
			gotoxy(5, logIndex + 4 - pageIndex * 20);

			temp = fgetc(fp);
			if (temp == EOF) {
				gotoxy(0, logIndex + 4 - pageIndex * 20); printf("    ");
				gotoxy(10, 25); printf("%d������", pageIndex+1);

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
