#ifndef __CONSOLEPRINT_H__
#define __CONSOLEPRINT_H__

#include <stdio.h>
#include <Windows.h>
#include "gamestart.h"

int printAndSelectMenu(); // 메뉴 출력 -> 유저의 메뉴 선택 -> 선택한 함수로 이동
void printUpAndDownBorderLine(); // 상, 하단 테두리 출력
void clearBoard(); // 화면 지우기
void printStatus(); // gameStatus( ) 정보 출력

// ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ 커서 관련 ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
void gotoxy(int x, int y); // 콘솔에서 커서 이동시키는 함수

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void setCursorType(CURSOR_TYPE c);
// ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ 커서 관련 ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲

#endif