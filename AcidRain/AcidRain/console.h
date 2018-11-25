#ifndef CONSOLE_H
#define CONSOLE_H

#pragma comment(lib,"winmm.lib")
/*
	<< #define ISSUE >>
	선언한 이유: 여러 PC에서 테스트한 결과 _getch()에서 문제가 생기는 PC와 그렇지 않은 PC 존재함(원인 파악 못함)
	만약 두 번 눌러야 인식이 된다면 이 ISSUE를 주석 해제하고 실행할 것
*/
//#define ISSUE

#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>
#include <mmsystem.h>

#include "game.h"
#include "log.h"
#include "ranking.h"

#define VERSION "v1.3.5" // 현재 버전 정보

#define DELAY 7

#define DARK_GREEN 2
#define DARK_CYAN 3
#define DARK_YELLOW 6
#define GRAY 8
#define BLUE 9
#define GREEN 10
#define CYAN 11
#define RED 12
#define MAGENTA 13
#define YELLOW 14
#define WHITE 15

#define SOUND_FAIL "dataFile\\sound\\fail.wav"
#define SOUND_SELECT "dataFile\\sound\\select.wav"
#define SOUND_CORRECT "dataFile\\sound\\correct.wav"
#define SOUND_ALL_CLEAR "dataFile\\sound\\allClear.wav"
#define SOUND_INCORRECT "dataFile\\sound\\incorrect.wav"
#define SOUND_STAGE_CLEAR "dataFile\\sound\\stageClear.wav"

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void setCursorType(CURSOR_TYPE c);
void setColor(int colorNumber);

void consoleSetting(struct _gameStatus* gameStatus);
struct _settingValue {
	int hideCursorToggle;
	int dropSpeedToggle;
};

void printTitle();
void printMenuList();
void printRain();
void printOthers();
void printMenuArrow(int* menuIndex);
void printMenu(int* menuIndex);

int mainMenu(int* menuIndex);
void printHelp();
void setting(struct _settingValue* settingValue, struct _gameStatus* gameStatus);

void gotoxy(int x, int y);

void printSingleBorderLine(int y);
void printDoubleBorderLine();
void printStatus(struct _gameStatus* gameStatus);
void printPrompt();
void clearStatus();
void clearBoard();
void clearPrompt();

#endif
