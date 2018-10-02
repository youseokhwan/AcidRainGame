#ifndef __CONSOLEPRINT_H__
#define __CONSOLEPRINT_H__

#include <stdio.h>
#include <Windows.h>

int printAndSelectMenu(); // 메뉴 출력 -> 유저의 메뉴 선택 -> 선택한 함수로 이동

// ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ 커서 관련 ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void setcursortype(CURSOR_TYPE c);
// ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ 커서 관련 ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲

#endif