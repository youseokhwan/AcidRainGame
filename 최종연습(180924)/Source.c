// ���� AcidRain ���α׷��ֵ��� ���� ������ ����
// pthread �̿��ؼ� ��ܿ��� �ܾ� ����ϰ�
// �ϴܿ��� ������ Ÿ�����ϴ� ���� ���������� �����

// 2018.09.24 made by YouSeokHwan (https://github.com/youseokhwan)

#include <stdio.h>
#include <pthread.h>
#include <Windows.h>
#include <conio.h>

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void setcursortype(CURSOR_TYPE c); // �� 2���� Ŀ�� ��Ʈ���ϱ� ���� �������� �Լ�

void gotoxy(int x, int y); // Ŀ���� �̵���Ű�� �Լ�, (0, 0)���� (79, 24)������ ������ ���
char getKey(); // Ű �Է¹ޱ� ���� �Լ�

void* printOnTopFunc(void* arg); // ��ܿ� ���� ����ϴ� �Լ�(ù ��° ������)
void* printOnBottomFunc(void* arg); // �ϴܿ� ���� Ÿ���� ����ϴ� �Լ�(�� ��° ������)


struct cursorLocation { // Ŀ���� ��ġ���� �� �����ϴ� cursorLocation ����ü
	int x;
	int y;
};

// ******* MAIN FUNCTION *******
int main(void) {
	setcursortype(NOCURSOR); // Ŀ�� �����

	pthread_t printOnTop, printOnBottom; // pthread ����
	int intTemp; // ������ ������ pthread_join�� ���ڸ� �ֱ����� ���� ����

	int count = 0; // a ���� �����ϱ� ���� �������� �����Ͱ� ������ ���� ������ִ� ����
	int* voidPointerTemp = &count; // voidPointerTemp �̸��� �߸������µ� �����Ƽ� �ȹٲ�

	printf("��ܿ��� ���ڸ� ����ϴ� �Լ��� ����ǰ�\n");
	printf("�ϴܿ��� ������ �Է��� �� �� �ִ� �Լ��� ���ÿ� ����Ǵ� �������Դϴ�.\n\n");
	system("pause");
	system("cls");

	pthread_create(&printOnTop, NULL, printOnTopFunc, (void*)voidPointerTemp); // ������ ����
	pthread_create(&printOnBottom, NULL, printOnBottomFunc, (void*)voidPointerTemp); // ������ ����

	pthread_join(printOnTop, (void**)&intTemp); // ������ ����
	pthread_join(printOnBottom, (void**)&intTemp); // ������ ����

	system("cls");
	printf("Main �Լ� �����մϴ�.\n");
	system("pause");

	return 0;
}
// ******* MAIN FUNCTION *******

void setcursortype(CURSOR_TYPE c) {
	CONSOLE_CURSOR_INFO CurInfo;
	switch (c) {
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = FALSE;
		break;
	case SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = TRUE;
		break;
	case NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

void gotoxy(int x, int y) {
	COORD CursurPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursurPosition);
}

char getKey() {
	if (_kbhit()) {
		return _getch();
	}

	return '\0';
}

void* printOnTopFunc(void* arg) {
	struct cursorLocation topCursorLocation;
	topCursorLocation.x = 0;
	topCursorLocation.y = 0;

	int* aCount = (int*)arg;

	Sleep(500);

	while (1) {
		if (*aCount > 29) {
			break;
		}
		gotoxy(topCursorLocation.x, topCursorLocation.y);
		printf("a ");
		(*aCount)++;

		topCursorLocation.x += 2;
		if (topCursorLocation.x > 9) {
			topCursorLocation.x = 0;
			topCursorLocation.y++;
		}

		Sleep(500);
	}

	return NULL;
}

void* printOnBottomFunc(void* arg) {
	struct cursorLocation bottomCursorLocation;
	bottomCursorLocation.x = 0;
	bottomCursorLocation.y = 19;

	int* aCount = (int*)arg;
	char key;

	gotoxy(bottomCursorLocation.x, bottomCursorLocation.y++);
	printf("�ѱ��̶� �齺���̽��� ���� �������ϱ� ��鼭 ������. a 30�� ��µǸ� ����˴ϴ�.\n");
	printf("input >> ");
	bottomCursorLocation.x += 9;

	while (1) {
		if (*aCount > 29) {
			break;
		}

		key = getKey();
		if (key != '\0') {
			gotoxy(bottomCursorLocation.x++, bottomCursorLocation.y);
			printf("%c", key);
			if (bottomCursorLocation.x > 49) {
				bottomCursorLocation.x = 9;
				bottomCursorLocation.y++;
			}
		}
	}

	return NULL;
}