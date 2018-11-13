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
void setCursorType(CURSOR_TYPE c); // Ŀ�� �������� �ʰ� ����

void consoleSetting(); // ���� �ּܼ���

void gotoxy(int x, int y); // Ŀ�� Ư�� ��ǥ�� �̵�

void printBorderLine(); // ��輱 ���
void printStatus(); // status�� ���
void printPrompt(); // �Է� â ���

void clearStatus(); // status�� �����
void clearBoard(); // �ܾ� �����
void clearPrompt(); // �Է�â �����

#endif