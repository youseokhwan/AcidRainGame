// AcidRain C console game. Made by youseokhwan.
// https://github.com/youseokhwan/AcidRainGame
// 18.10.25 ~ 개발 중

#include "console.h"

int main(void) {
	consoleSetting(); // 최초 콘솔세팅

	while (true) { // 메뉴 출력 및 선택하여 진행
		system("cls");

		int selectNum = 0;

		printf("Acid Rain\n");
		printf("1 게임시작\n");
		printf("2 랭킹\n");
		printf("3 진행로그\n");
		printf("4 끝내기\n");
		printf("선택 >> ");
		scanf_s("%d", &selectNum);

		switch (selectNum) {
		case 1:
			gameStart();
			break;
		case 2:
			rankingFromMenu();
			break;
		case 3:
			showLog();
			break;
		case 4:
			system("cls");
			printf("게임을 종료합니다.\n");
			exit(0);
		default:
			system("cls");
			scanf("%*s");

			printf("잘못된 입력입니다.\n");
			system("pause>nul");
		}
	}//while(true)

	return 0;
}//int main(void)