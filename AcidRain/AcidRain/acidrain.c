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
			printf("게임을 종료합니다.\n");
			exit(0);
		default:
			printf("잘못선택하셨습니다. 다시 선택해주세요.\n");
		}

		break;
	}

	return 0;
}

int printAndSelectMenu() {
	int selectNumber;

	printf(">> Acid Rain\n");
	printf("1. 게임시작\n");
	printf("2. 랭킹\n");
	printf("3. 종료\n");
	printf(">> ");
	scanf_s("%d", &selectNumber);

	return selectNumber;
}