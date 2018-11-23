#include "ranking.h"

int recordIndex = 0; // record iterator

void addRecord(struct _gameStatus* gameStatus, struct _record* record) { // ��ŷ �߰�
	if (recordIndex > RECORD) { // ���ڵ� 10�� ������ Error ��� �� �Է°��� ����
		gotoxy(0, 5); printf("���ڵ尡 �� ���� �� �̻� ��ŷ����� �� �� �����ϴ�.");

		return;
	}

	gotoxy(0, 5); printf("�̸� �Է�:                          ");
	gotoxy(0, 7); printf("�� ���ĺ� �빮�� 5���� �̳��� �Է����ּ���! ex) YSH");

	gotoxy(11, 5); scanf_s("%s", record[recordIndex].name, NAME_BUFFER);

	addLog("register a ranking(name: ", false);
	addLog(record[recordIndex].name, true);
	addLog(")\n", true);

	record[recordIndex].rank = recordIndex + 1; // �켱 �� �ؿ� �־�ΰ� add�� record�� �Բ� rank�� �ٽ� �ʱ�ȭ
	record[recordIndex].stage = gameStatus->stage;
	record[recordIndex].score = gameStatus->score;

	// �ð� �� ����
	record[recordIndex].presentTime = time(NULL); // ���� �ð� ����(�� ����)
	localtime_s(&record[recordIndex].timeStruct, &record[recordIndex].presentTime);

	record[recordIndex].time.year = (record[recordIndex].timeStruct.tm_year + 1900) % 2000;
	record[recordIndex].time.month = record[recordIndex].timeStruct.tm_mon + 1;
	record[recordIndex].time.day = record[recordIndex].timeStruct.tm_mday;
	record[recordIndex].time.hour = record[recordIndex].timeStruct.tm_hour;
	record[recordIndex].time.min = record[recordIndex].timeStruct.tm_min;
	record[recordIndex].time.sec = record[recordIndex].timeStruct.tm_sec;

	// rank�� �ʱ�ȭ(sort)
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

void printRecords(struct _record* record) { // ��ŷ ���
	clearScreen();
	PlaySound(TEXT(SOUND_SELECT), NULL, SND_FILENAME | SND_ASYNC); // select.wav ���

	setColor(YELLOW);
	gotoxy(0, 0); printf("�� RANKING");
	setColor(WHITE);
	gotoxy(0, 2); printf("Rank");
	gotoxy(8, 2); printf("Name");
	gotoxy(18, 2); printf("Stage");
	gotoxy(29, 2); printf("Score");
	gotoxy(46, 2); printf("Time");

	printSingleBorderLine(3); // ��輱 ���

	if (recordIndex < 1) { // ����� ���ڵ尡 �� ���� ���� ���
		gotoxy(0, 4); printf("�� ����� ����� �����ϴ�!");
	}
	else {
		for (int i = 0; i < recordIndex; i++) {
			gotoxy(1, record[i].rank + 3); printf("%d", record[i].rank);
			gotoxy(8, record[i].rank + 3); printf("%s", record[i].name);
			gotoxy(20, record[i].rank + 3); printf("%d", record[i].stage);
			gotoxy(29, record[i].rank + 3); printf("%d", record[i].score);

			// �ð� ���
			gotoxy(40, record[i].rank + 3);
			printf("%02d-%02d-%02d %02d:%02d:%02d", record[i].time.year, record[i].time.month, record[i].time.day, record[i].time.hour, record[i].time.min, record[i].time.sec);
		}
	}

	system("pause>nul");
}

void rankingFromMenu(struct _record* record) { // ��ŷ(�޴����� ����)
	printRecords(record);
}

void rankingFromGame(struct _gameStatus* gameStatus, struct _record* record) { // ��ŷ(���ӿ��� ����)
	addRecord(gameStatus, record);
	printRecords(record);
}
