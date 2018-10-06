#include "gamestart.h"
#include "consoleprint.h"

// ���������������� �����忡 ����� �Լ� ���� ����������������
void* topThreadFunc(void* arg) {

	int theSpeedOfWordDrop[MAX_STAGE] = { 1200, 1000, 900, 800, 750, 700, 650, 600, 550, 200 }; // �ܾ� �������� ���ǵ� ����
	int pulseCount = 0; // �ܾ� �������� �۾��� ����� Ƚ��
	gameStatus.correctInputCountInStage = 0; // ������ �ش� ������������ ���� ������ ����
	
	srand(time(NULL)); // ���� �õ尪
	for (int i = 0; i < THE_NUMBER_OF_WORDS_IN_STAGE; i++) { // �ش� ����� ���� x�� ����
		wordInCurrentStage[i].x = (rand() % 56) + 1;
	}

	clearBoard(); // ȭ�� �����
	printStatus(); // ��������, ������, ���� ���
	printUpAndDownBorderLine(); // ��輱 ���
	printPrompt(); // ���� �Է�â ���
	gotoxy(0, 2);  printf("Stage %d START!!", gameStatus.stage);
	system("pause>nul");

	while (true) {
		clearBoard(); // ȭ�� �����
		printStatus(); // ��������, ������, ���� ���
		printUpAndDownBorderLine(); // ��輱 ���
		printPrompt(); // ���� �Է�â ���

		if (gameStatus.life == 0) { // ���� ����� 0�̸� ���� ���� �� ranking( ) ����
			gotoxy(0, 2); printf("Game Over!!\n");
			system("pause>nul");

			// ranking( ) ����
			break;
		}

		if (gameStatus.correctInputCountInStage == THE_NUMBER_OF_WORDS_IN_STAGE) { // �ܾ ��� �Է��ϸ� ���� ���������� �Ѿ
			gameStatus.score += gameStatus.stage * 100; // Ŭ���� �� ��������*100 ��ŭ ���� ����
			gotoxy(0, 2); printf("%d �������� Ŭ����!!\n", gameStatus.stage);
			system("pause>nul");

			break;
		}

		wordInCurrentStage[pulseCount].isPrint = true; // �ܾ� �ϳ��� isPrint�� true�� ����

		for (int i = 0; i < THE_NUMBER_OF_WORDS_IN_STAGE; i++) { // isPrint���� true�� �ܾ� ���
			if (wordInCurrentStage[i].isPrint == true) {
				gotoxy(wordInCurrentStage[i].x, wordInCurrentStage[i].y);
				printf("%s", wordInCurrentStage[i].word);
			}
		}

		for (int i = 0; i <= pulseCount; i++) { // ��µ� �ܾ�� y�� ++
			wordInCurrentStage[i].y++;

			if (wordInCurrentStage[i].y == 22 && wordInCurrentStage[i].isPrint == true) { // �ٴڿ� �����ϸ� isPrint ���� false�� �����ϰ�, life--;
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
	int x = 9, y = 24; // gotoxy(x, y)�� arg�� ���� ��� - �ʱ갪�� (10, 24)

	while (true) {
		if ((gameStatus.life == 0) || (gameStatus.correctInputCountInStage == THE_NUMBER_OF_WORDS_IN_STAGE)) { // topThread�� ���ÿ� ����
			break;
		}

		if (_kbhit()) {
			int keyboardInput = _getch(); _getch(); // ���� Ű���� �� �Է¹���

			if (keyboardInput == BACKSPACE_KEY && x != 9) { // �齺���̽� ����
				gotoxy(x - 1, y);  printf(" "); // �� ���� �����
				x--;
			}
			else if (keyboardInput == BACKSPACE_KEY && x == 9) {
				// empty
			}
			else if (keyboardInput == SPACEBAR_KEY) {
				// empty
			}
			else if (keyboardInput == ENTER_KEY) { // ����Ű ����
				gotoxy(9, 24); printf("                                   "); // 1) Ŀ�� �� ������ �ΰ� ������ �� �����
				x = 9; y = 24; // 2) Ŀ���� �ʱ갪���� ������

				// �Է� ���� ����� ���� ������ -> score++, correctAnswer++, isPrint->false
				// ���� ������� ���ʹ����� ���� �� �ʱ�ȭ�� �ؾ���
			}
			else if (x < 19) {
				gotoxy(x, y);  printf("%c", keyboardInput);
				x++;
			}
			else {
				// empty;
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
			// ranking( ) ����

			break;
		}

		if (gameStatus.stage > MAX_STAGE) { // ��� �������� Ŭ����
			printUpAndDownBorderLine();
			gotoxy(0, 2); printf("��� ���������� Ŭ�����ϼ̽��ϴ�!!\n");

			// ranking( ) ����

			break;
		}	

		srand(time(NULL)); // ���� �õ尪
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
			wordInCurrentStage[i].x = 0;
			wordInCurrentStage[i].y = 2;
		}

		int intTemp = 0;
		void* voidPointerTemp = &intTemp;

		pthread_create(&topThread, NULL, topThreadFunc, (void*)voidPointerTemp); // topThread ����
		pthread_create(&bottomThread, NULL, bottomThreadFunc, (void*)voidPointerTemp); // bottomThread ����

		pthread_join(topThread, (void**)&intTemp); // topThread ����
		pthread_join(bottomThread, (void**)&intTemp); // bottomThread ����

		gameStatus.stage++; // �������� ����
	}
}