#include "ranking.h"

int recordIndex = 0;

void addRecord() { // ��ŷ �߰�
	if (recordIndex > RECORD - 1) { // ���ڵ� 10�� ������ Error ��� �� ����! -> ���� ����
		printf("Error!!");

		return;
	}

	gotoxy(0, 5); printf("�̸� �Է�: ");
	gotoxy(0, 7); printf("�� ���ĺ� �빮�� 5���� �̳��� �Է����ּ���! ex) YSH");
	gotoxy(11, 5); scanf_s("%s", record[recordIndex].name, NAME_BUFFER);

	record[recordIndex].rank = recordIndex + 1; // �켱 �� �ؿ� �־�ΰ� ���߿� sort
	record[recordIndex].stage = gameStatus.stage;
	record[recordIndex].score = gameStatus.score;

	// �ð� �� ����
	record[recordIndex].presentTime = time(NULL); // ���� �ð� ����(�� ����)
	record[recordIndex].timeStruct = *localtime(&(record[recordIndex].presentTime));

	record[recordIndex].time.year = (record[recordIndex].timeStruct.tm_year + 1900) % 2000;
	record[recordIndex].time.month = record[recordIndex].timeStruct.tm_mon + 1;
	record[recordIndex].time.day = record[recordIndex].timeStruct.tm_mday;
	record[recordIndex].time.hour = record[recordIndex].timeStruct.tm_hour;
	record[recordIndex].time.min = record[recordIndex].timeStruct.tm_min;
	record[recordIndex].time.sec = record[recordIndex].timeStruct.tm_sec;

	recordIndex++;
}

void printRecords() { // ��ŷ ���
	system("cls");

	gotoxy(0, 0); printf("<< Ranking >>");
	gotoxy(0, 2); printf("Rank");
	gotoxy(8, 2); printf("Name");
	gotoxy(18, 2); printf("Stage");
	gotoxy(29, 2); printf("Score");
	gotoxy(40, 2); printf("Time");

	gotoxy(0, 3); printf("===============================================================");

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
			printf("%d-%d-%d %d:%d:%d", record[i].time.year, record[i].time.month, record[i].time.day, record[i].time.hour, record[i].time.min, record[i].time.sec);
		}
	}

	system("pause>nul");
}

void rankingFromMenu() { // ��ŷ(�޴����� ����)
	printRecords();
}

void rankingFromGame() { // ��ŷ(���ӿ��� ����)
	addRecord();
	printRecords();
}