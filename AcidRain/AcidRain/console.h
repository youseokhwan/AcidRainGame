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
void setCursorType(CURSOR_TYPE c); // Ŀ�� �����

struct _record* consoleSetting(); // ���� �ּܼ���

void gotoxy(int x, int y); // Ŀ�� Ư�� ��ǥ�� �̵�

void printSingleBorderLine(); // rank, log ��� �� ��¥�� ��輱 ���
void printDoubleBorderLine(); // gameBoard���� �� ��¥�� ��輱 ���
void printStatus(struct _gameStatus* gameStatus); // status�� ���
void printPrompt(); // �Է� â ���
void clearStatus(); // status�� �����
void clearBoard(); // �ܾ� �����
void clearPrompt(); // �Է�â �����

#endif