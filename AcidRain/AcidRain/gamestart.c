#include "gamestart.h"

void gotoxy(int x, int y) {
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

// ���������������� �����忡 ����� �Լ� ���� ����������������
void* topThreadFunc(void* arg) {
	printf("topThread�� ���������� �����\n");

	struct word* _word = (struct word*)arg;
	
	for (int i = 0; i < NUMBER_OF_WORD_IN_CURRENT_STAGE; i++) {
		printf("%s\n", _word[i].word);
	}

	return NULL;
}

void* bottomThreadFunc(void* arg) {
	Sleep(200);
	printf("bottomThread�� ���������� �����\n");

	struct word* _word = (struct word*)arg;

	for (int i = 0; i < NUMBER_OF_WORD_IN_CURRENT_STAGE; i++) {
		printf("%d\n", _word[i].printCount);
	}

	system("pause>nul");

	return NULL;
}
// ���������������� �����忡 ����� �Լ� ���� ����������������

void gameStart() {
	// TEST
	printf("gameStart() �Լ��� ���������� �����\n");


	// ��ü �ܾ� ����Ʈ ����
	char* wordList[NUMBER_OF_WORD_LIST] = { "art", "able", "acid", "about", "air", "aim", "also", "ant", "arm", "army",
						"ball", "blue", "bag", "band", "beat", "beef", "belt", "bill", "bike", "boat",
						"cafe", "cake", "call", "camp", "camo", "care", "case", "cave", "cat", "chef",
						"data", "dark", "day", "deer", "deep", "dog", "door", "draw", "drum", "drug",
						"each", "easy", "echo", "edge", "egg", "evil", "even", "exam", "eye", "else" }; // ���߿� ���� ��������� �ٽ� ����

	// gameStatus ����
	struct _gameStatus gameStatus = { 5, 1, 0, 0 };

	while (1) {
		system("cls");

		// ���������������� ��� �������� Ŭ�����ϸ� ��Ÿ���� ����  ����������������
		if (gameStatus.stage > MAX_STAGE) {
			gotoxy(0, 0); printf("============================================================\n");
			printf("��� ���������� Ŭ�����ϼ̽��ϴ�!!\n");
			gotoxy(0, 20); printf("============================================================\n");
			// ranking( ) ���� �Ѿ�� ��ƾ ¥����
			break;
		}
		// ���������������� ��� �������� Ŭ�����ϸ� ��Ÿ���� ���� ����������������


		// ���������������� ���� �������� �ܾ� �ʱ�ȭ ����������������
		struct word wordInCurrentStage[NUMBER_OF_WORD_IN_CURRENT_STAGE];
		for (int i = 0; i < NUMBER_OF_WORD_IN_CURRENT_STAGE; i++) {
			wordInCurrentStage[i].word = wordList[rand() % NUMBER_OF_WORD_LIST]; // ��ü ����Ʈ���� ������ ���� ���� ���������� �� �ܾ�� �ʱ�ȭ
			for (int j = 0; j < i; j++) {
				if (strcmp(wordInCurrentStage[i].word, wordInCurrentStage[j].word) == 0) {
					i--;
					break;
				}
			}
			wordInCurrentStage[i].isPrint = 0;
			wordInCurrentStage[i].printCount = 1; // 1���� �����ؼ� 10�� �����ϸ� ���� ����
			wordInCurrentStage[i].x = 0;
			wordInCurrentStage[i].y = 0;
		}
		// ���������������� ���� �������� �ܾ� �ʱ�ȭ ����������������


		/* // ���� �׽�Ʈ ����
		// ���������������� �������� ���� ���������������� // �̰� �ٽ� ������� �Բ� �Լ��� ��������
		gotoxy(0, 0); printf("============================================================\n");
		printf("%d�ܰ� �����մϴ�!\n", gameStatus.stage);
		gotoxy(0, 20); printf("============================================================\n");
		system("pause>nul");
		// ���������������� �������� ���� ����������������
		*/


		// ���������������� ������ ȣ�� ����������������
		intTemp = 0;

		pthread_create(&topThread, NULL, topThreadFunc, (void*)wordInCurrentStage); // topThread ����
		pthread_create(&bottomThread, NULL, bottomThreadFunc, (void*)wordInCurrentStage); // bottomThread ����

		pthread_join(topThread, (void**)&intTemp); // topThread ����
		pthread_join(bottomThread, (void**)&bottomThread); // bottomThread ����
		// ���������������� ������ ȣ�� ����������������


		gameStatus.stage++; // �������� 1
	}

}