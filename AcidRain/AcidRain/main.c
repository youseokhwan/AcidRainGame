#include <stdio.h>

void printMenu();

int main(void) {
	printMenu();

	return 0;
}

void printMenu() {
	int selectNumber;

	printf(">> Acid Rain\n");
	printf("1. ���ӽ���\n");
	printf("2. ��ŷ\n");
	printf("3. ����\n");
	printf(">> ");
	scanf("%d", &selectNumber);

	printf("������ �޴�: %d\n", selectNumber);
}