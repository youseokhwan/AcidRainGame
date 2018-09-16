#include <stdio.h>

void printMenu();

int main(void) {
	printMenu();

	return 0;
}

void printMenu() {
	int selectNumber;

	printf(">> Acid Rain\n");
	printf("1. 게임시작\n");
	printf("2. 랭킹\n");
	printf("3. 종료\n");
	printf(">> ");
	scanf("%d", &selectNumber);

	printf("선택한 메뉴: %d\n", selectNumber);
}