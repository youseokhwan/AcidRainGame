#include <stdio.h>
#include "gamestart.h"
#include "ranking.h"

int printMenu();

int main(void) {
	int numberSelectedByUser;

	numberSelectedByUser = printMenu();

	while (1) {
		switch (numberSelectedByUser) {
		case 1:
			printf("1����\n");
			break;
		case 2:
			printf("2����\n");
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

int printMenu() {
	int selectNumber;

	printf(">> Acid Rain\n");
	printf("1. ���ӽ���\n");
	printf("2. ��ŷ\n");
	printf("3. ����\n");
	printf(">> ");
	scanf_s("%d", &selectNumber);

	return selectNumber;
}