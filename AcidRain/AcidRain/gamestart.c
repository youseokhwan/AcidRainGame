#include <stdio.h>
#include <conio.h>
#include <pthread.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "gamestart.h"

void gotoxy(int x, int y) {
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

void gameStart() {
	// ���������������� TEST ����������������
	printf("gameStart() �Լ��� ���������� �����\n");
	// ���������������� TEST ����������������

	// ��ü �ܾ� ����Ʈ ����
	char* wordList[50] = { "art", "able", "acid", "about", "air", "aim", "also", "ant", "arm", "army",
						"ball", "blue", "bag", "band", "beat", "beef", "belt", "bill", "bike", "boat",
						"cafe", "cake", "call", "camp", "camo", "care", "case", "cave", "cat", "chef",
						"data", "dark", "day", "deer", "deep", "dog", "door", "draw", "drum", "drug",
						"each", "easy", "echo", "edge", "egg", "evil", "even", "exam", "eye", "else" };

	// gameStatus ����
	struct _gameStatus gameStatus = { 5, 1, 0, 0, 0 };

	while (1) {
		system("cls");

		if (gameStatus.stage == 11) {
			gotoxy(0, 0); printf("============================================================\n");
			printf("��� ���������� Ŭ�����ϼ̽��ϴ�!!\n");
			gotoxy(0, 20); printf("============================================================\n");
			// ranking( ) ���� �Ѿ�� ��ƾ ¥����
			break;
		}

		// ���������������� ���� �������� �ܾ� �ʱ�ȭ ����������������
		struct word wordInCurrentStage[10];
		for (int i = 0; i < 10; i++) {
			wordInCurrentStage[i].word = wordList[rand() % 30]; // ��ü ����Ʈ���� ������ ���� ���� ���������� �� �ܾ�� �ʱ�ȭ
			for (int j = 0; j < i; j++) {
				if (strcmp(wordInCurrentStage[i].word, wordInCurrentStage[j].word) == 0) {
					i--;
					break;
				}
			}
		}
		for (int i = 0; i < 10; i++) {
			wordInCurrentStage[i].isPrint = 0;
			wordInCurrentStage[i].printCount = 1; // 1���� �����ؼ� 10�� �����ϸ� ���� ����
		}
		// ���������������� ���� �������� �ܾ� �ʱ�ȭ ����������������

		// ���������������� �������� ���� ���������������� // �̰� �ٽ� ������� �Բ� �Լ��� ��������
		gotoxy(0, 0); printf("============================================================\n");
		printf("%d�ܰ� �����մϴ�!\n", gameStatus.stage);
		gotoxy(0, 20); printf("============================================================\n");
		system("pause>nul");
		// ���������������� �������� ���� ����������������

	

		gameStatus.stage++; // �������� 1 ����
	}


}