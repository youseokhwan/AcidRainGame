// AcidRain C console game. Made by youseokhwan.
// https://github.com/youseokhwan/AcidRainGame
// 18.10.25 v0.1 �⺻ Ʋ ����


#include "console.h"

int main(void) {
	initialConsoleSetting(); // �ܼ� ���ʼ���
	
	while (true) { // �޴� ��� �� �����Ͽ� ����
		int num = 0;
		
		system("cls");
		printf("Acid Rain\n");
		printf("1 ���ӽ���, 2 ��ŷ, 3 �α׺���, 4 ������\n");
		printf("���� >> ");
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
			printf("������ �����մϴ�...\n");
			exit(0);
		default:
			printf("�ٽ� �������ּ���.\n");
		}
	}
	
	return 0;
}