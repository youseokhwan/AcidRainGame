#ifndef __CONSOLEPRINT_H__
#define __CONSOLEPRINT_H__

#include <stdio.h>
#include <Windows.h>

int printAndSelectMenu(); // �޴� ��� -> ������ �޴� ���� -> ������ �Լ��� �̵�

// ���������������� Ŀ�� ���� ����������������
typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void setcursortype(CURSOR_TYPE c);
// ���������������� Ŀ�� ���� ����������������

#endif