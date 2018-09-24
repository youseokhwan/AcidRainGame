// 본격 AcidRain 프로그래밍들어가기 전에 마지막 연습
// pthread 이용해서 상단에선 단어 출력하고
// 하단에선 유저가 타이핑하는 내용 보여지도록 만들기

// 2018.09.24 made by YouSeokHwan (https://github.com/youseokhwan)

#include <stdio.h>
#include <pthread.h>
#include <Windows.h>
#include <conio.h>

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void setcursortype(CURSOR_TYPE c); // 위 2개는 커서 컨트롤하기 위한 열거형과 함수

void gotoxy(int x, int y); // 커서를 이동시키는 함수, (0, 0)부터 (79, 24)까지만 가급적 사용
char getKey(); // 키 입력받기 위한 함수

void* printOnTopFunc(void* arg); // 상단에 문자 출력하는 함수(첫 번째 쓰레드)
void* printOnBottomFunc(void* arg); // 하단에 유저 타이핑 출력하는 함수(두 번째 쓰레드)


struct cursorLocation { // 커서의 위치정보 값 저장하는 cursorLocation 구조체
	int x;
	int y;
};

// ******* MAIN FUNCTION *******
int main(void) {
	setcursortype(NOCURSOR); // 커서 숨기기

	pthread_t printOnTop, printOnBottom; // pthread 선언
	int intTemp; // 쓰지는 않지만 pthread_join에 인자를 넣기위해 만든 변수

	int count = 0; // a 개수 저장하기 위한 변수이자 포인터가 참조할 곳을 만들어주는 변수
	int* voidPointerTemp = &count; // voidPointerTemp 이름을 잘못지었는데 귀찮아서 안바꿈

	printf("상단에는 문자를 출력하는 함수가 실행되고\n");
	printf("하단에는 유저가 입력을 할 수 있는 함수가 동시에 실행되는 쓰레드입니다.\n\n");
	system("pause");
	system("cls");

	pthread_create(&printOnTop, NULL, printOnTopFunc, (void*)voidPointerTemp); // 쓰레드 생성
	pthread_create(&printOnBottom, NULL, printOnBottomFunc, (void*)voidPointerTemp); // 쓰레드 생성

	pthread_join(printOnTop, (void**)&intTemp); // 쓰레드 해제
	pthread_join(printOnBottom, (void**)&intTemp); // 쓰레드 해제

	system("cls");
	printf("Main 함수 종료합니다.\n");
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
	printf("한글이랑 백스페이스는 구현 못했으니까 울면서 쓰세요. a 30개 출력되면 종료됩니다.\n");
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