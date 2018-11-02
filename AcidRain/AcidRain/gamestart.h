#ifndef __GAMESTART_H__
#define __GAMESTART_H__

#include "console.h"

#define THE_NUMBER_OF_WORDS 50
#define MAX_STAGE 10
#define THE_NUMBER_OF_WORDS_IN_STAGE 10

void gameStart();

struct _gameStatus {
	int life; // ���� ���(���� 5��)
	int stage;
	int score;
	int correctAnswerCount; // �ش� ������������ ���� ������ ��
	int printCount; // ���� true�� word.isPrint�� ����
	int updateCount; // ���� ������������ pulse�� Ƚ��
} gameStatus;

struct word {
	char* word; // �ܾ�
	bool isPrint; // �ܾ ȭ�鿡 ��Ÿ���� �ִ��� ����(true�� ���, false�� ���X)
	int x, y; // �ش� �ܾ��� x, y ��ǥ - gotoxy()�� ���ڷ� ���
} wordInStage[THE_NUMBER_OF_WORDS_IN_STAGE];

#endif