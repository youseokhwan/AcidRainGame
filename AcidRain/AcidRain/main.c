// AcidRain C console game. Made by youseokhwan.
// https://github.com/youseokhwan/AcidRainGame
// 18.10.25 v0.1 �⺻ Ʋ ����

#include "console.h"

int main(void) {
	initialConsoleSetting(); // �ܼ� ���ʼ���
	
	while (true) { // �޴� ��� �� �����Ͽ� ����
		system("cls");

		int selectNum = 0;
		
		printf("Acid Rain\n");
		printf("1 ���ӽ���\n");
		printf("2 ��ŷ\n");
		printf("3 ����α�\n");
		printf("4 ������\n");
		printf("���� >> ");
		scanf_s("%d", &selectNum); fflush(stdin);

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
			printf("������ �����մϴ�.\n");
			exit(0);
		default:
			printf("�ٽ� �������ּ���.\n");
		}
	}
	
	return 0;
}