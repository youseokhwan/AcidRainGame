#ifndef __GAMESTART_H__
#define __GAMESTART_H__

void gotoxy(int x, int y);

void gameStart(); // ���ӽ��� ������ �� �����ϴ� �Լ�

typedef struct _gameStatus {
	int leftLife; // ���� ���(���� 5��)
	int stage;
	int score;
	int correctInputCount; // �ùٸ��� �Է��� Ƚ��
	int notCorrectInputCount; // �ùٸ����ʰ� �Է��� Ƚ��
};

struct word {
	char* word; // �ܾ�
	int isPrint; // �ܾ ȭ�鿡 ��Ÿ���� �ִ��� ����(true�� ��Ÿ��)
	int printCount; // �ܾ ���� �� ��° �ٿ� ��ġ�ϴ����� ���� �� 
};

#endif