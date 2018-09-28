#ifndef __GAMESTART_H__
#define __GAMESTART_H__

#include <pthread.h>

void gotoxy(int x, int y); // �ֿܼ��� Ŀ�� �̵���Ű�� �Լ�

void gameStart(); // "1. ���ӽ���" ������ �� �����ϴ� �Լ�

struct _gameStatus {
	int leftLife; // ���� ���(���� 5��)
	int stage;
	int score;
	int correctInputCount; // ���� �Է��� Ƚ��
};

struct word {
	char* word; // �ܾ�
	int isPrint; // �ܾ ȭ�鿡 ��Ÿ���� �ִ��� ����(true�� ���, false�� ���X)
	int printCount; // �ܾ ���� �� ��° �ٿ� ��ġ�ϴ����� ���� ��
};

// ���������������� ������ ���� ���� ����������������
void* topThreadFunc(void* arg); // topThread���� ���� �Լ�
void* bottomThreadFunc(void* arg); // bottomThread���� ���� �Լ�

pthread_t topThread, bottomThread; // ������ ����
int intTemp; // pthread_join()�� ���� ����(���� ��� ����)
void* voidPointerTemp;
// ���������������� ������ ���� ���� ����������������


#endif