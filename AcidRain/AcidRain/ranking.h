#ifndef RANKING_H
#define RANKING_H

#include "console.h"

#define RECORD 10
#define NAME_BUFFER 10

struct _time {
	int year;
	int month;
	int day;
	int hour;
	int min;
	int sec;
};

struct _record {
	char name[NAME_BUFFER]; // �̸�
	int rank; // ����
	int stage; // ���� ��������
	int score; // ���� ����

	time_t presentTime; // ���� �ð�
	struct tm timeStruct; // �� �ð� �����ϱ� ���� ����ϴ� struct (time.h ����)
	
	struct _time time; // ������ �� �ð� ������ ����
} record[RECORD];

void addRecord(); // ��ŷ ���
void printRecords(); // ��ŷ ���

void rankingFromMenu(); // ��ŷ(�޴����� ����)
void rankingFromGame(); // ��ŷ(���ӿ��� ����)

#endif