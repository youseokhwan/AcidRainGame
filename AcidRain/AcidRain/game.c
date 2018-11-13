#include "game.h"

void gameStart() { // ���ӽ���
	system("cls");

	// ��ü �ܾ� ����Ʈ ����
	char* wordList[WORD] = { "art", "able", "acid", "about", "air", "aim", "also", "ant", "arm", "army",
		"ball", "blue", "bag", "band", "beat", "beef", "belt", "bill", "bike", "boat",
		"cafe", "cake", "call", "camp", "camo", "care", "case", "cave", "cat", "chef",
		"data", "dark", "day", "deer", "deep", "dog", "door", "draw", "drum", "drug",
		"each", "easy", "echo", "edge", "egg", "evil", "even", "exam", "eye", "else" };

	// gameStatus �ʱ�ȭ
	gameStatus.life = 5;
	gameStatus.score = 0;
	gameStatus.stage = 1;
	gameStatus.correctAnswer = 0;
	gameStatus.printCount = 0;

	while (true) { // �������� ����
		printStatus(); // status�� ���
		printBorderLine(); // ��輱 ���
		printPrompt(); // �Է� â ���

		if (gameStatus.life == 0) { // ������ 0�̸� ���� ����
			clearStatus();
			clearBoard();
			clearPrompt();

			gotoxy(0, 2); printf("Game Over!!\n");
			gotoxy(0, 3); printf("Ŭ������ ��������: %d / ���� ���ھ�: %d", gameStatus.stage - 1, gameStatus.score);
			system("pause>nul");

			rankingFromGame(); // ��ŷ���� ����

			break;
		}
		else if (gameStatus.stage > STAGE) { // ��� �������� Ŭ����
			clearStatus();
			clearBoard();

			gotoxy(0, 2); printf("��� ���������� Ŭ�����Ͽ����ϴ�!!\n");
			gotoxy(0, 3); printf("���� ���ھ�: %d", gameStatus.score);
			system("pause>null");

			rankingFromGame(); // ��ŷ���� ����

			break;
		}
		else {
			// ���� �������� �ܾ� ����
			srand((unsigned int)time(NULL)); // ���� �õ尪
			for (int i = 0; i < WORD_IN_STAGE; i++) { // ��ü ����Ʈ���� ���� ���������� �� �ܾ� ���� ����
				wordInStage[i].word = wordList[rand() % WORD];
				for (int j = 0; j < i; j++) {
					if (strcmp(wordInStage[i].word, wordInStage[j].word) == 0) { // �ߺ� �˻�
						i--;

						break;
					}
				}

				wordInStage[i].isPrint = false;
				wordInStage[i].x = (rand() % 56) + 1; // �ش� ����� ���� x�� ����
				wordInStage[i].y = 2;
			}

			gameStatus.updateCount = 0;
			gotoxy(0, 2); printf("�������� %d ����!!", gameStatus.stage);
			system("pause>nul");

			// �ܾ� �Էºκ� �ʱ갪 ����
			int inputX = 9, inputY = 24; // �ʱ갪
			char inputBuffer[BUFFER];
			int iterator = 0;

			for (int i = 0; i < BUFFER; i++) {
				inputBuffer[i] = (char)NULL;
			}

			gameStatus.startClock = clock();
			while (true) { // �ܾ� ��� �� �Է� ����

#ifndef TEST_MODE
				gotoxy(0, 26); printf("           ");
				gotoxy(0, 26); printf("%d", gameStatus.correctAnswer);
#endif

				// ������ 0�̰ų� ��� �������� Ŭ���� �� ����
				if (gameStatus.life == 0 || gameStatus.stage > STAGE) {
					// break �� ���� while �������� �۾� ����

					break;
				}

				// �ܾ� ��� �����̸�
				if (gameStatus.correctAnswer == WORD_IN_STAGE) {
					clearBoard();

					gameStatus.score += gameStatus.stage * 100;
					gotoxy(0, 2); printf("�������� %d Ŭ����!!", gameStatus.stage++);

					gameStatus.correctAnswer = 0;
					system("pause>nul");

					break;
				}

				// �ܾ� ��� ������ �������� ���� �ʾ��� ��
				for (int i = 0; i < WORD_IN_STAGE; i++) {
					if (wordInStage[i].isPrint == false) {
						gameStatus.printCount++;
					}
				}

				if (gameStatus.updateCount >= WORD_IN_STAGE) { // clock( ) �̿��ؼ� �ٲ����
					if (gameStatus.printCount == WORD_IN_STAGE) {
						gameStatus.score += gameStatus.stage * 100;
						gameStatus.correctAnswer = 0;

						gotoxy(0, 2); printf("�������� %d Ŭ����!!\n", gameStatus.stage++);
						system("pause>nul");

						break;
					}
					else {
						gameStatus.printCount = 0;
					}
				}
				else {
					gameStatus.printCount = 0;
				}

				// �ܾ� ��� �κ�
				if ((clock()-gameStatus.startClock) % 500 == 0) {
					clearBoard();

					if (gameStatus.updateCount <= WORD_IN_STAGE) {
						wordInStage[gameStatus.updateCount].isPrint = true;
					}

					for (int i = 0; i < WORD_IN_STAGE; i++) { // isPrint���� true�� �ܾ� ���
						if (wordInStage[i].isPrint == true) {
							gotoxy(wordInStage[i].x, wordInStage[i].y);
							printf("%s", wordInStage[i].word);
						}
					}

					for (int i = 0; i < WORD_IN_STAGE; i++) { // ������ ���̴� ����
						if (wordInStage[i].y == 22 && wordInStage[i].isPrint == true) { // �ٴڿ� �����ϸ� life--; isPrint ���� false�� ����
							gameStatus.life--;

							wordInStage[i].isPrint = false;

							clearStatus();
							printStatus();
							printBorderLine();
						}
					}

					for (int i = 0; i <= gameStatus.updateCount; i++) { // ��µ� �ܾ�� y�� ++
						wordInStage[i].y++;
					}

					gameStatus.updateCount++;
				}

				// �ܾ� �Է� �κ�

				while (_kbhit()) {
					int keyboardInput = _getch(); _getch(); // Ű���� �� �Է¹���, �� ����Ʈ ���������� _getch() �� �� ���

					if (keyboardInput == BACKSPACE && inputX != 9) {
						gotoxy(--inputX, inputY); printf(" ");
						iterator--;
					}
					else if (keyboardInput == BACKSPACE && inputX == 9) {
						// empty!!
					}
					else if (keyboardInput == SPACEBAR) {
						// empty!!
					}
					else if (keyboardInput == ENTER) {
						inputX = 9; inputY = 24;
						gotoxy(inputX, inputY); printf("                  ");

						inputBuffer[iterator] = (char)NULL;
						for (int i = 0; i < WORD_IN_STAGE; i++) {
							if (strcmp(inputBuffer, wordInStage[i].word) == 0) {
								gameStatus.score += 10;
								clearStatus();
								printStatus();

								gameStatus.correctAnswer++;
								wordInStage[i].isPrint = false;

								clearBoard();
								for (int j = 0; j < WORD_IN_STAGE; j++) { // isPrint���� true�� �ܾ� ���
									if (wordInStage[j].isPrint == true) {
										gotoxy(wordInStage[j].x, wordInStage[j].y);
										printf("%s", wordInStage[j].word);
									}
								}
							}
							else {
								// empty!!
							}
						}

						for (int i = 0; i < BUFFER; i++) {
							inputBuffer[i] = (char)NULL;
						}

						iterator = 0;
					}
					else if (inputX < 18) {
						gotoxy(inputX, inputY); printf("%c", keyboardInput);
						inputX++;

						if (iterator < BUFFER) {
							inputBuffer[iterator] = keyboardInput;
							if (iterator != BUFFER - 1) {
								iterator++;
							}
						}
					}
					else {
						// empty!!
					}
				}
			}
		}
	}
}