#include "console.h"

#define CURSOR_HIDE

void consoleSetting() { // 최초 콘솔 세팅 
	system("title Acid Rain"); // 콘솔 타이틀 변경
	system("mode con: cols=64 lines=27");

#ifdef CURSOR_HIDE
	setCursorType(NOCURSOR); // 커서 숨기기
#endif
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

void gotoxy(int x, int y) { // 커서 특정 좌표로 이동
	COORD cursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void printBorderLine() { // 경계선 출력
	gotoxy(0, 1); printf("===============================================================\n");
	gotoxy(0, 22); printf("===============================================================\n");
}

void printStatus() { // status값 출력
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

void printPrompt() { // 입력 창 출력
	gotoxy(0, 24);  printf("Input >>");
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