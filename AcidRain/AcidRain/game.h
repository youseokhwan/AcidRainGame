#ifndef GAME_H
#define GAME_H

#include "console.h"

#define WORD 100
#define STAGE 10
#define INPUT_BUFFER 10
#define WORD_IN_STAGE 10
#define FILE_BUFFER 1000

#define ENTER 13
#define SPACEBAR 32
#define BACKSPACE 8

#define ARROW 224
#define UP_ARROW 72
#define DOWN_ARROW 80
#define LEFT_ARROW 75
#define RIGHT_ARROW 77

void gameStart(struct _record* record); // ���ӽ���

struct _gameStatus { // ������ ���������� �Ѱ��ϴ� struct
	int life; // ���� ���(���� 5��)
	int stage; // ��������
	int score; // ���ھ�
	int correctAnswer; // �ش� ������������ ���� ������ ��
	int printCount; // ���� true�� word.isPrint�� ����
	int updateCount; // �ش� ������������ pulse�� Ƚ��(�ܾ� ������Ʈ�� Ƚ��)
	int startClock; // �ش� ���������� ������ �ð�
	int dropSpeed[STAGE]; // �ܾ� �������� �ӵ��� ����
};

struct _word { // �ܾ� struct
	char* text; // �ܾ� ���ڿ�
	bool isPrint; // �ܾ ȭ�鿡 ��Ÿ���� �ִ��� ����(true�� ���, false�� �����)
	int x, y; // �ش� �ܾ��� x, y ��ǥ - gotoxy()�� ���ڷ� ���
};

#endif
