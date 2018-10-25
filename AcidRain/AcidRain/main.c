// AcidRain C console game. Made by youseokhwan.
// https://github.com/youseokhwan/AcidRainGame
// 18.10.25 v0.1 기본 틀 구성


#include "console.h"

int main(void) {
	initialConsoleSetting(); // 콘솔 최초설정
	
	while (true) { // 메뉴 출력 및 선택하여 진행
		int num = 0;
		
		system("cls");
		printf("Acid Rain\n");
		printf("1 게임시작, 2 랭킹, 3 로그보기, 4 끝내기\n");
		printf("선택 >> ");
		scanf_s("%d", &num);

		switch (num) {
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
			printf("게임을 종료합니다...\n");
			exit(0);
		default:
			printf("다시 선택해주세요.\n");
		}
	}
	
	return 0;
}