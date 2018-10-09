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

int printAndSelectMenu(); // ���� �޴� ��� �� �����Է�
//void selectMenu();

// ���������������� topThreadFunc���� ��� ����������������
void printBorderLine(); // ��輱 ���
void clearBoard(); // ȭ�� �����
void printStatus(); // gameStatus( ) ���� ���
void printPrompt(); // ���� �Է�ĭ�� ������Ʈ ���
// ���������������� topThreadFunc���� ��� ����������������


// ���������������� bottomThreadFunc���� ��� ����������������
// ���������������� bottomThreadFunc���� ��� ����������������


// ���������������� Ŀ�� ���� ����������������
void gotoxy(int x, int y); // // Ŀ�� Ư�� ��ǥ�� �̵�

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void setCursorType(CURSOR_TYPE c); // Ŀ�� �������� �ʰ� ����
// ���������������� Ŀ�� ���� ����������������

#endif