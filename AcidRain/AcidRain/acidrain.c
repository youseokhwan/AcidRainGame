// ������������������������������������������������������������������
// 18.09.16 ~ 
// made by youseokhwan(https://github.com/youseokhwan/AcidRainGame)
// ������������������������������������������������������������������

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include "acidrain.h"
#include "gamestart.h"
#include "ranking.h"

int main(void) {
	setcursortype(NOCURSOR); // Ŀ�� �������� �ʰ��ϴ� �Լ�
	srand(time(NULL));

	int numberSelectedByUser;

	numberSelectedByUser = printAndSelectMenu();

	while (1) {
		switch (numberSelectedByUser) {
		case 1:
			gameStart(); // gameStart.c
			break;
		case 2:
			ranking(); // ranking.c
			break;
		case 3:
			printf("������ �����մϴ�.\n");
			exit(0);
			// break;
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