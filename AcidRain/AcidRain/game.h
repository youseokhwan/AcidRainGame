#ifndef GAME_H
#define GAME_H

#include "console.h"

#define WORD 50 // ���߿� ���� ��������� �ٽ� ����
#define STAGE 10
#define WORD_IN_STAGE 10
#define BUFFER 10

#define BACKSPACE 8
#define ENTER 13
#define SPACEBAR 32
//#define UP_ARROW 72
//#define DOWN_ARROW 80

void gameStart(); // ���ӽ���

struct _gameStatus {
	int life; // ���� ���(���� 5��)
	int stage;
	int score;
	int correctAnswer; // �ش� ������������ ���� ������ ��
	int printCount; // ���� true�� word.isPrint�� ����
	int updateCount; // update�� Ƚ��
	int startClock; // �ش� �������� ������ �ð�
} gameStatus;

struct word {
	char* word; // �ܾ� ���ڿ�
	bool isPrint; // �ܾ ȭ�鿡 ��Ÿ���� �ִ��� ����(true�� ���, false�� ���X)
	int x, y; // �ش� �ܾ��� x, y ��ǥ - gotoxy()�� ���ڷ� ���
} wordInStage[WORD_IN_STAGE];

#endif