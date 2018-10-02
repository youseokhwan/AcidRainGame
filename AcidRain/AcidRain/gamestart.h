#ifndef __GAMESTART_H__
#define __GAMESTART_H__

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <pthread.h>

#define NUMBER_OF_WORD_LIST 50
#define MAX_STAGE 10
#define NUMBER_OF_WORD_IN_CURRENT_STAGE 10

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
	int x, y; // �ش� �ܾ��� x, y ��ǥ - gotoxy()�� ���ڷ� ���
};

// ���������������� ������ ���� ���� ����������������
void* topThreadFunc(void* arg); // topThread���� ���� �Լ�
void* bottomThreadFunc(void* arg); // bottomThread���� ���� �Լ�

pthread_t topThread, bottomThread; // ������ ����
int intTemp; // pthread_join()�� ���� ����(���� ��� ����)
// ���������������� ������ ���� ���� ����������������

#endif