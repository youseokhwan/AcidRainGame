#include "consolecontrol.h"

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
	int userInput = 0;

	printf("<< Acid Rain >>\n");
	printf("1. Start\n");
	printf("2. Ranking\n");
	printf("3. Exit\n");
	printf(">> ");
	scanf_s("%d", &userInput);

	return userInput;
}

//void selectMenu() {
//	int menuPrompt = 1;
//	int x = 1, y = 1;
//	int input;
//
//	while (true) {
//		gotoxy(x, y); printf(">>");
//		gotoxy(0, 0); printf("<< Acid Rain >>");
//		gotoxy(5, 1); printf("1. Start");
//		gotoxy(5, 2); printf("2. Ranking");
//		gotoxy(5, 3); printf("3. Exit");
//
//		while (true) {
//			input = _getch();
//			if (input == ENTER_KEY) {
//				switch (menuPrompt) {
//				case 1:
//					gameStart();
//					break;
//				case 2:
//					ranking();
//					break;
//				case 3:
//					gotoxy(5, 6); printf("Good Bye !!\n");
//					exit(0);
//				}
//			}
//			else if (input == 224) {
//				input = _getch();
//				if (input == UP_KEY) {
//					gotoxy(1, 1); printf("  ");
//					gotoxy(1, 2); printf("  ");
//					gotoxy(1, 3); printf("  ");
//
//					if (menuPrompt == 1) {
//						gotoxy(x, y); printf(">>");
//					}
//					else {
//						gotoxy(x, --y); printf(">>");
//						menuPrompt--;
//					}
//				}
//				else if (input == DOWN_KEY) {
//					gotoxy(1, 1); printf("  ");
//					gotoxy(1, 2); printf("  ");
//					gotoxy(1, 3); printf("  ");
//
//					if (menuPrompt == 3) {
//						gotoxy(x, y); printf(">>");
//					}
//					else {
//						gotoxy(x, ++y); printf(">>");
//						menuPrompt++;
//					}
//				}
//			}
//		}
//	}
//}

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