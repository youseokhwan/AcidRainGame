#ifndef __CONSOLEPRINT_H__
#define __CONSOLEPRINT_H__

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "gamestart.h"

int printAndSelectMenu(); // ���� �޴� ��� �� �����Է�

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