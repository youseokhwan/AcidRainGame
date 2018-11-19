#ifndef CONSOLE_H
#define CONSOLE_H

#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib,"winmm.lib")

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

#define SOUND_FAIL "dataFile\\sound\\fail.wav"
#define SOUND_SELECT "dataFile\\sound\\select.wav"
#define SOUND_CORRECT "dataFile\\sound\\correct.wav"
#define SOUND_ALL_CLEAR "dataFile\\sound\\allClear.wav"
#define SOUND_INCORRECT "dataFile\\sound\\incorrect.wav"
#define SOUND_STAGE_CLEAR "dataFile\\sound\\stageClear.wav"

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void setCursorType(CURSOR_TYPE c); // 커서 숨기기

struct _record* consoleSetting(); // 최초 콘솔세팅

void printMenu(int* menuIndex); // 메뉴 출력
int mainMenu(int* menuIndex); // 키보드 UX 정의 및 메뉴 선택값 반환
void printHelp(); // 도움말 출력
void setting(); // 설정

void gotoxy(int x, int y); // 커서 특정 좌표로 이동

void printSingleBorderLine(); // rank, log 등에서 한 줄짜리 경계선 출력
void printDoubleBorderLine(); // gameBoard에서 두 줄짜리 경계선 출력
void printStatus(struct _gameStatus* gameStatus); // status값 출력
void printPrompt(); // 입력 창 출력
void clearStatus(); // status값 지우기
void clearBoard(); // 단어 지우기
void clearPrompt(); // 입력창 지우기

#endif