// ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
// 18.09.16 ~ 
// made by youseokhwan(https://github.com/youseokhwan/AcidRainGame)
// ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲

#include "consoleprint.h"
#include "gamestart.h"
#include "ranking.h"

// ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ Main Function  ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
int main(void) {
	setCursorType(NOCURSOR); // 커서 깜빡이지 않게하는 함수
	srand(time(NULL));

	int numberSelectedByUser = printAndSelectMenu();

	while (true) {
		switch (numberSelectedByUser) {
		case 1:
			gameStart(); // gameStart.c
			break;
		case 2:
			ranking(); // ranking.c
			break;
		case 3:
			printf("게임을 종료합니다.\n");
			exit(0);
			// break;
		default:
			printf("잘못선택하셨습니다. 다시 선택해주세요.\n");
		}

		break;
	}

	return 0;
}
// ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ Main Function ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲