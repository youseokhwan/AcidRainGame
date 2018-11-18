// AcidRain C console game. Made by youseokhwan.
// https://github.com/youseokhwan/AcidRainGame
// 18.10.25 ~ 개발 중

#include "console.h"

int main(int argc, char* argv[]) {
	struct _record* record = consoleSetting(); // 최초 콘솔세팅
	addLog("start a program\n", false);

	while (true) { // 메뉴 출력 및 선택하여 진행
		system("cls");

		char selectNum[INPUT_BUFFER] = "";

		gotoxy(0, 0); printf("<< Acid Rain>>");
		gotoxy(0, 2); printf("1 게임시작\n");
		gotoxy(0, 3); printf("2 랭킹\n");
		gotoxy(0, 4); printf("3 진행로그\n");
		gotoxy(0, 5); printf("4 끝내기\n");
		gotoxy(0, 7); printf("선택 >> ");
		scanf_s("%s", selectNum, INPUT_BUFFER);

		if (selectNum[1] != (char)NULL) { // 두 글자 이상 입력했을 시 재입력하도록 유도
			selectNum[0] = 0;
		}

		switch (selectNum[0]) {
		case '1':
			gameStart(record);
			break;
		case '2':
			rankingFromMenu(record);
			break;
		case '3':
			showLog();
			break;
		case '4':
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
	}//while(true)

	return 0;
}//int main(void)