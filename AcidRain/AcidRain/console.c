#include "console.h"

void initialConsoleSetting() {
	system("title AcidRain"); // �ܼ� Ÿ��Ʋ ����
	setCursorType(NOCURSOR); // Ŀ�� �������� �ʵ��� ����
}

void setCursorType(CURSOR_TYPE c) { // Ŀ�� �������� �ʰ� ����
	CONSOLE_CURSOR_INFO curInfo;
	switch (c) {
	case NOCURSOR:
		curInfo.dwSize = 1;
		curInfo.bVisible = FALSE;
		break;
	case SOLIDCURSOR:
		curInfo.dwSize = 100;
		curInfo.bVisible = TRUE;
		break;
	case NORMALCURSOR:
		curInfo.dwSize = 20;
		curInfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}
