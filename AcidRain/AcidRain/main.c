// ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
// 18.09.16 v0.0 프로젝트 시작
// 18.10.07 v1.0 gamestart.c 구현 완료
// made by youseokhwan(https://github.com/youseokhwan/AcidRainGame)
// ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲

#include "consoleprint.h"
#include "gamestart.h"
#include "ranking.h"

// ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ Main Function  ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
int main(void) {
	system("title Acid Rain (A simple word typing game)"); // 콘솔 타이틀 변경
	setCursorType(NOCURSOR); // 커서 깜빡이지 않게하는 함수

	int numberSelectedByUser = printAndSelectMenu();

	while (true) {
		switch (numberSelectedByUser) { // 나중에 키보드 입력으로 바꾸기?
		case 1:
			gameStart(); // gameStart.c
			break;
		case 2:
			ranking(); // ranking.c
			break;
		case 3:
			printf("게임을 종료합니다.\n");
			system("pause>nul");
			exit(0);
		default:
			printf("잘못선택하셨습니다. 다시 선택해주세요.\n");
			system("pause>nul");
		}

		system("cls");
		numberSelectedByUser = printAndSelectMenu();
	}

	return 0;
}
// ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ Main Function ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲