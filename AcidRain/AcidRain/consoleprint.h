#ifndef __CONSOLEPRINT_H__
#define __CONSOLEPRINT_H__

#include <stdio.h>
#include <Windows.h>
#include "gamestart.h"

int printAndSelectMenu(); // �޴� ��� -> ������ �޴� ���� -> ������ �Լ��� �̵�
void printUpAndDownBorderLine(); // ��, �ϴ� �׵θ� ���
void clearBoard(); // ȭ�� �����
void printStatus(); // gameStatus( ) ���� ���

// ���������������� Ŀ�� ���� ����������������
void gotoxy(int x, int y); // �ֿܼ��� Ŀ�� �̵���Ű�� �Լ�

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void setCursorType(CURSOR_TYPE c);
// ���������������� Ŀ�� ���� ����������������

#endif