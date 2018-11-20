#include "console.h"

#define HIDE_CURSOR

struct _record* consoleSetting() { // 최초 콘솔 세팅
	system("title Acid Rain"); // 콘솔 타이틀 변경
	system("mode con: cols=64 lines=27"); // 콘솔 사이즈 변경

#ifdef HIDE_CURSOR
	setCursorType(NOCURSOR); // 커서 숨기기
#endif

	setColor(WHITE);

	// _record 동적 할당
	struct _record* rcPtr = malloc(sizeof(struct _record)*RECORD);
	struct _record rc[RECORD];
	*rcPtr = rc[RECORD];

	return rcPtr;
}

void setColor(int colorNumber) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNumber);
}

void setCursorType(CURSOR_TYPE c) { // 커서 깜빡이지 않게 설정
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
	gotoxy(5, 18 + *menuIndex); printf("→");

	setColor(YELLOW);
	switch (*menuIndex) {
	case 0:
		gotoxy(9, 18); printf("게임시작"); break;
	case 1:
		gotoxy(9, 19); printf("랭킹"); break;
	case 2:
		gotoxy(9, 20); printf("도움말"); break;
	case 3:
		gotoxy(9, 21); printf("로그보기"); break;
	case 4:
		gotoxy(9, 22); printf("설정"); break;
	case 5:
		gotoxy(9, 23); printf("끝내기"); break;
	}

	setColor(WHITE);
}

void printTitle() { // 타이틀 출력
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

void printMenuList() { // 메뉴 목록 출력
	gotoxy(9, 18); printf("게임시작");
	gotoxy(9, 19); printf("랭킹");
	gotoxy(9, 20); printf("도움말");
	gotoxy(9, 21); printf("로그보기");
	gotoxy(9, 22); printf("설정");
	gotoxy(9, 23); printf("끝내기");
}

void printOthers() { // 기타 정보 출력
	// HOW TO PLAY 출력
	gotoxy(30, 18); printf("┌─  ");
	gotoxy(45, 18); printf(" ────────┐");
	for (int i = 0; i < 5; i++) {
		gotoxy(30, 19 + i); printf("│");
		gotoxy(54, 19 + i); printf("│");
	}
	gotoxy(30, 24); printf("└───────────────────────┘");

	setColor(DARK_YELLOW);
	gotoxy(34, 18); printf("HOW TO PLAY");
	setColor(WHITE);

	setColor(DARK_CYAN);
	gotoxy(34, 20); printf("Select");
	gotoxy(34, 21); printf("Input");
	gotoxy(34, 22); printf("Delete");
	gotoxy(34, 23); printf("Submit");

	setColor(CYAN);
	gotoxy(44, 20); printf("  ↑ ↓");
	gotoxy(44, 21); printf(" Typing!");
	gotoxy(44, 22); printf("Backspace");
	gotoxy(44, 23); printf("  Enter");
	setColor(WHITE);

	// 프로그램 정보 출력
	setColor(DARK_YELLOW);
	gotoxy(1, 26); printf("v1.0");
	gotoxy(20, 26); printf("https://github.com/youseokhwan/AcidRainGame");
	setColor(WHITE);
}

void printRain() { // 비 출력
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

void printMenu(int* menuIndex) { // 메인화면 출력
	system("cls");

	printTitle(); // 타이틀 출력
	printMenuList(); // 메뉴 목록 출력
	printOthers(); // 기타 정보 출력
	printRain(); // 비 출력
	printArrow(menuIndex); // 화살표 출력
}

int mainMenu(int* menuIndex) { // 메인 메뉴 컨트롤
	printMenu(menuIndex);

	while (true) {
		while (_kbhit()) {
			int userInput = _getch();

			if (userInput == ARROW) {
				userInput = _getch();

				if (userInput == UP_ARROW) {
					// *menuIndex 값 변경
					if (*menuIndex != 0) {
						(*menuIndex)--;
					}

					printMenuList();
					printArrow(menuIndex);
				}
				else if (userInput == DOWN_ARROW) {
					// *menuIndex 값 변경
					if (*menuIndex != 5) {
						(*menuIndex)++;
					}

					printMenuList();
					printArrow(menuIndex);
				}
			}
			else if (userInput == ENTER) { // 엔터키누르면 현재 화살표가 가리키는 인덱스 반환
				_getch(); // 불필요한 바이트 버리기

				return *menuIndex;
			}
		}
	}

	return 0; // 위 내용 완성되면 삭제
}

void printHelp() { // 도움말 출력
	system("cls");

	gotoxy(0, 0); printf("도움말 출력!");
	system("pause>nul");
}

void setting() { // 설정 창 출력
	system("cls");

	gotoxy(0, 0); printf("setting() 진입");
	system("pause>nul");
}

void gotoxy(int x, int y) { // 커서 특정 좌표로 이동
	COORD cursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void printSingleBorderLine() { // rank, log 등에서 한 줄짜리 경계선 출력
	setColor(DARK_YELLOW);
	gotoxy(0, 3); printf("===============================================================");
	setColor(WHITE);
}

void printDoubleBorderLine() { // gameBoard에서 두 줄짜리 경계선 출력
	setColor(DARK_YELLOW);
	gotoxy(0, 1); printf("===============================================================\n");
	gotoxy(0, 22); printf("===============================================================\n");
	setColor(WHITE);
}

void printStatus(struct _gameStatus* gameStatus) { // status값 출력
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

void printPrompt() { // 입력 창 출력
	setColor(DARK_YELLOW);
	gotoxy(0, 24);  printf("Input >> ");
	setColor(WHITE);
}

void clearStatus() { // status값 지우기
	gotoxy(0, 0);
	printf("                                                                ");
}

void clearBoard() { // 단어 지우기
	for (int i = 2; i <= 21; i++) {
		gotoxy(0, i);
		printf("                                                                ");
	}
}

void clearPrompt() { // 입력창 지우기
	gotoxy(0, 24); printf("                                 ");
}
