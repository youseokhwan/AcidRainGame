// AcidRain C console game. Made by youseokhwan.
// https://github.com/youseokhwan/AcidRainGame
// 18.10.25 ~ 개발 중
// 18.11.18 v1.0
// 18.11.20 v1.1 UI 업데이트

#include "console.h"

int main(int argc, char* argv[]) {
	struct _record* record = consoleSetting(); // 최초 콘솔세팅
	addLog("start a program\n", false);

	int mi = 0;
	int* menuIndex = &mi;

	while (true) {
		int userSelect = mainMenu(menuIndex);

		switch (userSelect) {
		case 0:
			gameStart(record);
			break;
		case 1:
			rankingFromMenu(record);
			break;
		case 2:
			printHelp();
			break;
		case 3:
			showLog();
			break;
		case 4:
			setting();
			break;
		case 5:
			system("cls");
			gotoxy(0, 0); printf("※ 게임을 종료합니다.\n");
			gotoxy(0, 2);

			addLog("end a program\n", false);
			free(record); // 동적 할당한 메모리 반환(console.c 참조)
			exit(0);
		default:
			gotoxy(0, 9); printf("※ 잘못된 입력입니다.");
			system("pause>nul");
		}
	}

	return 0;
}//int main(void)
