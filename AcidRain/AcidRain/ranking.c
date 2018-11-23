#include "ranking.h"

int recordIndex = 0;

/*
	��ŷ �߰��ϴ� �Լ�
*/
void addRecord(struct _gameStatus* gameStatus, struct _record* record) {
	/*
		��ŷ 10�� �̻� �Է� �Ұ�
		���� �����ؾ� �� �κ�
	*/
	if (recordIndex > RECORD) {
		gotoxy(0, 5); printf("���ڵ尡 �� ���� �� �̻� ��ŷ����� �� �� �����ϴ�.");

		return;
	}

	gotoxy(0, 5); printf("�̸� �Է�:                          ");
	gotoxy(0, 7); printf("�� ���ĺ� �빮�� 5���� �̳��� �Է����ּ���! ex) YSH");

	gotoxy(11, 5); scanf_s("%s", record[recordIndex].name, NAME_BUFFER);

	addLog("register a ranking(name: ", false);
	addLog(record[recordIndex].name, true);
	addLog(")\n", true);

	/*
		rank�� �켱 �� ������ �־�ΰ� �ؿ��� sort ����
	*/
	record[recordIndex].rank = recordIndex + 1;
	record[recordIndex].stage = gameStatus->stage;
	record[recordIndex].score = gameStatus->score;

	/*
		���� �ð����� �ʱ�ȭ
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
		�� record�� rank�� �ʱ�ȭ
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
	��ŷ ����ϴ� �Լ�
*/
void printRecords(struct _record* record) {
	system("cls");
	PlaySound(TEXT(SOUND_SELECT), NULL, SND_FILENAME | SND_ASYNC); // select.wav ���

	setColor(YELLOW);
	gotoxy(0, 0); printf("�� RANKING");
	setColor(WHITE);
	gotoxy(0, 2); printf("Rank");
	gotoxy(8, 2); printf("Name");
	gotoxy(18, 2); printf("Stage");
	gotoxy(29, 2); printf("Score");
	gotoxy(46, 2); printf("Time");

	printSingleBorderLine(3);

	/*
		����� ��ũ�� �� ���� ���� ���
	*/
	if (recordIndex < 1) {
		gotoxy(0, 4); printf("�� ����� ����� �����ϴ�!");
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
	���� ȭ�鿡�� ��ŷ �޴� ����
*/
void rankingFromMenu(struct _record* record) {
	printRecords(record);
}

/*
	���ӿ��� ��ŷ �޴� ����
*/
void rankingFromGame(struct _gameStatus* gameStatus, struct _record* record) {
	addRecord(gameStatus, record);
	printRecords(record);
}
