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

#define SOUND_FAIL "sound\\fail.wav"
#define SOUND_SELECT "sound\\select.wav"
#define SOUND_CORRECT "sound\\correct.wav"
#define SOUND_ALL_CLEAR "sound\\allClear.wav"
#define SOUND_INCORRECT "sound\\incorrect.wav"
#define SOUND_STAGE_CLEAR "sound\\stageClear.wav"

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void setCursorType(CURSOR_TYPE c); // 커서 숨기기

struct _record* consoleSetting(); // 최초 콘솔세팅

void gotoxy(int x, int y); // 커서 특정 좌표로 이동

void printSingleBorderLine(); // rank, log 등에서 한 줄짜리 경계선 출력
void printDoubleBorderLine(); // gameBoard에서 두 줄짜리 경계선 출력
void printStatus(struct _gameStatus* gameStatus); // status값 출력
void printPrompt(); // 입력 창 출력
void clearStatus(); // status값 지우기
void clearBoard(); // 단어 지우기
void clearPrompt(); // 입력창 지우기

#endif