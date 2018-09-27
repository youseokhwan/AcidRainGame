#ifndef __ACIDRAIN_H__
#define __ACIDRAIN_H__

int printAndSelectMenu(); // 메뉴 출력 -> 유저의 메뉴 선택 -> 선택한 함수로 이동

// ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ 커서 관련 ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;

void setcursortype(CURSOR_TYPE c) {
	CONSOLE_CURSOR_INFO CurInfo;
	switch (c) {
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = FALSE;
		break;
	case SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = TRUE;
		break;
	case NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}
// ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ 커서 관련 ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲

#endif