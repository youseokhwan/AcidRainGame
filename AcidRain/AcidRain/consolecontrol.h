#ifndef __CONSOLECONTROL_H__
#define __CONSOLECONTROL_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include <pthread.h>
#include "gamestart.h"
#include "ranking.h"

#define BACKSPACE_KEY 8
#define ENTER_KEY 13
#define SPACEBAR_KEY 32
#define UP_KEY 72
#define DOWN_KEY 80

int printAndSelectMenu(); // 최초 메뉴 출력 및 유저입력
//void selectMenu();

// ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ topThreadFunc에서 사용 ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
void printBorderLine(); // 경계선 출력
void clearBoard(); // 화면 지우기
void printStatus(); // gameStatus( ) 정보 출력
void printPrompt(); // 유저 입력칸에 프롬프트 출력
// ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ topThreadFunc에서 사용 ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲


// ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ bottomThreadFunc에서 사용 ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
// ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ bottomThreadFunc에서 사용 ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲


// ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ 커서 관련 ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
void gotoxy(int x, int y); // // 커서 특정 좌표로 이동

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void setCursorType(CURSOR_TYPE c); // 커서 깜빡이지 않게 설정
// ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ 커서 관련 ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲

#endif