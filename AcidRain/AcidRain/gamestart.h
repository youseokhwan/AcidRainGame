#ifndef __GAMESTART_H__
#define __GAMESTART_H__

void gameStart(); // ���ӽ��� ������ �� �����ϴ� �Լ�

struct gameStatus {
	int leftLife; // ���� ���(���� 5��)
	int stage;
	int score;
	int correctInputCount; // �ùٸ��� �Է��� Ƚ��
	int notCorrectInputCount; // �ùٸ����ʰ� �Է��� Ƚ��
};

struct word {
	char* wordName;
	int currentLocation; // 0���� �����ؼ� 10�Ǹ� ������ �����ϴ� �˰���
};

#endif