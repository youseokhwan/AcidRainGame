// ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
// 18.09.16 v0.0 프로젝트 시작
// 18.10.07 v1.0 gamestart.c 구현 완료
// 18.10.07 v1.1 버퍼 사이즈 수정
// 18.10.09 v1.2 입력버퍼 오류 수정
// made by youseokhwan(https://github.com/youseokhwan/AcidRainGame)
// ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲

#include "consolecontrol.h"

// ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ Main Function ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
int main(void) {
	system("title Acid Rain (A simple word typing game)"); // 콘솔 타이틀 변경

	// ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ 커서 표시할지 말지 결정하는 임시 구간(테스트용) ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
	printf("커서를 표시할까요?\n");
	printf("1. 표시안함(권장)\n");
	printf("2. 표시(테스트할때만 사용)\n>> ");
	int cursorUserSelect = 0;
	scanf_s("%d", &cursorUserSelect);
	fflush(stdin);

	if (cursorUserSelect == 1) {
		setCursorType(NOCURSOR); // 커서 깜빡이지 않게하는 함수
	}

	system("cls");
	// ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ 커서 표시할지 말지 결정하는 임시 구간(테스트용) ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
	
	//setCursorType(NOCURSOR); // 커서 깜빡이지 않게하는 함수

	selectMenu();

	//int numberSelectedByUser = printAndSelectMenu();

	//while (true) {
	//	if (numberSelectedByUser == 1) {
	//		gameStart(); // gameStart.c
	//	}
	//	else if (numberSelectedByUser == 2) {
	//		enterRankingFromMenu(); // ranking.c
	//	}
	//	else if (numberSelectedByUser == 3) {
	//		printf("Good Bye :)\n");
	//		system("pause>nul");
	//		exit(0);
	//	}
	//	else {
	//		printf("That's the wrong input!\n");
	//		printf("Try again, please\n");
	//		system("pause>nul");
	//	}

	//	system("cls");
	//	numberSelectedByUser = printAndSelectMenu();
	//}

	return 0;
}
// ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ Main Function ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲