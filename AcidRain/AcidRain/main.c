// ������������������������������������������������������������������
// 18.09.16 v0.0 ������Ʈ ����
// 18.10.07 v1.0 gamestart.c ���� �Ϸ�
// made by youseokhwan(https://github.com/youseokhwan/AcidRainGame)
// ������������������������������������������������������������������

#include "consoleprint.h"
#include "gamestart.h"
#include "ranking.h"

// ���������������� Main Function  ����������������
int main(void) {
	system("title Acid Rain (A simple word typing game)"); // �ܼ� Ÿ��Ʋ ����
	setCursorType(NOCURSOR); // Ŀ�� �������� �ʰ��ϴ� �Լ�

	int numberSelectedByUser = printAndSelectMenu();

	while (true) {
		switch (numberSelectedByUser) { // ���߿� Ű���� �Է����� �ٲٱ�?
		case 1:
			gameStart(); // gameStart.c
			break;
		case 2:
			ranking(); // ranking.c
			break;
		case 3:
			printf("������ �����մϴ�.\n");
			system("pause>nul");
			exit(0);
		default:
			printf("�߸������ϼ̽��ϴ�. �ٽ� �������ּ���.\n");
			system("pause>nul");
		}

		system("cls");
		numberSelectedByUser = printAndSelectMenu();
	}

	return 0;
}
// ���������������� Main Function ����������������