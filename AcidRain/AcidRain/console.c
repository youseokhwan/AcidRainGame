#include "console.h"

struct _record* consoleSetting(struct _gameStatus* gameStatus) { // ���� �ܼ� ����
	system("title Acid Rain"); // �ܼ� Ÿ��Ʋ ����
	system("mode con: cols=64 lines=27"); // �ܼ� ������ ����

	setCursorType(NOCURSOR); // Ŀ�� �����
	setColor(WHITE);

	for (int i = 0; i < STAGE; i++) { // �ܾ� ���ϼӵ� ���� ����
		gameStatus->dropSpeed[i] = 800 - 60 * i;
	}

	// _record ���� �Ҵ�
	struct _record* rcPtr = malloc(sizeof(struct _record)*RECORD);
	struct _record rc[RECORD];
	*rcPtr = rc[RECORD];

	return rcPtr;
}

void setColor(int colorNumber) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNumber);
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

void printArrow(int* menuIndex) {
	for (int i = 0; i < 6; i++) {
		gotoxy(5, 18 + i); printf("  ");
	}

	setColor(DARK_YELLOW);
	gotoxy(5, 18 + *menuIndex); printf("��");

	setColor(YELLOW);
	switch (*menuIndex) {
	case 0:
		gotoxy(9, 18); printf("���ӽ���"); break;
	case 1:
		gotoxy(9, 19); printf("��ŷ"); break;
	case 2:
		gotoxy(9, 20); printf("����"); break;
	case 3:
		gotoxy(9, 21); printf("�α׺���"); break;
	case 4:
		gotoxy(9, 22); printf("������ ����"); break;
	case 5:
		gotoxy(9, 23); printf("������"); break;
	}

	setColor(WHITE);
}

void printTitle() { // Ÿ��Ʋ ���
	// "A"cid Rain
	gotoxy(5, 6); printf("##"); Sleep(DELAY);
	gotoxy(5, 5); printf("##"); Sleep(DELAY);
	gotoxy(6, 4); printf("##"); Sleep(DELAY);
	gotoxy(6, 3); printf("##"); Sleep(DELAY);
	gotoxy(7, 2); printf("##"); Sleep(DELAY);
	gotoxy(8, 1); printf("###"); Sleep(DELAY);
	gotoxy(10, 2); printf("##"); Sleep(DELAY);
	gotoxy(11, 3); printf("##"); Sleep(DELAY);
	gotoxy(11, 4); printf("##"); Sleep(DELAY);
	gotoxy(12, 5); printf("##"); Sleep(DELAY);
	gotoxy(12, 6); printf("##"); Sleep(DELAY);
	gotoxy(8, 4); printf("#"); Sleep(DELAY);
	gotoxy(9, 4); printf("##"); Sleep(DELAY);
	gotoxy(10, 4); printf("##"); Sleep(DELAY);

	// A"c"id Rain
	gotoxy(21, 3); printf("##"); Sleep(DELAY);
	gotoxy(19, 3); printf("##"); Sleep(DELAY);
	gotoxy(17, 3); printf("##"); Sleep(DELAY);
	gotoxy(16, 4); printf("##"); Sleep(DELAY);
	gotoxy(16, 5); printf("##"); Sleep(DELAY);
	gotoxy(17, 6); printf("##"); Sleep(DELAY);
	gotoxy(19, 6); printf("##"); Sleep(DELAY);
	gotoxy(21, 6); printf("#"); Sleep(DELAY);

	// Ac"i"d Rain
	gotoxy(25, 1); printf("##"); Sleep(DELAY);
	gotoxy(25, 3); printf("##"); Sleep(DELAY);
	gotoxy(25, 4); printf("##"); Sleep(DELAY);
	gotoxy(25, 5); printf("##"); Sleep(DELAY);
	gotoxy(25, 6); printf("##"); Sleep(DELAY);

	// Aci"d" Rain
	gotoxy(34, 1); printf("##"); Sleep(DELAY);
	gotoxy(34, 2); printf("##"); Sleep(DELAY);
	gotoxy(34, 3); printf("##"); Sleep(DELAY);
	gotoxy(34, 4); printf("##"); Sleep(DELAY);
	gotoxy(34, 5); printf("##"); Sleep(DELAY);
	gotoxy(34, 6); printf("#"); Sleep(DELAY);
	gotoxy(32, 3); printf("##"); Sleep(DELAY);
	gotoxy(30, 3); printf("##"); Sleep(DELAY);
	gotoxy(29, 4); printf("##"); Sleep(DELAY);
	gotoxy(29, 5); printf("##"); Sleep(DELAY);
	gotoxy(30, 6); printf("##"); Sleep(DELAY);
	gotoxy(32, 6); printf("##"); Sleep(DELAY);

	// Acid "R"ain
	gotoxy(28, 10); printf("##"); Sleep(DELAY);
	gotoxy(28, 11); printf("##"); Sleep(DELAY);
	gotoxy(28, 12); printf("##"); Sleep(DELAY);
	gotoxy(28, 13); printf("##"); Sleep(DELAY);
	gotoxy(28, 14); printf("##"); Sleep(DELAY);
	gotoxy(29, 9); printf("##"); Sleep(DELAY);
	gotoxy(31, 9); printf("##"); Sleep(DELAY);
	gotoxy(33, 9); printf("##"); Sleep(DELAY);
	gotoxy(34, 10); printf("##"); Sleep(DELAY);
	gotoxy(34, 11); printf("##"); Sleep(DELAY);
	gotoxy(33, 12); printf("##"); Sleep(DELAY);
	gotoxy(30, 12); printf("###"); Sleep(DELAY);
	gotoxy(32, 13); printf("##"); Sleep(DELAY);
	gotoxy(33, 14); printf("##"); Sleep(DELAY);
	gotoxy(35, 14); printf("##"); Sleep(DELAY);

	// Acid R"a"in
	gotoxy(41, 11); printf("##"); Sleep(DELAY);
	gotoxy(39, 11); printf("##"); Sleep(DELAY);
	gotoxy(38, 12); printf("##"); Sleep(DELAY);
	gotoxy(38, 13); printf("##"); Sleep(DELAY);
	gotoxy(39, 14); printf("##"); Sleep(DELAY);
	gotoxy(41, 14); printf("##"); Sleep(DELAY);
	gotoxy(42, 13); printf("#"); Sleep(DELAY);
	gotoxy(42, 12); printf("#"); Sleep(DELAY);
	gotoxy(38, 12); printf("##"); Sleep(DELAY);
	gotoxy(43, 12); printf("#"); Sleep(DELAY);
	gotoxy(43, 13); printf("##"); Sleep(DELAY);
	gotoxy(44, 14); printf("##"); Sleep(DELAY);

	// Acid Ra"i"n
	gotoxy(48, 9); printf("##"); Sleep(DELAY);
	gotoxy(48, 11); printf("##"); Sleep(DELAY);
	gotoxy(48, 12); printf("##"); Sleep(DELAY);
	gotoxy(48, 13); printf("##"); Sleep(DELAY);
	gotoxy(48, 14); printf("##"); Sleep(DELAY);

	// Acid Rai"n"
	gotoxy(52, 12); printf("##"); Sleep(DELAY);
	gotoxy(52, 13); printf("##"); Sleep(DELAY);
	gotoxy(52, 14); printf("##"); Sleep(DELAY);
	gotoxy(53, 11); printf("###"); Sleep(DELAY);
	gotoxy(56, 11); printf("##"); Sleep(DELAY);
	gotoxy(57, 12); printf("##"); Sleep(DELAY);
	gotoxy(57, 13); printf("##"); Sleep(DELAY);
	gotoxy(57, 14); printf("##"); Sleep(DELAY);
}

void printMenuList() { // �޴� ��� ���
	gotoxy(9, 18); printf("���ӽ���");
	gotoxy(9, 19); printf("��ŷ");
	gotoxy(9, 20); printf("����");
	gotoxy(9, 21); printf("�α׺���");
	gotoxy(9, 22); printf("������ ����");
	gotoxy(9, 23); printf("������");
}

void printOthers() { // ��Ÿ ���� ���
	// HOW TO PLAY ���
	gotoxy(30, 18); printf("����  ");
	gotoxy(45, 18); printf(" ������������������");
	for (int i = 0; i < 5; i++) {
		gotoxy(30, 19 + i); printf("��");
		gotoxy(54, 19 + i); printf("��");
	}
	gotoxy(30, 24); printf("��������������������������������������������������");

	setColor(DARK_YELLOW);
	gotoxy(34, 18); printf("HOW TO PLAY");
	setColor(WHITE);

	setColor(DARK_CYAN);
	gotoxy(34, 20); printf("Select");
	gotoxy(34, 21); printf("Input");
	gotoxy(34, 22); printf("Delete");
	gotoxy(34, 23); printf("Submit");

	setColor(CYAN);
	gotoxy(44, 20); printf("  �� ��");
	gotoxy(44, 21); printf(" Typing!");
	gotoxy(44, 22); printf("Backspace");
	gotoxy(44, 23); printf("  Enter");
	setColor(WHITE);

	// ���α׷� ���� ���
	setColor(DARK_YELLOW);
	gotoxy(1, 26); printf("%s", VERSION);
	gotoxy(20, 26); printf("https://github.com/youseokhwan/AcidRainGame");
	setColor(WHITE);
}

void printRain() { // �� ���
	setColor(DARK_CYAN);

	gotoxy(20, 0); printf("*");
	gotoxy(46, 3); printf("*");
	gotoxy(60, 8); printf("*");
	gotoxy(9, 11); printf("*");
	gotoxy(36, 13); printf("*");
	gotoxy(57, 20); printf("*");
	gotoxy(22, 22); printf("*"); Sleep(DELAY * 4);

	gotoxy(19, 1); printf("*");
	gotoxy(45, 4); printf("*");
	gotoxy(59, 9); printf("*");
	gotoxy(8, 12); printf("*");
	gotoxy(56, 21); printf("*");
	gotoxy(21, 23); printf("*"); Sleep(DELAY * 4);

	gotoxy(18, 2); printf("*");
	gotoxy(44, 5); printf("*");
	gotoxy(58, 10); printf("*");
	gotoxy(27, 12); printf("*");
	gotoxy(7, 13); printf("*");
	gotoxy(34, 15); printf("*");
	gotoxy(20, 24); printf("*"); Sleep(DELAY * 4);

	gotoxy(43, 6); printf("*");
	gotoxy(26, 13); printf("*");
	gotoxy(6, 14); printf("*");
	gotoxy(33, 16); printf("*");
	gotoxy(19, 25); printf("*"); Sleep(DELAY * 4);

	gotoxy(42, 7); printf("*");
	gotoxy(25, 14); printf("*");
	gotoxy(5, 15); printf("*");
	gotoxy(32, 17); printf("*");
	// gotoxy(53, 24); printf("*");
	gotoxy(18, 26); printf("*"); Sleep(DELAY * 4);

	setColor(WHITE);
}

void printMenu(int* menuIndex) { // ����ȭ�� ���
	system("cls");

	printTitle(); // Ÿ��Ʋ ���
	printMenuList(); // �޴� ��� ���
	printOthers(); // ��Ÿ ���� ���
	printRain(); // �� ���
	printArrow(menuIndex); // ȭ��ǥ ���
}

int mainMenu(int* menuIndex) { // ���� �޴� ��Ʈ��
	printMenu(menuIndex);

	while (true) {
		while (_kbhit()) {
			int userInput = _getch();

			if (userInput == ARROW) {
				userInput = _getch();

				if (userInput == UP_ARROW) {
					// *menuIndex �� ����
					if (*menuIndex != 0) {
						(*menuIndex)--;
					}

					printMenuList();
					printArrow(menuIndex);
				}
				else if (userInput == DOWN_ARROW) {
					// *menuIndex �� ����
					if (*menuIndex != 5) {
						(*menuIndex)++;
					}

					printMenuList();
					printArrow(menuIndex);
				}
			}
			else if (userInput == ENTER) { // ����Ű������ ���� ȭ��ǥ�� ����Ű�� �ε��� ��ȯ
				_getch(); // ���ʿ��� ����Ʈ ������

				return *menuIndex;
			}
		}
	}

	return 0; // �� ���� �ϼ��Ǹ� ����
}

void printHelp() { // ���� ���
	system("cls");

	printSingleBorderLine(3);
	printSingleBorderLine(8);
	printSingleBorderLine(16);
	printSingleBorderLine(23);

	setColor(YELLOW);
	gotoxy(0, 0); printf("�� HELP");
	gotoxy(0, 2); printf("�� Information");
	gotoxy(0, 7); printf("�� How To Play");
	gotoxy(0, 15); printf("�� Key Setting");
	gotoxy(0, 22); printf("�� Made By");
	setColor(WHITE);

	gotoxy(0, 4); printf("\'Acid Rain\'�� �꼺���� ������, ���ѱ۰���ǻ���� \'����Ÿ�ڿ���\'");
	gotoxy(0, 5); printf("�� \'�꼺��\' ������ ����� C �ְܼ����Դϴ�.");
	gotoxy(0, 9); printf("�������� �ܾ Ÿ�����Ͽ� ���־��ϸ�, �ܾ �ٴڱ��� ������ ��");
	gotoxy(0, 10); printf("�� �������� �ҽ��ϴ�. �������� ��� ������ ������ ����˴ϴ�.");
	gotoxy(0, 12); printf("�� 10���� ���������� �����Ǿ��ְ�, ���� �ҹ��ڸ� ����մϴ�.");
	gotoxy(0, 13); printf("���� ����Ű(��)�� ������ �ߵ� ������ �� �ֽ��ϴ�.");
	gotoxy(0, 17); printf("�޴� �̵�: �� ��");
	gotoxy(0, 18); printf("�ܾ� �Է�: a ~ z Ÿ����");
	gotoxy(0, 19); printf("�ܾ� ����: enterŰ");
	gotoxy(0, 20); printf("�ܾ� �����: backspaceŰ");
	gotoxy(0, 24); printf("youseokhwan");
	gotoxy(0, 25); printf("%s https://github.com/youseokhwan/AcidRainGame", VERSION);

	system("pause>nul");
}

void setting(struct _settingValue* settingValue, struct _gameStatus* gameStatus) { // ���� â ���
	system("cls");

	printSingleBorderLine(3);
	printSingleBorderLine(8);
	printSingleBorderLine(12);

	setColor(YELLOW);
	gotoxy(0, 0); printf("�� DEVELOPER SETTING");
	gotoxy(0, 2); printf("�� ���ư���(press \'��\' key)");
	gotoxy(0, 7); printf("�� �ܼ� Ŀ�� ���̱�(press \'C\' key)");
	gotoxy(0, 11); printf("�� ���� �ӵ� ����(press \'S\' key)");
	setColor(WHITE);

	gotoxy(0, 4); printf("�׽�Ʈ�� ���� ������ ���� �޴��Դϴ�.");
	gotoxy(0, 5); printf("���� ����Ű(��)�� ������ ���θ޴��� ���ư��ϴ�.");
	gotoxy(5, 9); printf("On");
	gotoxy(12, 9); printf("Off");
	gotoxy(5, 13); printf("Normal");
	gotoxy(5, 14); printf("Fast(All Stages)");
	gotoxy(5, 15); printf("Slow(All Stages)");

	setColor(DARK_YELLOW);
	if (settingValue->hideCursorToggle == 0) {
		gotoxy(2, 9); printf("��");
	}
	else {
		gotoxy(9, 9); printf("��");
	}

	if (settingValue->dropSpeedToggle == 0) {
		gotoxy(2, 13); printf("��");
	}
	else if (settingValue->dropSpeedToggle == 1) {
		gotoxy(2, 14); printf("��");
	}
	else {
		gotoxy(2, 15); printf("��");
	}

	while (true) {
		int keyboardInput = _getch();

		if (keyboardInput == ARROW) {
			keyboardInput = _getch();

			if (keyboardInput == LEFT_ARROW) {
				break;
			}
			else {
				// empty!!
			}
		}
		else if (keyboardInput == 67 || keyboardInput == 99) { // c Ȥ�� C �Է����� ��
			_getch();

			if (settingValue->hideCursorToggle == 1) {
				gotoxy(9, 9); printf("  ");
				gotoxy(2, 9); printf("��");
				
				setCursorType(NORMALCURSOR); // Ŀ�� ���̱�

				settingValue->hideCursorToggle = 0;
			}
			else {
				gotoxy(2, 9); printf("  ");
				gotoxy(9, 9); printf("��");

				setCursorType(NOCURSOR); // Ŀ�� �����

				settingValue->hideCursorToggle = 1;
			}
		}
		else if (keyboardInput == 83 || keyboardInput == 115) { // s Ȥ�� S �Է����� ��
			_getch();

			if (settingValue->dropSpeedToggle == 0) {
				gotoxy(2, 13); printf("  ");
				gotoxy(2, 14); printf("��");

				for (int i = 0; i < STAGE; i++) { // �ܾ� ���ϼӵ� ������
					gameStatus->dropSpeed[i] = 200;
				}

				settingValue->dropSpeedToggle = 1;
			}
			else if (settingValue->dropSpeedToggle == 1) {
				gotoxy(2, 14); printf("  ");
				gotoxy(2, 15); printf("��");

				for (int i = 0; i < STAGE; i++) { // �ܾ� ���ϼӵ� ������
					gameStatus->dropSpeed[i] = 2000;
				}

				settingValue->dropSpeedToggle = 2;
			}
			else {
				gotoxy(2, 15); printf("  ");
				gotoxy(2, 13); printf("��");

				for (int i = 0; i < STAGE; i++) { // �ܾ� ���ϼӵ� ��������
					gameStatus->dropSpeed[i] = 800 - 60 * i;
				}

				settingValue->dropSpeedToggle = 0;
			}
		}
		else {
			_getch();
		}
	}
	setColor(WHITE);
}

void gotoxy(int x, int y) { // Ŀ�� Ư�� ��ǥ�� �̵�
	COORD cursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void printSingleBorderLine(int y) { // rank, log ��� �� ��¥�� ��輱 ���
	setColor(DARK_YELLOW);
	gotoxy(0, y); printf("===============================================================");
	setColor(WHITE);
}

void printDoubleBorderLine() { // gameBoard���� �� ��¥�� ��輱 ���
	setColor(DARK_YELLOW);
	gotoxy(0, 1); printf("===============================================================\n");
	gotoxy(0, 22); printf("===============================================================\n");
	setColor(WHITE);
}

void printStatus(struct _gameStatus* gameStatus) { // status�� ���
	setColor(DARK_YELLOW);
	
	gotoxy(0, 0); printf("Stage: ");
	setColor(YELLOW);
	printf("%d", gameStatus->stage);
	setColor(DARK_YELLOW);

	gotoxy(25, 0);
	if (gameStatus->life == 1) {
		printf("Life: ");
	}
	else {
		printf("Lifes: ");
	}
	setColor(YELLOW);
	printf("%d", gameStatus->life);
	setColor(DARK_YELLOW);

	gotoxy(50, 0); printf("Score: ");
	setColor(YELLOW);
	printf("%d", gameStatus->score);
	
	setColor(WHITE);
}

void printPrompt() { // �Է� â ���
	setColor(DARK_YELLOW);
	gotoxy(0, 24);  printf("Input >> ");
	setColor(WHITE);
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

void clearLog() { // �α�â �����
	for (int i = 4; i <= 24; i++) {
		gotoxy(0, i); printf("                                                             ");
	}
}