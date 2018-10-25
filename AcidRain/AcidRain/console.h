#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>

#include "gamestart.h"
#include "ranking.h"
#include "log.h"

#define BACKSPACE_KEY 8
#define ENTER_KEY 13
#define SPACEBAR_KEY 32
#define UP_KEY 72
#define DOWN_KEY 80

void initialConsoleSetting();

void gotoxy(int x, int y);

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void setCursorType(CURSOR_TYPE c);

void printBorderLine();
void clearBoard();
void printStatus();
void printPrompt();

#endif