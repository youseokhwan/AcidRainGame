#ifndef __RANKING_H__
#define __RANKING_H__

#include "consolecontrol.h"

#define THE_NUMBER_OF_RECORDS 10

int recordIndex;

struct _record {
	char name[10]; // �̸�
	int rank; // ����
	int stage; // Ŭ������ ���� ��������
	int score; // ���� ����
	int time; // ��ϵ� �ð�
} record[THE_NUMBER_OF_RECORDS];

void addRecord(); // ��ŷ ���
void printRecords(); // ��ŷ ����Ʈ ���

void enterRankingFromMenu(); // ��ŷ�޴� ����(�޴�����)
void enterRankingFromGamePlay(); // ��ŷ�޴� ����(���ӳ�����)

#endif