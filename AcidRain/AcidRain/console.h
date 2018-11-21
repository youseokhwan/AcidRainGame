#ifndef CONSOLE_H
#define CONSOLE_H

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

#define VERSION "v1.3.3"

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
void setCursorType(CURSOR_TYPE c); // Ŀ�� �����
void setColor(int colorNumber); // ��Ʈ ���� ����

struct _record* consoleSetting(struct _gameStatus* gameStatus); // ���� �ּܼ���
struct _settingValue {
	int hideCursorToggle;
	int dropSpeedToggle;
};

void printTitle(); // Ÿ��Ʋ ���
void printMenuList(); // �޴� ��� ���
void printRain(); // �� ���
void printOthers(); // ��Ÿ ���� ���
void printArrow(int* menuIndex); // ȭ��ǥ ���
void printMenu(int* menuIndex); // �޴� ���

int mainMenu(int* menuIndex); // Ű���� UX ���� �� �޴� ���ð� ��ȯ
void printHelp(); // ���� ���
void setting(struct _settingValue* settingValue, struct _gameStatus* gameStatus); // ����

void gotoxy(int x, int y); // Ŀ�� Ư�� ��ǥ�� �̵�

void printSingleBorderLine(int y); // rank, log ��� �� ��¥�� ��輱 ���
void printDoubleBorderLine(); // gameBoard���� �� ��¥�� ��輱 ���
void printStatus(struct _gameStatus* gameStatus); // status�� ���
void printPrompt(); // �Է� â ���
void clearStatus(); // status�� �����
void clearBoard(); // �ܾ� �����
void clearPrompt(); // �Է�â �����
void clearLog(); // �α�â �����

#endif
