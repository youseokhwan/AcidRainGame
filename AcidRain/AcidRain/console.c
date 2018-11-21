#include "console.h"

struct _record* consoleSetting(struct _gameStatus* gameStatus) { // 최초 콘솔 세팅
	system("title Acid Rain"); // 콘솔 타이틀 변경
	system("mode con: cols=64 lines=27"); // 콘솔 사이즈 변경

	setCursorType(NOCURSOR); // 커서 숨기기
	setColor(WHITE);

	for (int i = 0; i < STAGE; i++) { // 단어 낙하속도 최초 설정
		gameStatus->dropSpeed[i] = 800 - 60 * i;
	}

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
		gotoxy(9, 22); printf("개발자 설정"); break;
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
	gotoxy(9, 22); printf("개발자 설정");
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
	gotoxy(1, 26); printf("%s", VERSION);
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

	printSingleBorderLine(3);
	printSingleBorderLine(8);
	printSingleBorderLine(16);
	printSingleBorderLine(23);

	setColor(YELLOW);
	gotoxy(0, 0); printf("● HELP");
	gotoxy(0, 2); printf("○ Information");
	gotoxy(0, 7); printf("○ How To Play");
	gotoxy(0, 15); printf("○ Key Setting");
	gotoxy(0, 22); printf("○ Made By");
	setColor(WHITE);

	gotoxy(0, 4); printf("\'Acid Rain\'은 산성비라는 뜻으로, ㈜한글과컴퓨터의 \'한컴타자연습\'");
	gotoxy(0, 5); printf("의 \'산성비\' 게임을 모방한 C 콘솔게임입니다.");
	gotoxy(0, 9); printf("내려오는 단어를 타이핑하여 없애야하며, 단어가 바닥까지 내려올 경");
	gotoxy(0, 10); printf("우 라이프를 잃습니다. 라이프를 모두 읽으면 게임이 종료됩니다.");
	gotoxy(0, 12); printf("총 10개의 스테이지로 구성되어있고, 영어 소문자만 사용합니다.");
	gotoxy(0, 13); printf("왼쪽 방향키(←)를 누르면 중도 포기할 수 있습니다.");
	gotoxy(0, 17); printf("메뉴 이동: ↑ ↓");
	gotoxy(0, 18); printf("단어 입력: a ~ z 타이핑");
	gotoxy(0, 19); printf("단어 제출: enter키");
	gotoxy(0, 20); printf("단어 지우기: backspace키");
	gotoxy(0, 24); printf("youseokhwan");
	gotoxy(0, 25); printf("%s https://github.com/youseokhwan/AcidRainGame", VERSION);

	system("pause>nul");
}

void setting(struct _settingValue* settingValue, struct _gameStatus* gameStatus) { // 설정 창 출력
	system("cls");

	printSingleBorderLine(3);
	printSingleBorderLine(8);
	printSingleBorderLine(12);

	setColor(YELLOW);
	gotoxy(0, 0); printf("● DEVELOPER SETTING");
	gotoxy(0, 2); printf("○ 돌아가기(press \'←\' key)");
	gotoxy(0, 7); printf("○ 콘솔 커서 보이기(press \'C\' key)");
	gotoxy(0, 11); printf("○ 낙하 속도 조정(press \'S\' key)");
	setColor(WHITE);

	gotoxy(0, 4); printf("테스트를 위한 개발자 설정 메뉴입니다.");
	gotoxy(0, 5); printf("왼쪽 방향키(←)를 누르면 메인메뉴로 돌아갑니다.");
	gotoxy(5, 9); printf("On");
	gotoxy(12, 9); printf("Off");
	gotoxy(5, 13); printf("Normal");
	gotoxy(5, 14); printf("Fast(All Stages)");
	gotoxy(5, 15); printf("Slow(All Stages)");

	setColor(DARK_YELLOW);
	if (settingValue->hideCursorToggle == 0) {
		gotoxy(2, 9); printf("●");
	}
	else {
		gotoxy(9, 9); printf("●");
	}

	if (settingValue->dropSpeedToggle == 0) {
		gotoxy(2, 13); printf("●");
	}
	else if (settingValue->dropSpeedToggle == 1) {
		gotoxy(2, 14); printf("●");
	}
	else {
		gotoxy(2, 15); printf("●");
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
		else if (keyboardInput == 67 || keyboardInput == 99) { // c 혹은 C 입력했을 때
			_getch();

			if (settingValue->hideCursorToggle == 1) {
				gotoxy(9, 9); printf("  ");
				gotoxy(2, 9); printf("●");
				
				setCursorType(NORMALCURSOR); // 커서 보이기

				settingValue->hideCursorToggle = 0;
			}
			else {
				gotoxy(2, 9); printf("  ");
				gotoxy(9, 9); printf("●");

				setCursorType(NOCURSOR); // 커서 숨기기

				settingValue->hideCursorToggle = 1;
			}
		}
		else if (keyboardInput == 83 || keyboardInput == 115) { // s 혹은 S 입력했을 때
			_getch();

			if (settingValue->dropSpeedToggle == 0) {
				gotoxy(2, 13); printf("  ");
				gotoxy(2, 14); printf("●");

				for (int i = 0; i < STAGE; i++) { // 단어 낙하속도 빠르게
					gameStatus->dropSpeed[i] = 200;
				}

				settingValue->dropSpeedToggle = 1;
			}
			else if (settingValue->dropSpeedToggle == 1) {
				gotoxy(2, 14); printf("  ");
				gotoxy(2, 15); printf("●");

				for (int i = 0; i < STAGE; i++) { // 단어 낙하속도 느리게
					gameStatus->dropSpeed[i] = 2000;
				}

				settingValue->dropSpeedToggle = 2;
			}
			else {
				gotoxy(2, 15); printf("  ");
				gotoxy(2, 13); printf("●");

				for (int i = 0; i < STAGE; i++) { // 단어 낙하속도 정상으로
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

void gotoxy(int x, int y) { // 커서 특정 좌표로 이동
	COORD cursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void printSingleBorderLine(int y) { // rank, log 등에서 한 줄짜리 경계선 출력
	setColor(DARK_YELLOW);
	gotoxy(0, y); printf("===============================================================");
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

void clearLog() { // 로그창 지우기
	for (int i = 4; i <= 24; i++) {
		gotoxy(0, i); printf("                                                             ");
	}
}