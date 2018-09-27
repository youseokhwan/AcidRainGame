// ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
// 18.09.16 ~ 
// made by youseokhwan(https://github.com/youseokhwan/AcidRainGame)
// ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include "acidrain.h"
#include "gamestart.h"
#include "ranking.h"

int main(void) {
	setcursortype(NOCURSOR); // 커서 깜빡이지 않게하는 함수
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
			printf("게임을 종료합니다.\n");
			exit(0);
			// break;
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