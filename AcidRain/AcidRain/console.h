#ifndef CONSOLE_H
#define CONSOLE_H

#define _CRT_SECURE_NO_WARNINGS

#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>

#include "game.h"
#include "log.h"
#include "ranking.h"

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void setCursorType(CURSOR_TYPE c); // 커서 깜빡이지 않게 설정

void consoleSetting(); // 최초 콘솔세팅

void gotoxy(int x, int y); // 커서 특정 좌표로 이동

void printBorderLine(); // 경계선 출력
void printStatus(); // status값 출력
void printPrompt(); // 입력 창 출력

void clearStatus(); // status값 지우기
void clearBoard(); // 단어 지우기
void clearPrompt(); // 입력창 지우기

#endif