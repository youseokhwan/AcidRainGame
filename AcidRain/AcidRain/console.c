#include "console.h"

#define HIDE_CURSOR

struct _record* consoleSetting() { // ���� �ܼ� ����
	system("title Acid Rain"); // �ܼ� Ÿ��Ʋ ����
	system("mode con: cols=64 lines=27"); // �ܼ� ������ ����

#ifdef HIDE_CURSOR
	setCursorType(NOCURSOR); // Ŀ�� �����
#endif

	// _record ���� �Ҵ�
	struct _record* rcPtr = malloc(sizeof(struct _record)*RECORD);
	struct _record rc[RECORD];
	*rcPtr = rc[RECORD];

	return rcPtr;
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

void printMenu(int* menuIndex) {
	// ���� ���

	// �޴� ��� ���

	// ȭ��ǥ ���
}

int mainMenu(int* menuIndex) {
	printMenu(menuIndex);

	while (true) {
		while (_kbhit()) {
			int userInput = _getch();

			if (userInput == ARROW) {
				userInput = _getch();

				if (userInput == UP_ARROW) {
					// *menuIndex �� ����
					printMenu(menuIndex);
				}
				else if (userInput == DOWN_ARROW) {
					// *menuIndex �� ����
					printMenu(menuIndex);
				}
			}
			//else if (userInput == ? ? ) {
			//	// h �Է��ϸ� ���򸻷� �Ѿ��
			//}
			//else if (userInput == ? ? ) {
			//	// s�Է��ϸ� �������� �Ѿ��
			//}
			//else if (userInput == ENTER) {
			//	// ����ġ�� ���� �� index�� ��ȯ�ع�����
			//
			//  // return *menuIndex;
			//}
		}
	}

	return 0; // �ӽ�
}

void printHelp() {
	system("cls");

	gotoxy(0, 0); printf("���� ���!");
	system("pause>nul");
}

void setting() {
	system("cls");

	gotoxy(0, 0); printf("setting() ����");
	system("pause>nul");
}

void gotoxy(int x, int y) { // Ŀ�� Ư�� ��ǥ�� �̵�
	COORD cursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void printSingleBorderLine() { // rank, log ��� �� ��¥�� ��輱 ���
	gotoxy(0, 3); printf("===============================================================");
}

void printDoubleBorderLine() { // gameBoard���� �� ��¥�� ��輱 ���
	gotoxy(0, 1); printf("===============================================================\n");
	gotoxy(0, 22); printf("===============================================================\n");
}

void printStatus(struct _gameStatus* gameStatus) { // status�� ���
	gotoxy(0, 0); printf("Stage: %d", gameStatus->stage);
	gotoxy(25, 0);
	if (gameStatus->life == 1) {
		printf("Life: %d", gameStatus->life);
	}
	else {
		printf("Lifes: %d", gameStatus->life);
	}
	gotoxy(50, 0); printf("Score: %d", gameStatus->score);
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