#include <stdio.h>
#include "gamestart.h"
#include "ranking.h"

int printAndSelectMenu();

int main(void) {
	int numberSelectedByUser;

	numberSelectedByUser = printAndSelectMenu();

	while (1) {
		switch (numberSelectedByUser) {
		case 1:
			gameStart();
			break;
		case 2:
			ranking();
			break;
		case 3:
			printf("������ �����մϴ�.\n");
			exit(0);
		default:
			printf("�߸������ϼ̽��ϴ�. �ٽ� �������ּ���.\n");
		}

		break;
	}

	return 0;
}

int printAndSelectMenu() {
	int selectNumber;

	printf(">> Acid Rain\n");
	printf("1. ���ӽ���\n");
	printf("2. ��ŷ\n");
	printf("3. ����\n");
	printf(">> ");
	scanf_s("%d", &selectNumber);

	return selectNumber;
}