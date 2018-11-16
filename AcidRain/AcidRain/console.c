#include "console.h"

#define CURSOR_HIDE

void consoleSetting() { // ���� �ܼ� ���� 
	system("title Acid Rain"); // �ܼ� Ÿ��Ʋ ����
	system("mode con: cols=64 lines=27");

#ifdef CURSOR_HIDE
	setCursorType(NOCURSOR); // Ŀ�� �����
#endif
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

void gotoxy(int x, int y) { // Ŀ�� Ư�� ��ǥ�� �̵�
	COORD cursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void printBorderLine() { // ��輱 ���
	gotoxy(0, 1); printf("===============================================================\n");
	gotoxy(0, 22); printf("===============================================================\n");
}

void printStatus() { // status�� ���
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

void printPrompt() { // �Է� â ���
	gotoxy(0, 24);  printf("Input >>");
}

void clearStatus() { // status�� �����
	gotoxy(0, 0);
	printf("                                                                ");
}

void clearBoard() { // �ܾ� �����
	for (int i = 2; i <= 21; i++) {
		gotoxy(0, i);
		printf("                                                                ");
	}
}

void clearPrompt() { // �Է�â �����
	gotoxy(0, 24); printf("                                 ");
}