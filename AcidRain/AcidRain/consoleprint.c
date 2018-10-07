#include "consoleprint.h"

void gotoxy(int x, int y) { // Ŀ�� Ư�� ��ǥ�� �̵�
	COORD cursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void setCursorType(CURSOR_TYPE c) { // Ŀ�� �������� �ʰ� ����
	CONSOLE_CURSOR_INFO curInfo;
	switch (c) {
	case NOCURSOR:
		curInfo.dwSize = 1;
		curInfo.bVisible = FALSE;
		break;
	case SOLIDCURSOR:
		curInfo.dwSize = 100;
		curInfo.bVisible = TRUE;
		break;
	case NORMALCURSOR:
		curInfo.dwSize = 20;
		curInfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

int printAndSelectMenu() { // ���� �޴� ��� �� �����Է�
	int selectNumber;

	printf(">> Acid Rain\n");
	printf("1. ���ӽ���\n");
	printf("2. ��ŷ\n");
	printf("3. ����\n");
	printf(">> ");
	scanf_s("%d", &selectNumber);

	return selectNumber;
}

void printBorderLine() { // ��輱 ���
	gotoxy(0, 1); printf("===============================================================\n");
	gotoxy(0, 22); printf("===============================================================\n");
}

void clearBoard() { // ȭ�� �����
	gotoxy(0, 0);
	printf("                                                                ");

	for (int i = 2; i <= 21; i++) {
		gotoxy(0, i);
		printf("                                                                ");
	}
}

void printStatus() { // gameStatus( ) ���� ���
	gotoxy(0, 0); printf("Stage: %d", gameStatus.stage);
	gotoxy(25, 0);
	if (gameStatus.life == 1) {
		printf("Life: %d", gameStatus.life);
	}
	else {
		printf("Lifes: %d", gameStatus.life);
	}
	gotoxy(50, 0); printf("Score: %d", gameStatus.score);
}

void printPrompt() {
	gotoxy(0, 24);  printf("Input >>");
}