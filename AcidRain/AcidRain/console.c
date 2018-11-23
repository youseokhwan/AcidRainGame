#include "console.h"

/*
	title �� �ܼ� ������ ����
	Ŀ�� �����, �ܾ� ���ϼӵ� �������� ����
*/
void consoleSetting(struct _gameStatus* gameStatus) {
	system("title Acid Rain");
	system("mode con: cols=64 lines=27");

	setCursorType(NOCURSOR);
	setColor(WHITE);

	for (int i = 0; i < STAGE; i++) {
		gameStatus->dropSpeed[i] = 800 - 60 * i;
	}
}

/*
	�ܼ� ���ڻ� ����
	���� �ڵ�� console.h ����
*/
void setColor(int colorNumber) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNumber);
}

/*
	�ֿܼ��� Ŀ�� ���� �����ϴ� �Լ�
	NOCURSOR: Ŀ�� ����
	SOLIDCURSOR: solid ���� Ŀ���� ����
	NORMALCURSOR: �Ϲ� _ Ŀ���� ����(�ܼ� ����Ʈ ��)
*/
void setCursorType(CURSOR_TYPE c) {
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

/*
	���� ȭ�鿡�� ȭ��ǥ ����ϴ� �Լ�
	printMenu( )���� ���
*/
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

/*
	���� ȭ�鿡�� Acid Rain �ִϸ��̼� ����ϴ� �Լ�
	printMenu( )���� ���
*/
void printTitle() {
	// "A"cid Rain
	gotoxy(5, 7); printf("##"); Sleep(DELAY);
	gotoxy(5, 6); printf("##"); Sleep(DELAY);
	gotoxy(6, 5); printf("##"); Sleep(DELAY);
	gotoxy(6, 4); printf("##"); Sleep(DELAY);
	gotoxy(7, 3); printf("##"); Sleep(DELAY);
	gotoxy(8, 2); printf("###"); Sleep(DELAY);
	gotoxy(10, 3); printf("##"); Sleep(DELAY);
	gotoxy(11, 4); printf("##"); Sleep(DELAY);
	gotoxy(11, 5); printf("##"); Sleep(DELAY);
	gotoxy(12, 6); printf("##"); Sleep(DELAY);
	gotoxy(12, 7); printf("##"); Sleep(DELAY);
	gotoxy(8, 5); printf("#"); Sleep(DELAY);
	gotoxy(9, 5); printf("##"); Sleep(DELAY);
	gotoxy(10, 5); printf("##"); Sleep(DELAY);

	// A"c"id Rain
	gotoxy(21, 4); printf("##"); Sleep(DELAY);
	gotoxy(19, 4); printf("##"); Sleep(DELAY);
	gotoxy(17, 4); printf("##"); Sleep(DELAY);
	gotoxy(16, 5); printf("##"); Sleep(DELAY);
	gotoxy(16, 6); printf("##"); Sleep(DELAY);
	gotoxy(17, 7); printf("##"); Sleep(DELAY);
	gotoxy(19, 7); printf("##"); Sleep(DELAY);
	gotoxy(21, 7); printf("#"); Sleep(DELAY);

	// Ac"i"d Rain
	gotoxy(25, 2); printf("##"); Sleep(DELAY);
	gotoxy(25, 4); printf("##"); Sleep(DELAY);
	gotoxy(25, 5); printf("##"); Sleep(DELAY);
	gotoxy(25, 6); printf("##"); Sleep(DELAY);
	gotoxy(25, 7); printf("##"); Sleep(DELAY);

	// Aci"d" Rain
	gotoxy(34, 2); printf("##"); Sleep(DELAY);
	gotoxy(34, 3); printf("##"); Sleep(DELAY);
	gotoxy(34, 4); printf("##"); Sleep(DELAY);
	gotoxy(34, 5); printf("##"); Sleep(DELAY);
	gotoxy(34, 6); printf("##"); Sleep(DELAY);
	gotoxy(34, 7); printf("#"); Sleep(DELAY);
	gotoxy(32, 4); printf("##"); Sleep(DELAY);
	gotoxy(30, 4); printf("##"); Sleep(DELAY);
	gotoxy(29, 5); printf("##"); Sleep(DELAY);
	gotoxy(29, 6); printf("##"); Sleep(DELAY);
	gotoxy(30, 7); printf("##"); Sleep(DELAY);
	gotoxy(32, 7); printf("##"); Sleep(DELAY);

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


/*
	���� ȭ�鿡�� �޴� ��� ����ϴ� �Լ�
	printMenu( )���� ���
*/
void printMenuList() {
	gotoxy(9, 18); printf("���ӽ���");
	gotoxy(9, 19); printf("��ŷ");
	gotoxy(9, 20); printf("����");
	gotoxy(9, 21); printf("�α׺���");
	gotoxy(9, 22); printf("������ ����");
	gotoxy(9, 23); printf("������");
}

/*
	���� ȭ�鿡�� HOW TO PLAY, ���α׷� ���� ����ϴ� �Լ�
	printMenu( )���� ���
*/
void printOthers() {
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

/*
	���� ȭ�鿡�� �� ������ �ִϸ��̼� ����ϴ� �Լ�
	printMenu( )���� ���
*/
void printRain() {
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
	gotoxy(18, 26); printf("*"); Sleep(DELAY * 4);

	setColor(WHITE);
}

/*
	���� ȭ�� ����ϴ� �Լ�
*/
void printMenu(int* menuIndex) {
	system("cls");

	printTitle();
	printMenuList();
	printOthers();
	printRain();
	printArrow(menuIndex);
}

/*
	���� ��Ͽ��� ����Ű ���� �� �ε��� �� ��ȯ�ϴ� �Լ�
*/
int mainMenu(int* menuIndex) {
	printMenu(menuIndex);

	while (true) {
		while (_kbhit()) {
			int userInput = _getch();

			if (userInput == ARROW) {
				userInput = _getch();

				if (userInput == UP_ARROW) {
					if (*menuIndex != 0) {
						(*menuIndex)--;
					}

					printMenuList();
					printArrow(menuIndex);
				}
				else if (userInput == DOWN_ARROW) {
					if (*menuIndex != 5) {
						(*menuIndex)++;
					}

					printMenuList();
					printArrow(menuIndex);
				}
			}
			else if (userInput == ENTER) { // ���� �ε��� ��ȯ
#ifndef ISSUE
				_getch(); // �Է� ��Ʈ�� ����
#endif

				return *menuIndex;
			}
		}
	}
}

/*
	���� ���
*/
void printHelp() {
	system("cls");
	PlaySound(TEXT(SOUND_SELECT), NULL, SND_FILENAME | SND_ASYNC); // select.wav ���

	printSingleBorderLine(3);
	printSingleBorderLine(8);
	printSingleBorderLine(16);
	printSingleBorderLine(23);

	setColor(YELLOW);
	gotoxy(0, 0); printf("�� HELP");
	gotoxy(0, 2); printf("�� Information");
	gotoxy(0, 7); printf("�� How To Play");
	gotoxy(0, 15); printf("�� Key Setting");
	gotoxy(0, 22); printf("�� Made by");
	
	setColor(CYAN);
	gotoxy(11, 22); printf("youseokhwan");

	setColor(DARK_YELLOW);
	gotoxy(1, 26); printf("%s", VERSION);
	gotoxy(20, 26); printf("https://github.com/youseokhwan/AcidRainGame");

	/*
		���� �ؽ�Ʈ �ִϸ��̼����� ����
	*/
	setColor(WHITE);
	gotoxy(0, 4); printf("\'"); gotoxy(0, 9); printf("��");
	gotoxy(0, 12); printf("��"); gotoxy(0, 17); printf("��"); Sleep(DELAY);

	gotoxy(1, 4); printf("A"); gotoxy(2, 9); printf("��");
	gotoxy(2, 12); printf(" "); gotoxy(2, 17); printf("��"); Sleep(DELAY);

	gotoxy(2, 4); printf("c"); gotoxy(4, 9); printf("��");
	gotoxy(3, 12); printf("1"); gotoxy(4, 17); printf(" "); Sleep(DELAY);

	gotoxy(3, 4); printf("i"); gotoxy(6, 9); printf("��");
	gotoxy(4, 12); printf("0"); gotoxy(5, 17); printf("��"); Sleep(DELAY);

	gotoxy(4, 4); printf("d"); gotoxy(8, 9); printf(" ");
	gotoxy(5, 12); printf("��"); gotoxy(7, 17); printf("��"); Sleep(DELAY);

	gotoxy(5, 4); printf(" "); gotoxy(9, 9); printf("��");
	gotoxy(7, 12); printf("��"); gotoxy(9, 17); printf(":"); Sleep(DELAY);

	gotoxy(6, 4); printf("R"); gotoxy(11, 9); printf("��");
	gotoxy(9, 12); printf(" "); gotoxy(10, 17); printf(" "); Sleep(DELAY);

	gotoxy(7, 4); printf("a"); gotoxy(13, 9); printf("��");
	gotoxy(10, 12); printf("��"); gotoxy(11, 17); printf("��"); Sleep(DELAY);

	gotoxy(8, 4); printf("i"); gotoxy(15, 9); printf(" ");
	gotoxy(12, 12); printf("��"); gotoxy(13, 17); printf(" "); Sleep(DELAY);

	gotoxy(9, 4); printf("n"); gotoxy(16, 9); printf("Ÿ");
	gotoxy(14, 12); printf("��"); gotoxy(14, 17); printf("��"); Sleep(DELAY);

	gotoxy(10, 4); printf("\'"); gotoxy(18, 9); printf("��");
	gotoxy(16, 12); printf("��"); gotoxy(0, 18); printf("��"); Sleep(DELAY);

	gotoxy(11, 4); printf("��"); gotoxy(20, 9); printf("��");
	gotoxy(18, 12); printf("��"); gotoxy(2, 18); printf("��"); Sleep(DELAY);

	gotoxy(13, 4); printf(" "); gotoxy(22, 9); printf("��");
	gotoxy(20, 12); printf(" "); gotoxy(4, 18); printf(" "); Sleep(DELAY);

	gotoxy(14, 4); printf("��"); gotoxy(24, 9); printf("��");
	gotoxy(21, 12); printf("��"); gotoxy(5, 18); printf("��"); Sleep(DELAY);

	gotoxy(16, 4); printf("��"); gotoxy(26, 9); printf(" ");
	gotoxy(23, 12); printf("��"); gotoxy(7, 18); printf("��"); Sleep(DELAY);

	gotoxy(18, 4); printf("��"); gotoxy(27, 9); printf("��");
	gotoxy(25, 12); printf("��"); gotoxy(9, 18); printf(":"); Sleep(DELAY);

	gotoxy(20, 4); printf("��"); gotoxy(29, 9); printf("��");
	gotoxy(27, 12); printf("��"); gotoxy(10, 18); printf(" "); Sleep(DELAY);

	gotoxy(22, 4); printf("��"); gotoxy(31, 9); printf("��");
	gotoxy(29, 12); printf("��"); gotoxy(11, 18); printf("a"); Sleep(DELAY);

	gotoxy(24, 4); printf(" "); gotoxy(33, 9); printf("��");
	gotoxy(31, 12); printf("��"); gotoxy(12, 18); printf(" "); Sleep(DELAY);

	gotoxy(25, 4); printf("��"); gotoxy(35, 9); printf("��");
	gotoxy(33, 12); printf(","); gotoxy(13, 18); printf("~"); Sleep(DELAY);

	gotoxy(27, 4); printf("��"); gotoxy(37, 9); printf(",");
	gotoxy(34, 12); printf(" "); gotoxy(14, 18); printf(" "); Sleep(DELAY);

	gotoxy(29, 4); printf("��"); gotoxy(38, 9); printf(" ");
	gotoxy(35, 12); printf("��"); gotoxy(15, 18); printf("z"); Sleep(DELAY);

	gotoxy(31, 4); printf(","); gotoxy(39, 9); printf("��");
	gotoxy(37, 12); printf("��"); gotoxy(16, 18); printf(" "); Sleep(DELAY);

	gotoxy(32, 4); printf(" "); gotoxy(41, 9); printf("��");
	gotoxy(39, 12); printf(" "); gotoxy(17, 18); printf("Ÿ"); Sleep(DELAY);

	gotoxy(33, 4); printf("��"); gotoxy(43, 9); printf("��");
	gotoxy(40, 12); printf("��"); gotoxy(19, 18); printf("��"); Sleep(DELAY);

	gotoxy(35, 4); printf("��"); gotoxy(45, 9); printf(" ");
	gotoxy(42, 12); printf("��"); gotoxy(21, 18); printf("��"); Sleep(DELAY);

	gotoxy(37, 4); printf("��"); gotoxy(46, 9); printf("��");
	gotoxy(44, 12); printf("��"); gotoxy(0, 19); printf("��"); Sleep(DELAY);

	gotoxy(39, 4); printf("��"); gotoxy(48, 9); printf("��");
	gotoxy(46, 12); printf("��"); gotoxy(2, 19); printf("��"); Sleep(DELAY);

	gotoxy(41, 4); printf("��"); gotoxy(50, 9); printf("��");
	gotoxy(48, 12); printf(" "); gotoxy(4, 19); printf(" "); Sleep(DELAY);

	gotoxy(43, 4); printf("ǻ"); gotoxy(52, 9); printf("��");
	gotoxy(49, 12); printf("��"); gotoxy(5, 19); printf("��"); Sleep(DELAY);

	gotoxy(45, 4); printf("��"); gotoxy(54, 9); printf(" ");
	gotoxy(51, 12); printf("��"); gotoxy(7, 19); printf("��"); Sleep(DELAY);

	gotoxy(47, 4); printf("��"); gotoxy(55, 9); printf("��");
	gotoxy(53, 12); printf("��"); gotoxy(9, 19); printf(":"); Sleep(DELAY);

	gotoxy(49, 4); printf(" "); gotoxy(57, 9); printf("��");
	gotoxy(55, 12); printf("��"); gotoxy(10, 19); printf(" "); Sleep(DELAY);

	gotoxy(50, 4); printf("\'"); gotoxy(59, 9); printf("��");
	gotoxy(57, 12); printf("��"); gotoxy(11, 19); printf("e"); Sleep(DELAY);

	gotoxy(51, 4); printf("��"); gotoxy(61, 9); printf(" ");
	gotoxy(59, 12); printf("."); gotoxy(12, 19); printf("n"); Sleep(DELAY);

	gotoxy(53, 4); printf("��"); gotoxy(62, 9); printf("��");
	gotoxy(0, 13); printf("��"); gotoxy(13, 19); printf("t"); Sleep(DELAY);

	gotoxy(55, 4); printf("Ÿ"); gotoxy(0, 10); printf("��");
	gotoxy(2, 13); printf("��"); gotoxy(14, 19); printf("e"); Sleep(DELAY);

	gotoxy(57, 4); printf("��"); gotoxy(2, 10); printf(" ");
	gotoxy(4, 13); printf(" "); gotoxy(15, 19); printf("r"); Sleep(DELAY);

	gotoxy(59, 4); printf("��"); gotoxy(3, 10); printf("��");
	gotoxy(5, 13); printf("��"); gotoxy(16, 19); printf("Ű"); Sleep(DELAY);

	gotoxy(61, 4); printf("��"); gotoxy(5, 10); printf("��");
	gotoxy(7, 13); printf("��"); gotoxy(0, 20); printf("��"); Sleep(DELAY);

	gotoxy(63, 4); printf("\'"); gotoxy(7, 10); printf("��");
	gotoxy(9, 13); printf("Ű"); gotoxy(2, 20); printf("��"); Sleep(DELAY);

	gotoxy(0, 5); printf("��"); gotoxy(9, 10); printf("��");
	gotoxy(11, 13); printf("("); gotoxy(4, 20); printf(" "); Sleep(DELAY);

	gotoxy(2, 5); printf(" "); gotoxy(11, 10); printf(" ");
	gotoxy(12, 13); printf("��"); gotoxy(5, 20); printf("��"); Sleep(DELAY);

	gotoxy(3, 5); printf("\'"); gotoxy(12, 10); printf("��");
	gotoxy(14, 13); printf(")"); gotoxy(7, 20); printf("��"); Sleep(DELAY);

	gotoxy(4, 5); printf("��"); gotoxy(14, 10); printf("��");
	gotoxy(15, 13); printf("��"); gotoxy(9, 20); printf("��"); Sleep(DELAY);

	gotoxy(6, 5); printf("��"); gotoxy(16, 10); printf("��");
	gotoxy(17, 13); printf(" "); gotoxy(11, 20); printf(":"); Sleep(DELAY);

	gotoxy(8, 5); printf("��"); gotoxy(18, 10); printf("��");
	gotoxy(18, 13); printf("��"); gotoxy(12, 20); printf(" "); Sleep(DELAY);

	gotoxy(10, 5); printf("\'"); gotoxy(20, 10); printf(".");
	gotoxy(20, 13); printf("��"); gotoxy(13, 20); printf("b"); Sleep(DELAY);

	gotoxy(11, 5); printf(" "); gotoxy(21, 10); printf(" ");
	gotoxy(22, 13); printf("��"); gotoxy(14, 20); printf("a"); Sleep(DELAY);

	gotoxy(12, 5); printf("��"); gotoxy(22, 10); printf("��");
	gotoxy(24, 13); printf(" "); gotoxy(15, 20); printf("c"); Sleep(DELAY);

	gotoxy(14, 5); printf("��"); gotoxy(24, 10); printf("��");
	gotoxy(25, 13); printf("��"); gotoxy(16, 20); printf("k"); Sleep(DELAY);

	gotoxy(16, 5); printf("��"); gotoxy(26, 10); printf("��");
	gotoxy(27, 13); printf("��"); gotoxy(17, 20); printf("s"); Sleep(DELAY);

	gotoxy(18, 5); printf(" "); gotoxy(28, 10); printf("��");
	gotoxy(29, 13); printf(" "); gotoxy(18, 20); printf("p"); Sleep(DELAY);

	gotoxy(19, 5); printf("��"); gotoxy(30, 10); printf(" ");
	gotoxy(30, 13); printf("��"); gotoxy(19, 20); printf("a"); Sleep(DELAY);

	gotoxy(21, 5); printf("��"); gotoxy(31, 10); printf("��");
	gotoxy(32, 13); printf("��"); gotoxy(20, 20); printf("c"); Sleep(DELAY);

	gotoxy(23, 5); printf("��"); gotoxy(33, 10); printf("��");
	gotoxy(34, 13); printf("��"); gotoxy(21, 20); printf("e"); Sleep(DELAY);

	gotoxy(25, 5); printf(" "); gotoxy(35, 10); printf(" ");
	gotoxy(36, 13); printf(" "); gotoxy(22, 20); printf("Ű"); Sleep(DELAY);

	gotoxy(26, 5); printf("C"); gotoxy(36, 10); printf("��");
	gotoxy(37, 13); printf("��"); Sleep(DELAY);

	gotoxy(27, 5); printf(" "); gotoxy(38, 10); printf("��");
	gotoxy(39, 13); printf(" "); Sleep(DELAY);

	gotoxy(28, 5); printf("��"); gotoxy(40, 10); printf("��");
	gotoxy(40, 13); printf("��"); Sleep(DELAY);

	gotoxy(30, 5); printf("��"); gotoxy(42, 10); printf(" ");
	gotoxy(42, 13); printf("��"); Sleep(DELAY);

	gotoxy(32, 5); printf("��"); gotoxy(43, 10); printf("��");
	gotoxy(44, 13); printf("��"); Sleep(DELAY);

	gotoxy(34, 5); printf("��"); gotoxy(45, 10); printf("��");
	gotoxy(46, 13); printf("��"); Sleep(DELAY);

	gotoxy(36, 5); printf("��"); gotoxy(47, 10); printf("��");
	gotoxy(48, 13); printf("."); Sleep(DELAY);

	gotoxy(38, 5); printf("��"); gotoxy(49, 10); printf(" "); Sleep(DELAY);

	gotoxy(40, 5); printf("��"); gotoxy(50, 10); printf("��"); Sleep(DELAY);

	gotoxy(42, 5); printf("."); gotoxy(52, 10); printf("��"); Sleep(DELAY);

	gotoxy(54, 10); printf("��"); Sleep(DELAY);

	gotoxy(56, 10); printf("��"); Sleep(DELAY);

	gotoxy(58, 10); printf("��"); Sleep(DELAY);

	gotoxy(60, 10); printf("."); Sleep(DELAY);

	system("pause>nul");
}

/*
	������ ���� ���
*/
void setting(struct _settingValue* settingValue, struct _gameStatus* gameStatus) {
	system("cls");
	PlaySound(TEXT(SOUND_SELECT), NULL, SND_FILENAME | SND_ASYNC); // select.wav ���

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
#ifndef ISSUE
			_getch();
#endif

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
#ifndef ISSUE
			_getch();
#endif

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
#ifndef ISSUE
			_getch(); // �Է� ��Ʈ�� ����
#endif
		}
	}
	setColor(WHITE);
}

/*
	�ܼ� Ŀ���� Ư�� ��ǥ�� �̵���Ű�� �Լ�
*/
void gotoxy(int x, int y) {
	COORD cursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

/*
	��輱 �� �� ����ϴ� �Լ�
	��ŷ, �α�, ����, ���� â���� ���
*/
void printSingleBorderLine(int y) {
	setColor(DARK_YELLOW);
	gotoxy(0, y); printf("===============================================================");
	setColor(WHITE);
}

/*
	��輱 �� �� ����ϴ� �Լ�
	���� ȭ�鿡�� �ܾ� ���� ������, ���������� ���
*/
void printDoubleBorderLine() {
	setColor(DARK_YELLOW);
	gotoxy(0, 1); printf("===============================================================\n");
	gotoxy(0, 22); printf("===============================================================\n");
	setColor(WHITE);
}

/*
	���� ȭ�鿡�� ȭ�� ��ܿ� ��������, ������, ���ھ� ����ϴ� �Լ�
*/
void printStatus(struct _gameStatus* gameStatus) {
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

/*
	���� ȭ�鿡�� �ϴܿ� �ܾ� �Էº� ������Ʈ ����ϴ� �Լ�
*/
void printPrompt() {
	setColor(DARK_YELLOW);
	gotoxy(0, 24);  printf("Input >> ");
	setColor(WHITE);
}

/*
	���� ȭ�鿡�� ����� Status�� ����� �Լ�
	Status�� ������Ʈ�ϱ� ����
*/
void clearStatus() {
	gotoxy(0, 0);
	printf("                                                                ");
}

/*
	���� ȭ�鿡�� �ܾ� ��� �� ����� �Լ�
	�ܾ� �����ϴ� �ִϸ��̼� �����ϱ� ����
*/
void clearBoard() {
	for (int i = 2; i <= 21; i++) {
		gotoxy(0, i);
		printf("                                                                ");
	}
}

/*
	���� ȭ�鿡�� �ܾ� �Է� �� ����� �Լ�
	�ܾ� �Է� �� ����Ű ���� �� ����� ����
*/
void clearPrompt() {
	gotoxy(0, 24); printf("                                 ");
}
