#include "console.h"

/*
	title 및 콘솔 사이즈 변경
	커서 숨기기, 단어 낙하속도 보통으로 설정
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
	콘솔 글자색 변경
	색상 코드는 console.h 참고
*/
void setColor(int colorNumber) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNumber);
}

/*
	콘솔에서 커서 상태 변경하는 함수
	NOCURSOR: 커서 숨김
	SOLIDCURSOR: solid 형태 커서로 변경
	NORMALCURSOR: 일반 _ 커서로 변경(콘솔 디폴트 값)
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
	메인 화면에서 화살표 출력하는 함수
	printMenu( )에서 사용
*/
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

/*
	메인 화면에서 Acid Rain 애니메이션 출력하는 함수
	printMenu( )에서 사용
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
	메인 화면에서 메뉴 목록 출력하는 함수
	printMenu( )에서 사용
*/
void printMenuList() {
	gotoxy(9, 18); printf("게임시작");
	gotoxy(9, 19); printf("랭킹");
	gotoxy(9, 20); printf("도움말");
	gotoxy(9, 21); printf("로그보기");
	gotoxy(9, 22); printf("개발자 설정");
	gotoxy(9, 23); printf("끝내기");
}

/*
	메인 화면에서 HOW TO PLAY, 프로그램 정보 출력하는 함수
	printMenu( )에서 사용
*/
void printOthers() {
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

/*
	메인 화면에서 비 내리는 애니메이션 출력하는 함수
	printMenu( )에서 사용
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
	메인 화면 출력하는 함수
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
	메인 목록에서 방향키 제어 및 인덱스 값 반환하는 함수
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
			else if (userInput == ENTER) { // 현재 인덱스 반환
#ifndef ISSUE
				_getch(); // 입력 스트림 비우기
#endif

				return *menuIndex;
			}
		}
	}
}

/*
	도움말 출력
*/
void printHelp() {
	system("cls");
	PlaySound(TEXT(SOUND_SELECT), NULL, SND_FILENAME | SND_ASYNC); // select.wav 재생

	printSingleBorderLine(3);
	printSingleBorderLine(8);
	printSingleBorderLine(16);
	printSingleBorderLine(23);

	setColor(YELLOW);
	gotoxy(0, 0); printf("● HELP");
	gotoxy(0, 2); printf("○ Information");
	gotoxy(0, 7); printf("○ How To Play");
	gotoxy(0, 15); printf("○ Key Setting");
	gotoxy(0, 22); printf("○ Made by");
	
	setColor(CYAN);
	gotoxy(11, 22); printf("youseokhwan");

	setColor(DARK_YELLOW);
	gotoxy(1, 26); printf("%s", VERSION);
	gotoxy(20, 26); printf("https://github.com/youseokhwan/AcidRainGame");

	/*
		도움말 텍스트 애니메이션으로 구현
	*/
	setColor(WHITE);
	gotoxy(0, 4); printf("\'"); gotoxy(0, 9); printf("내");
	gotoxy(0, 12); printf("총"); gotoxy(0, 17); printf("메"); Sleep(DELAY);

	gotoxy(1, 4); printf("A"); gotoxy(2, 9); printf("려");
	gotoxy(2, 12); printf(" "); gotoxy(2, 17); printf("뉴"); Sleep(DELAY);

	gotoxy(2, 4); printf("c"); gotoxy(4, 9); printf("오");
	gotoxy(3, 12); printf("1"); gotoxy(4, 17); printf(" "); Sleep(DELAY);

	gotoxy(3, 4); printf("i"); gotoxy(6, 9); printf("는");
	gotoxy(4, 12); printf("0"); gotoxy(5, 17); printf("이"); Sleep(DELAY);

	gotoxy(4, 4); printf("d"); gotoxy(8, 9); printf(" ");
	gotoxy(5, 12); printf("개"); gotoxy(7, 17); printf("동"); Sleep(DELAY);

	gotoxy(5, 4); printf(" "); gotoxy(9, 9); printf("단");
	gotoxy(7, 12); printf("의"); gotoxy(9, 17); printf(":"); Sleep(DELAY);

	gotoxy(6, 4); printf("R"); gotoxy(11, 9); printf("어");
	gotoxy(9, 12); printf(" "); gotoxy(10, 17); printf(" "); Sleep(DELAY);

	gotoxy(7, 4); printf("a"); gotoxy(13, 9); printf("를");
	gotoxy(10, 12); printf("스"); gotoxy(11, 17); printf("↑"); Sleep(DELAY);

	gotoxy(8, 4); printf("i"); gotoxy(15, 9); printf(" ");
	gotoxy(12, 12); printf("테"); gotoxy(13, 17); printf(" "); Sleep(DELAY);

	gotoxy(9, 4); printf("n"); gotoxy(16, 9); printf("타");
	gotoxy(14, 12); printf("이"); gotoxy(14, 17); printf("↓"); Sleep(DELAY);

	gotoxy(10, 4); printf("\'"); gotoxy(18, 9); printf("이");
	gotoxy(16, 12); printf("지"); gotoxy(0, 18); printf("단"); Sleep(DELAY);

	gotoxy(11, 4); printf("은"); gotoxy(20, 9); printf("핑");
	gotoxy(18, 12); printf("로"); gotoxy(2, 18); printf("어"); Sleep(DELAY);

	gotoxy(13, 4); printf(" "); gotoxy(22, 9); printf("하");
	gotoxy(20, 12); printf(" "); gotoxy(4, 18); printf(" "); Sleep(DELAY);

	gotoxy(14, 4); printf("산"); gotoxy(24, 9); printf("여");
	gotoxy(21, 12); printf("구"); gotoxy(5, 18); printf("입"); Sleep(DELAY);

	gotoxy(16, 4); printf("성"); gotoxy(26, 9); printf(" ");
	gotoxy(23, 12); printf("성"); gotoxy(7, 18); printf("력"); Sleep(DELAY);

	gotoxy(18, 4); printf("비"); gotoxy(27, 9); printf("없");
	gotoxy(25, 12); printf("되"); gotoxy(9, 18); printf(":"); Sleep(DELAY);

	gotoxy(20, 4); printf("라"); gotoxy(29, 9); printf("애");
	gotoxy(27, 12); printf("어"); gotoxy(10, 18); printf(" "); Sleep(DELAY);

	gotoxy(22, 4); printf("는"); gotoxy(31, 9); printf("야");
	gotoxy(29, 12); printf("있"); gotoxy(11, 18); printf("a"); Sleep(DELAY);

	gotoxy(24, 4); printf(" "); gotoxy(33, 9); printf("하");
	gotoxy(31, 12); printf("고"); gotoxy(12, 18); printf(" "); Sleep(DELAY);

	gotoxy(25, 4); printf("뜻"); gotoxy(35, 9); printf("며");
	gotoxy(33, 12); printf(","); gotoxy(13, 18); printf("~"); Sleep(DELAY);

	gotoxy(27, 4); printf("으"); gotoxy(37, 9); printf(",");
	gotoxy(34, 12); printf(" "); gotoxy(14, 18); printf(" "); Sleep(DELAY);

	gotoxy(29, 4); printf("로"); gotoxy(38, 9); printf(" ");
	gotoxy(35, 12); printf("영"); gotoxy(15, 18); printf("z"); Sleep(DELAY);

	gotoxy(31, 4); printf(","); gotoxy(39, 9); printf("단");
	gotoxy(37, 12); printf("어"); gotoxy(16, 18); printf(" "); Sleep(DELAY);

	gotoxy(32, 4); printf(" "); gotoxy(41, 9); printf("어");
	gotoxy(39, 12); printf(" "); gotoxy(17, 18); printf("타"); Sleep(DELAY);

	gotoxy(33, 4); printf("㈜"); gotoxy(43, 9); printf("가");
	gotoxy(40, 12); printf("소"); gotoxy(19, 18); printf("이"); Sleep(DELAY);

	gotoxy(35, 4); printf("한"); gotoxy(45, 9); printf(" ");
	gotoxy(42, 12); printf("문"); gotoxy(21, 18); printf("핑"); Sleep(DELAY);

	gotoxy(37, 4); printf("글"); gotoxy(46, 9); printf("바");
	gotoxy(44, 12); printf("자"); gotoxy(0, 19); printf("단"); Sleep(DELAY);

	gotoxy(39, 4); printf("과"); gotoxy(48, 9); printf("닥");
	gotoxy(46, 12); printf("만"); gotoxy(2, 19); printf("어"); Sleep(DELAY);

	gotoxy(41, 4); printf("컴"); gotoxy(50, 9); printf("까");
	gotoxy(48, 12); printf(" "); gotoxy(4, 19); printf(" "); Sleep(DELAY);

	gotoxy(43, 4); printf("퓨"); gotoxy(52, 9); printf("지");
	gotoxy(49, 12); printf("사"); gotoxy(5, 19); printf("제"); Sleep(DELAY);

	gotoxy(45, 4); printf("터"); gotoxy(54, 9); printf(" ");
	gotoxy(51, 12); printf("용"); gotoxy(7, 19); printf("출"); Sleep(DELAY);

	gotoxy(47, 4); printf("의"); gotoxy(55, 9); printf("내");
	gotoxy(53, 12); printf("합"); gotoxy(9, 19); printf(":"); Sleep(DELAY);

	gotoxy(49, 4); printf(" "); gotoxy(57, 9); printf("려");
	gotoxy(55, 12); printf("니"); gotoxy(10, 19); printf(" "); Sleep(DELAY);

	gotoxy(50, 4); printf("\'"); gotoxy(59, 9); printf("올");
	gotoxy(57, 12); printf("다"); gotoxy(11, 19); printf("e"); Sleep(DELAY);

	gotoxy(51, 4); printf("한"); gotoxy(61, 9); printf(" ");
	gotoxy(59, 12); printf("."); gotoxy(12, 19); printf("n"); Sleep(DELAY);

	gotoxy(53, 4); printf("컴"); gotoxy(62, 9); printf("경");
	gotoxy(0, 13); printf("왼"); gotoxy(13, 19); printf("t"); Sleep(DELAY);

	gotoxy(55, 4); printf("타"); gotoxy(0, 10); printf("우");
	gotoxy(2, 13); printf("쪽"); gotoxy(14, 19); printf("e"); Sleep(DELAY);

	gotoxy(57, 4); printf("자"); gotoxy(2, 10); printf(" ");
	gotoxy(4, 13); printf(" "); gotoxy(15, 19); printf("r"); Sleep(DELAY);

	gotoxy(59, 4); printf("연"); gotoxy(3, 10); printf("라");
	gotoxy(5, 13); printf("방"); gotoxy(16, 19); printf("키"); Sleep(DELAY);

	gotoxy(61, 4); printf("습"); gotoxy(5, 10); printf("이");
	gotoxy(7, 13); printf("향"); gotoxy(0, 20); printf("단"); Sleep(DELAY);

	gotoxy(63, 4); printf("\'"); gotoxy(7, 10); printf("프");
	gotoxy(9, 13); printf("키"); gotoxy(2, 20); printf("어"); Sleep(DELAY);

	gotoxy(0, 5); printf("의"); gotoxy(9, 10); printf("를");
	gotoxy(11, 13); printf("("); gotoxy(4, 20); printf(" "); Sleep(DELAY);

	gotoxy(2, 5); printf(" "); gotoxy(11, 10); printf(" ");
	gotoxy(12, 13); printf("←"); gotoxy(5, 20); printf("지"); Sleep(DELAY);

	gotoxy(3, 5); printf("\'"); gotoxy(12, 10); printf("잃");
	gotoxy(14, 13); printf(")"); gotoxy(7, 20); printf("우"); Sleep(DELAY);

	gotoxy(4, 5); printf("산"); gotoxy(14, 10); printf("습");
	gotoxy(15, 13); printf("를"); gotoxy(9, 20); printf("기"); Sleep(DELAY);

	gotoxy(6, 5); printf("성"); gotoxy(16, 10); printf("니");
	gotoxy(17, 13); printf(" "); gotoxy(11, 20); printf(":"); Sleep(DELAY);

	gotoxy(8, 5); printf("비"); gotoxy(18, 10); printf("다");
	gotoxy(18, 13); printf("누"); gotoxy(12, 20); printf(" "); Sleep(DELAY);

	gotoxy(10, 5); printf("\'"); gotoxy(20, 10); printf(".");
	gotoxy(20, 13); printf("르"); gotoxy(13, 20); printf("b"); Sleep(DELAY);

	gotoxy(11, 5); printf(" "); gotoxy(21, 10); printf(" ");
	gotoxy(22, 13); printf("면"); gotoxy(14, 20); printf("a"); Sleep(DELAY);

	gotoxy(12, 5); printf("게"); gotoxy(22, 10); printf("라");
	gotoxy(24, 13); printf(" "); gotoxy(15, 20); printf("c"); Sleep(DELAY);

	gotoxy(14, 5); printf("임"); gotoxy(24, 10); printf("이");
	gotoxy(25, 13); printf("중"); gotoxy(16, 20); printf("k"); Sleep(DELAY);

	gotoxy(16, 5); printf("을"); gotoxy(26, 10); printf("프");
	gotoxy(27, 13); printf("도"); gotoxy(17, 20); printf("s"); Sleep(DELAY);

	gotoxy(18, 5); printf(" "); gotoxy(28, 10); printf("를");
	gotoxy(29, 13); printf(" "); gotoxy(18, 20); printf("p"); Sleep(DELAY);

	gotoxy(19, 5); printf("모"); gotoxy(30, 10); printf(" ");
	gotoxy(30, 13); printf("포"); gotoxy(19, 20); printf("a"); Sleep(DELAY);

	gotoxy(21, 5); printf("방"); gotoxy(31, 10); printf("모");
	gotoxy(32, 13); printf("기"); gotoxy(20, 20); printf("c"); Sleep(DELAY);

	gotoxy(23, 5); printf("한"); gotoxy(33, 10); printf("두");
	gotoxy(34, 13); printf("할"); gotoxy(21, 20); printf("e"); Sleep(DELAY);

	gotoxy(25, 5); printf(" "); gotoxy(35, 10); printf(" ");
	gotoxy(36, 13); printf(" "); gotoxy(22, 20); printf("키"); Sleep(DELAY);

	gotoxy(26, 5); printf("C"); gotoxy(36, 10); printf("잃");
	gotoxy(37, 13); printf("수"); Sleep(DELAY);

	gotoxy(27, 5); printf(" "); gotoxy(38, 10); printf("으");
	gotoxy(39, 13); printf(" "); Sleep(DELAY);

	gotoxy(28, 5); printf("콘"); gotoxy(40, 10); printf("면");
	gotoxy(40, 13); printf("있"); Sleep(DELAY);

	gotoxy(30, 5); printf("솔"); gotoxy(42, 10); printf(" ");
	gotoxy(42, 13); printf("습"); Sleep(DELAY);

	gotoxy(32, 5); printf("게"); gotoxy(43, 10); printf("게");
	gotoxy(44, 13); printf("니"); Sleep(DELAY);

	gotoxy(34, 5); printf("임"); gotoxy(45, 10); printf("임");
	gotoxy(46, 13); printf("다"); Sleep(DELAY);

	gotoxy(36, 5); printf("입"); gotoxy(47, 10); printf("이");
	gotoxy(48, 13); printf("."); Sleep(DELAY);

	gotoxy(38, 5); printf("니"); gotoxy(49, 10); printf(" "); Sleep(DELAY);

	gotoxy(40, 5); printf("다"); gotoxy(50, 10); printf("종"); Sleep(DELAY);

	gotoxy(42, 5); printf("."); gotoxy(52, 10); printf("료"); Sleep(DELAY);

	gotoxy(54, 10); printf("됩"); Sleep(DELAY);

	gotoxy(56, 10); printf("니"); Sleep(DELAY);

	gotoxy(58, 10); printf("다"); Sleep(DELAY);

	gotoxy(60, 10); printf("."); Sleep(DELAY);

	system("pause>nul");
}

/*
	개발자 설정 출력
*/
void setting(struct _settingValue* settingValue, struct _gameStatus* gameStatus) {
	system("cls");
	PlaySound(TEXT(SOUND_SELECT), NULL, SND_FILENAME | SND_ASYNC); // select.wav 재생

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
#ifndef ISSUE
			_getch();
#endif

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
#ifndef ISSUE
			_getch();
#endif

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
#ifndef ISSUE
			_getch(); // 입력 스트림 비우기
#endif
		}
	}
	setColor(WHITE);
}

/*
	콘솔 커서를 특정 좌표로 이동시키는 함수
*/
void gotoxy(int x, int y) {
	COORD cursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

/*
	경계선 한 줄 출력하는 함수
	랭킹, 로그, 도움말, 설정 창에서 사용
*/
void printSingleBorderLine(int y) {
	setColor(DARK_YELLOW);
	gotoxy(0, y); printf("===============================================================");
	setColor(WHITE);
}

/*
	경계선 두 줄 출력하는 함수
	게임 화면에서 단어 낙하 시작점, 도착점으로 사용
*/
void printDoubleBorderLine() {
	setColor(DARK_YELLOW);
	gotoxy(0, 1); printf("===============================================================\n");
	gotoxy(0, 22); printf("===============================================================\n");
	setColor(WHITE);
}

/*
	게임 화면에서 화면 상단에 스테이지, 라이프, 스코어 출력하는 함수
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
	게임 화면에서 하단에 단어 입력부 프롬프트 출력하는 함수
*/
void printPrompt() {
	setColor(DARK_YELLOW);
	gotoxy(0, 24);  printf("Input >> ");
	setColor(WHITE);
}

/*
	게임 화면에서 상단의 Status값 지우는 함수
	Status값 업데이트하기 위함
*/
void clearStatus() {
	gotoxy(0, 0);
	printf("                                                                ");
}

/*
	게임 화면에서 단어 출력 부 지우는 함수
	단어 낙하하는 애니메이션 구현하기 위함
*/
void clearBoard() {
	for (int i = 2; i <= 21; i++) {
		gotoxy(0, i);
		printf("                                                                ");
	}
}

/*
	게임 화면에서 단어 입력 부 지우는 함수
	단어 입력 후 엔터키 누를 시 지우기 위함
*/
void clearPrompt() {
	gotoxy(0, 24); printf("                                 ");
}
