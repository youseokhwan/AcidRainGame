#include "gamestart.h"
#include "consoleprint.h"

// ���������������� �����忡 ����� �Լ� ���� ����������������
void* topThreadFunc(void* arg) {
	int theSpeedOfWordDrop[MAX_STAGE] = { 1500, 1000, 900, 800, 750, 700, 650, 600, 550, 200 }; // �ܾ� �������� ���ǵ� ����
	int pulseCount = 0; // �ܾ� �������� �۾��� ����� Ƚ��
	gameStatus.correctInputCountInStage = 0; // ������ �ش� ������������ ���� ������ ����
	
	for (int i = 0; i < THE_NUMBER_OF_WORDS_IN_STAGE; i++) {
		wordInCurrentStage[i].x = (rand() % 60) + 2; // �ش� �ܾ��� ���� x�� ����
	}

	clearBoard(); // ȭ�� �����
	printStatus(); // ��������, ������, ���� ���
	printUpAndDownBorderLine(); // ��輱 ���
	gotoxy(0, 2);  printf("Stage %d START!!", gameStatus.stage);
	system("pause>nul");

	while (true) {
		clearBoard(); // ȭ�� �����
		printStatus(); // ��������, ������, ���� ���
		printUpAndDownBorderLine(); // ��輱 ���

		if (gameStatus.life == 0) { // ���� ����� 0�̸� ���� ���� �� ranking( ) ����
			gotoxy(0, 2); printf("Game Over!!\n");
			
			system("pause>nul");
			// ranking( ) ����
			break;
		}

		if (gameStatus.correctInputCountInStage == THE_NUMBER_OF_WORDS_IN_STAGE) { // �ܾ ��� �Է��ϸ� ���� ���������� �Ѿ
			gotoxy(0, 2); printf("%d �������� Ŭ����!!\n", gameStatus.stage);

			system("pause>nul");
			break;
		}

		//if (pulseCount % 2 == 0) {
		//	wordInCurrentStage[pulseCount/2].isPrint = true;
		//}
		wordInCurrentStage[pulseCount].isPrint = true;

		for (int i = 0; i < THE_NUMBER_OF_WORDS_IN_STAGE; i++) {
			if (wordInCurrentStage[i].isPrint == true) {
				gotoxy(wordInCurrentStage[i].x, wordInCurrentStage[i].y);
				printf("%s", wordInCurrentStage[i].word);
			}
		}

		for (int i = 0; i <= pulseCount; i++) {
			wordInCurrentStage[i].y++;

			if (wordInCurrentStage[i].y == 22) { // �ٴڿ� �����ϸ� isPrint ���� false�� �����ϰ�, life--;
				wordInCurrentStage[i].isPrint = false;
				gameStatus.life--;
			}
		}

		pulseCount++;

		Sleep(theSpeedOfWordDrop[gameStatus.stage-1]); // �ܾ��� ���ϼӵ� ������
	}

	return NULL;
}

void* bottomThreadFunc(void* arg) {
	//Sleep(200);
	//printf("bottomThread�� ���������� �����\n");

	//struct word* _word = (struct word*)arg;

	//for (int i = 0; i < THE_NUMBER_OF_WORDS_IN_STAGE; i++) {
	//	printf("%d\n", _word[i].printCount);
	//}

	//system("pause>nul");

	//return NULL;
}
// ���������������� �����忡 ����� �Լ� ���� ����������������

void gameStart() {
	// ��ü �ܾ� ����Ʈ ����
	char* wordList[THE_NUMBER_OF_WORDS] = { "art", "able", "acid", "about", "air", "aim", "also", "ant", "arm", "army",
						"ball", "blue", "bag", "band", "beat", "beef", "belt", "bill", "bike", "boat",
						"cafe", "cake", "call", "camp", "camo", "care", "case", "cave", "cat", "chef",
						"data", "dark", "day", "deer", "deep", "dog", "door", "draw", "drum", "drug",
						"each", "easy", "echo", "edge", "egg", "evil", "even", "exam", "eye", "else" }; // ���߿� ���� ��������� �ٽ� ����

	// gameStatus �ʱ�ȭ
	gameStatus.life = 5;
	gameStatus.score = 0;
	gameStatus.stage = 1;
	gameStatus.correctInputCount = 0;

	while (true) {
		system("cls");

		if (gameStatus.life == 0) {
			// ranking( ) ����

			break;
		}

		// ���������������� ��� �������� Ŭ�����ϸ� ��Ÿ���� ����  ����������������
		if (gameStatus.stage > MAX_STAGE) {
			printUpAndDownBorderLine();
			gotoxy(0, 2); printf("��� ���������� Ŭ�����ϼ̽��ϴ�!!\n");

			// ranking( ) ����

			break;
		}	
		// ���������������� ��� �������� Ŭ�����ϸ� ��Ÿ���� ���� ����������������

		// ���������������� ���� �������� �ܾ� �ʱ�ȭ ����������������
		for (int i = 0; i < THE_NUMBER_OF_WORDS_IN_STAGE; i++) {
			wordInCurrentStage[i].word = wordList[rand() % THE_NUMBER_OF_WORDS]; // ��ü ����Ʈ���� ������ ���� ���� ���������� �� �ܾ�� �ʱ�ȭ
			for (int j = 0; j < i; j++) {
				if (strcmp(wordInCurrentStage[i].word, wordInCurrentStage[j].word) == 0) {
					i--;
					break;
				}
			}
			wordInCurrentStage[i].isPrint = false;
			wordInCurrentStage[i].x = 0;
			wordInCurrentStage[i].y = 2;
		}
		// ���������������� ���� �������� �ܾ� �ʱ�ȭ ����������������

		// ���������������� ������ ȣ�� ����������������
		int intTemp = 0;
		void* voidPointerTemp = &intTemp;

		pthread_create(&topThread, NULL, topThreadFunc, (void*)voidPointerTemp); // topThread ����
		pthread_create(&bottomThread, NULL, bottomThreadFunc, (void*)voidPointerTemp); // bottomThread ����

		pthread_join(topThread, (void**)&intTemp); // topThread ����
		pthread_join(bottomThread, (void**)&bottomThread); // bottomThread ����
		// ���������������� ������ ȣ�� ����������������

		gameStatus.stage++; // �������� ����
	}

}