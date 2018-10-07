// ������������������������������������������������������������������
// 18.09.16 v0.0 ������Ʈ ����
// 18.10.07 v1.0 gamestart.c ���� �Ϸ�
// made by youseokhwan(https://github.com/youseokhwan/AcidRainGame)
// ������������������������������������������������������������������

#include "consoleprint.h"
#include "gamestart.h"
#include "ranking.h"

// ���������������� Main Function ����������������
int main(void) {
	system("title Acid Rain (A simple word typing game)"); // �ܼ� Ÿ��Ʋ ����

	// ���������������� Ŀ�� ǥ������ ���� �����ϴ� �ӽ� ����(�׽�Ʈ��) ����������������
	printf("Ŀ���� ǥ���ұ��?\n");
	printf("1. ǥ�þ���(����)\n");
	printf("2. ǥ��(�׽�Ʈ�Ҷ��� ���)\n>> ");
	int cursorUserSelect = 0;
	scanf_s("%d", &cursorUserSelect);

	if (cursorUserSelect == 1) {
		setCursorType(NOCURSOR); // Ŀ�� �������� �ʰ��ϴ� �Լ�
	}

	system("cls");
	// ���������������� Ŀ�� ǥ������ ���� �����ϴ� �ӽ� ����(�׽�Ʈ��) ����������������
	
	//setCursorType(NOCURSOR); // Ŀ�� �������� �ʰ��ϴ� �Լ�

	int numberSelectedByUser = printAndSelectMenu();

	while (true) {
		if (numberSelectedByUser == 1) {
			gameStart(); // gameStart.c
		}
		else if (numberSelectedByUser == 2) {
			ranking(); // ranking.c
		}
		else if (numberSelectedByUser == 3) {
			printf("Good Bye :)\n");
			system("pause>nul");
			exit(0);
		}
		else {
			printf("That's the wrong input!\n");
			printf("Try again, please\n");
			system("pause>nul");
		}

		system("cls");
		numberSelectedByUser = printAndSelectMenu();
	}

	return 0;
}
// ���������������� Main Function ����������������