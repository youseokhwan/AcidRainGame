#ifndef __GAMESTART_H__
#define __GAMESTART_H__

#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <pthread.h>
#include "consoleprint.h"

#define THE_NUMBER_OF_WORDS 50
#define MAX_STAGE 10
#define THE_NUMBER_OF_WORDS_IN_STAGE 10

#define BACKSPACE_KEY 8
#define ENTER_KEY 13
#define SPACEBAR_KEY 32

void gameStart(); // "1. ���ӽ���" ������ �� �����ϴ� �Լ�

struct _gameStatus {
	int life; // ���� ���(���� 5��)
	int stage;
	int score;
	int correctAnswerCount; // ���� ������������ ���� �Է��� Ƚ��
	int pulseCount; // �ܾ� �������� �۾��� ����� Ƚ��
	int isPrintCount; // �ܾ� ��� �������� ���� ��Ÿ���� ���� ����(�Է��ؼ� ������ų�, �ٴڿ� �����ؼ� ������ų�)
} gameStatus;

struct word {
	char* word; // �ܾ�
	bool isPrint; // �ܾ ȭ�鿡 ��Ÿ���� �ִ��� ����(true�� ���, false�� ���X)
	int x, y; // �ش� �ܾ��� x, y ��ǥ - gotoxy()�� ���ڷ� ���
} wordInCurrentStage[THE_NUMBER_OF_WORDS_IN_STAGE];

// ���������������� ������ ���� ���� ����������������
pthread_t topThread, bottomThread; // ������ ����

void* topThreadFunc(void* arg); // topThread���� ���� �Լ�
void* bottomThreadFunc(void* arg); // bottomThread���� ���� �Լ�
// ���������������� ������ ���� ���� ����������������

#endif