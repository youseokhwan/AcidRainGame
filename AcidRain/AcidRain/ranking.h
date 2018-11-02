#ifndef __RANKING_H__
#define __RANKING_H__

#include "console.h"

#define THE_NUMBER_OF_USER 10
#define BUFFER_OF_NAME 10
#define BUFFER_OF_TIME 20

void rankingFromMenu();
void rankingFromGame();

struct _user {
	int rank; // ����
	char name[BUFFER_OF_NAME]; // �̸�
	int stage; // ��������
	int score; // ����
	char time[BUFFER_OF_TIME]; // ��Ͻð�
}user[THE_NUMBER_OF_USER];

#endif