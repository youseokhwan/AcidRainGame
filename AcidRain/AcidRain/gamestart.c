#include "gamestart.h"

// ���������������� �����忡 ����� �Լ� ���� ����������������
void* topThreadFunc(void* arg) {
	//int theSpeedOfWordDrop[MAX_STAGE] = { 1000, 700, 650, 600, 550, 500, 450, 400, 350, 300 }; // �ܾ� �������� ���ǵ� ����
	int theSpeedOfWordDrop[MAX_STAGE] = { 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 }; // �ܾ� �������� ���ǵ� ����

	gameStatus.isPrintCount = 0;
	gameStatus.pulseCount = 0; // �ܾ� �������� �۾��� ����� Ƚ��
	gameStatus.correctAnswerCount = 0; // ���� ������������ ���� �Է��� Ƚ�� 0���� �ʱ�ȭ
	
	// ���� ���
	clearBoard(); // ȭ�� �����
	printStatus(); // ��������, ������, ���� ���
	printBorderLine(); // ��輱 ���
	printPrompt(); // ���� �Է�â ���

	gotoxy(0, 2); printf("Stage %d START!!", gameStatus.stage);
	system("pause>nul");

	while (true) {
		clearBoard(); // ȭ�� �����
		printStatus(); // ��������, ������, ���� ���
		printBorderLine(); // ��輱 ���
		printPrompt(); // ���� �Է�â ���

		if (gameStatus.life == 0) { // ���� ����� 0�̸� ���� ���� �� ranking( ) ����		
			printf("������0 �̿��� �ɸ�");

			gotoxy(0, 2); printf("Game Over!!\n");
			gotoxy(0, 3); printf("Completed Stage: %d / Final Score: %d", gameStatus.stage-1, gameStatus.score);
			system("pause>nul");
			system("pause>nul");
			system("pause>nul");

			break;
		}

		if (gameStatus.correctAnswerCount == THE_NUMBER_OF_WORDS_IN_STAGE) { // �ܾ ��� �Է��ϸ� ���� ���������� �Ѿ

			printf("10�� �� ���缭 �ɸ�\n");
			printf("%d", gameStatus.correctAnswerCount);

			gameStatus.score += gameStatus.stage * 100; // Ŭ���� �� ��������*100 ��ŭ ���� ����
			gotoxy(0, 2); printf("Stage %d Clear!!\n", gameStatus.stage);
			gameStatus.stage++;
			system("pause>nul");

			break;
		}

		// (�ܾ� �Է� �� ������ �� && ���� �ʾ��� ��)�� ���� ����
		for (int i = 0; i < THE_NUMBER_OF_WORDS_IN_STAGE; i++) {
			if (wordInCurrentStage[i].isPrint == false) {
				gameStatus.isPrintCount++;
			}
		}

		if (gameStatus.pulseCount > 10) { // �ܾ� 10���� ��� ��µ� ����
			if (gameStatus.isPrintCount == THE_NUMBER_OF_WORDS_IN_STAGE) {
				gameStatus.score += gameStatus.stage * 100; // Ŭ���� �� ��������*100 ��ŭ ���� ����
				gotoxy(0, 2); printf("Stage %d Clear!!\n", gameStatus.stage);
				gameStatus.stage++;
				system("pause>nul");

				break;
			}
			else {
				gameStatus.isPrintCount = 0;
			}
		}

		wordInCurrentStage[gameStatus.pulseCount].isPrint = true; // �ܾ� �ϳ��� isPrint�� true�� ����

		for (int i = 0; i < THE_NUMBER_OF_WORDS_IN_STAGE; i++) { // isPrint���� true�� �ܾ� ���
			if (wordInCurrentStage[i].isPrint == true) {
				gotoxy(wordInCurrentStage[i].x, wordInCurrentStage[i].y);
				printf("%s", wordInCurrentStage[i].word);
			}
		}

		for (int i = 0; i <= gameStatus.pulseCount; i++) { // ��µ� �ܾ�� y�� ++
			wordInCurrentStage[i].y++;
		}

		for (int i = 0; i < THE_NUMBER_OF_WORDS_IN_STAGE; i++) { // ������ ���̴� ����
			if (wordInCurrentStage[i].y == 22 && wordInCurrentStage[i].isPrint == true) { // �ٴڿ� �����ϸ� life--; isPrint ���� false�� ����
				gameStatus.life--;

				wordInCurrentStage[i].isPrint = false;
			}
		}

		gameStatus.pulseCount++;

		Sleep(theSpeedOfWordDrop[gameStatus.stage-1]); // �ܾ��� ���ϼӵ� ������
	}

	gameStatus.pulseCount = 0;
	gameStatus.correctAnswerCount = 0;

	return NULL;
}

void* bottomThreadFunc(void* arg) {
	int x = 9, y = 24; // gotoxy(x, y)�� arg�� ���� ��� - �ʱ갪�� (10, 24)

	char inputBuffer[10];
	int index = 0;

	for (int i = 0; i < 10; i++) {
		inputBuffer[i] = (char)NULL;
	}

	while (true) {
		// topThread�� ���� ���� ���� 3��
		if (gameStatus.life == 0) {
			break;
		}

		if (gameStatus.correctAnswerCount == THE_NUMBER_OF_WORDS_IN_STAGE) {
			break;
		}

		if (gameStatus.isPrintCount == 10 && gameStatus.pulseCount > 10) {
			break;
		}

		if (_kbhit()) {
			int keyboardInput = _getch(); _getch(); // ���� Ű���� �� �Է¹���, �� ����Ʈ�� ���������� _getch( ) �� �� ���� �����
			fflush(stdin);

			if (keyboardInput == BACKSPACE_KEY && x != 9) { // �齺���̽� ����
				gotoxy(x - 1, y);  printf(" "); // �� ���� �����
				x--; index--;
			}
			else if (keyboardInput == BACKSPACE_KEY && x == 9) {
				// empty!
			}
			else if (keyboardInput == SPACEBAR_KEY) {
				// empty!
			}
			else if (keyboardInput == ENTER_KEY) { // ����Ű ����
				gotoxy(9, 24); printf("                                   "); // 1) Ŀ�� �� ������ �ΰ� ������ �� �����
				x = 9; y = 24; // 2) Ŀ���� �ʱ갪���� ������

				// �Է� ���� ����� ���� ������ -> score++, correctAnswer++, isPrint->false
				// ���� ������� ���ʹ����� ���� �� �ʱ�ȭ�� �ؾ���
				inputBuffer[index] = (char)NULL;
				for (int i = 0; i < THE_NUMBER_OF_WORDS_IN_STAGE; i++) {
					if (strcmp(inputBuffer, wordInCurrentStage[i].word) == 0) { // �ܾ ��ġ�ϸ�
						gameStatus.score += 10;
						gameStatus.correctAnswerCount++;
						wordInCurrentStage[i].isPrint = false;
					}
					else {
						// empty!
					}
				}

				for (int i = 0; i < 10; i++) {
					inputBuffer[i] = (char)NULL;
				}

				index = 0;
			}
			else if (x < 18) {
				gotoxy(x, y);  printf("%c", keyboardInput);
				x++;

				inputBuffer[index++] = keyboardInput;
			}
			else {
				// empty!
			}
		}

	}

	return NULL;
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

	while (true) {
		system("cls");

		if (gameStatus.life == 0) {
			enterRankingFromGamePlay(); // ��ŷȭ������ ����

			break;
		}

		if (gameStatus.stage > MAX_STAGE) { // ��� �������� Ŭ����
			gameStatus.stage--;

			clearBoard(); // ȭ�� �����
			printStatus(); // ��������, ������, ���� ���
			printBorderLine(); // ��輱 ���

			gotoxy(0, 2); printf("Complete Final Stage!!\n");
			gotoxy(0, 3); printf("Final Score: %d", gameStatus.score);
			system("pause>null");
			system("pause>null");
			system("pause>null");

			enterRankingFromGamePlay(); // ��ŷȭ������ ����

			break;
		}	

		srand((unsigned int)time(NULL)); // ���� �õ尪
		for (int i = 0; i < THE_NUMBER_OF_WORDS_IN_STAGE; i++) { // ��ü ����Ʈ���� ���� ���������� �� �ܾ� ���� ����
			wordInCurrentStage[i].word = wordList[rand() % THE_NUMBER_OF_WORDS];
			for (int j = 0; j < i; j++) {
				if (strcmp(wordInCurrentStage[i].word, wordInCurrentStage[j].word) == 0) { // �ߺ� �˻�
					i--;
					break;
				}
			}
			// ������ ���� �� �ʱ�ȭ
			wordInCurrentStage[i].isPrint = false;
			wordInCurrentStage[i].x = (rand() % 56) + 1; // �ش� ����� ���� x�� ����
			wordInCurrentStage[i].y = 2;
		}

		pthread_t topThread, bottomThread; // ������ ����
		int intTemp = 0; // pthread_join�� ����� arg
		void* voidPointerTemp = &intTemp; // pthread_create�� ����� arg

		pthread_create(&topThread, NULL, topThreadFunc, (void*)voidPointerTemp); // topThread ����
		pthread_create(&bottomThread, NULL, bottomThreadFunc, (void*)voidPointerTemp); // bottomThread ����

		pthread_join(topThread, (void**)&intTemp); // topThread ����
		pthread_join(bottomThread, (void**)&intTemp); // bottomThread ����

		// gameStatus.stage++; // �������� ����
	}
}