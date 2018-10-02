#include "consoleprint.h"

void setcursortype(CURSOR_TYPE c) {
	CONSOLE_CURSOR_INFO CurInfo;
	switch (c) {
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = FALSE;
		break;
	case SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = TRUE;
		break;
	case NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
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