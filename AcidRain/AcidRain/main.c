// AcidRain C console game. Made by youseokhwan.
// https://github.com/youseokhwan/AcidRainGame
// 18.11.18 v1.0 기능구현 완료
// 18.11.20 v1.1 UI 업데이트
// 18.11.21 v1.2 단어 간격 조정 및 도움말 업데이트
// 18.11.21 v1.3 개발자 설정 업데이트
// 18.11.21 v1.3.1 dropSpeed 관련 hotfix, Use safety function
// 18.11.21 v1.3.2 log 페이지 업데이트
// 18.11.22 v1.3.3 도움말 GUI 업데이트

#include "console.h"

int main(int argc, char* argv[]) {
	//struct 선언부
	struct _gameStatus gs;
	struct _gameStatus* gameStatus = &gs;

	struct _record* record = consoleSetting(gameStatus); // 최초 콘솔세팅

	struct _settingValue sv = { 1, 0 }; // 초기 설정 값
	struct _settingValue* settingValue = &sv;
	
	addLog("start a program\n", false);

	int mi = 0;
	int* menuIndex = &mi;

	while (true) {
		int userSelect = mainMenu(menuIndex);

		switch (userSelect) {
		case 0:
			gameStart(record, gameStatus);
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
			setting(settingValue, gameStatus);
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
