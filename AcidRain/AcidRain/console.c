#include "console.h"

void initialConsoleSetting() {
	system("title Acid Rain"); // 콘솔 타이틀 변경
	system("mode con: cols=64 lines=27");

	setCursorType(NOCURSOR); // 커서 깜빡이지 않도록 설정
}

void gotoxy(int x, int y) { // 커서 특정 좌표로 이동
	COORD cursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
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

void printBorderLine() { // 경계선 출력
	gotoxy(0, 1); printf("===============================================================\n");
	gotoxy(0, 22); printf("===============================================================\n");
}

void clearBoard() { // 화면 지우기
	gotoxy(0, 0);
	printf("                                                                ");

	for (int i = 2; i <= 21; i++) {
		gotoxy(0, i);
		printf("                                                                ");
	}
}

void printStatus() { // gameStatus( ) 정보 출력
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

void printPrompt() { // 입력창 출력
	gotoxy(0, 24);  printf("Input >>");
}