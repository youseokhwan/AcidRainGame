#include "game.h"

//#define WORD_FILE_IO_CANCEL_FOR_TEST

/*
	���� �����ϴ� �Լ�
	�ܾ� ����, ȭ�� ���, �ܾ� �����, ���� �˻� �� ����
*/
void gameStart(struct _record* record, struct _gameStatus* gameStatus) {
	system("cls");
	PlaySound(TEXT(SOUND_SELECT), NULL, SND_FILENAME | SND_ASYNC); // select.wav ���

	/*
		wordInStage ����ü ����
		�� �ܾ��� �ؽ���, ��ǥ, ��� ���� �� ���� ����
	*/
	struct _word wordInStage[WORD_IN_STAGE];

	/*
		���� ����� ������� ����
	*/
#ifdef WORD_FILE_IO_CANCEL_FOR_TEST
	// ��ü �ܾ� ����Ʈ ����
	char* wordList[WORD] = { "art", "able", "acid", "about", "air", "aim", "also", "ant", "arm", "army",
		"ball", "blue", "bag", "band", "beat", "beef", "belt", "bill", "bike", "boat",
		"cafe", "cake", "call", "camp", "camo", "care", "case", "cave", "cat", "chef",
		"data", "dark", "day", "deer", "deep", "dog", "door", "draw", "drum", "drug",
		"each", "easy", "echo", "edge", "egg", "evil", "even", "exam", "eye", "else" };
#endif
	/*
		���� ����� ���
	*/
#ifndef WORD_FILE_IO_CANCEL_FOR_TEST
	FILE *fp;
	char fileBuffer[FILE_BUFFER];

	fopen_s(&fp, "dataFile\\word_list.txt", "rt");

	if (fp == NULL) {
		system("cls");
		gotoxy(0, 0); printf("word_list.txt ������ �����ϴ�!");
		gotoxy(0, 2); printf("���α׷��� �����մϴ�.");
		gotoxy(0, 3);

		free(record);

		exit(1);
	}
	else {
		fgets(fileBuffer, FILE_BUFFER, fp);
	}

	fclose(fp);

	/*
		���� ��������� �ܾ� ��� �޾Ƽ� ��ū���� �����Ͽ� ����
	*/
	char* wordList[WORD];
	char* nextContext = NULL;
	char* ptr = strtok_s(fileBuffer, " ", &nextContext);

	for (int i = 0; i < WORD; i++) {
		wordList[i] = ptr;
		ptr = strtok_s(NULL, " ", &nextContext);
	}
#endif

	/*
		gameStatus ����ü �ʱ�ȭ
	*/
	gameStatus->life = 5;
	gameStatus->score = 0;
	gameStatus->stage = 1;
	gameStatus->correctAnswer = 0;
	gameStatus->printCount = 0;

	addLog("enter a game\n", false); // �α� �߰�
	/*
		�������� ����
	*/
	while (true) {
		printStatus(gameStatus);
		printDoubleBorderLine();
		printPrompt();

		/*
			������ 0�̸� ���� �����Ͽ� ��ŷ���� ����
		*/
		if (gameStatus->life == 0) {
			clearStatus();
			clearBoard();
			clearPrompt();

			PlaySound(TEXT(SOUND_FAIL), NULL, SND_FILENAME | SND_ASYNC); // fail.wav ���
			gotoxy(0, 2); printf("Game Over!!\n");
			gotoxy(0, 3); printf("�Ϸ��� ��������: %d / ���� ���ھ�: %d", --gameStatus->stage, gameStatus->score);

			/*
				���� �ױ� ������ ���ϰ� Ÿ������ �ϴٰ� �״� ��찡 ������
				system("pause>nul")�� ����ϸ� ���ڸ��� ���ӵ� Ű �Է����� �ǵ�ġ�ʰ� �����
				���� ������ ����Ű�� �Է��ؾ� ����ǵ��� ��
			*/
			gotoxy(0, 5); printf("������ ����Ű�� ������ ����˴ϴ�.");
			while (true) {
				if (_kbhit()) {
					if (_getch() == ARROW) {
						if (_getch() == RIGHT_ARROW) {
							break;
						}
					}
				}
			}

			/*
				��ŷ���� ����
				ranking.c ����
			*/
			rankingFromGame(gameStatus, record);

			break;
		}
		/*
			��� �������� Ŭ�����ϸ� ���� �����Ͽ� ��ŷ���� ����
		*/
		else if (gameStatus->stage > STAGE) {
			clearStatus();
			clearBoard();

			PlaySound(TEXT(SOUND_ALL_CLEAR), NULL, SND_FILENAME | SND_ASYNC); // allClear.wav ���
			gotoxy(0, 2); printf("��� ���������� Ŭ�����Ͽ����ϴ�!!\n");
			gotoxy(0, 3); printf("���� ���ھ�: %d", gameStatus->score);
			gameStatus->stage--; // ���� �������� ���� 11�̹Ƿ� 1 ����
			system("pause>null");

			/*
				��ŷ���� ����
				ranking.c ����
			*/
			rankingFromGame(gameStatus, record);

			break;
		}
		else {
			/*
				���� ������������ ����� �ܾ� ���� ����
			*/
			srand((unsigned int)time(NULL));
			for (int i = 0; i < WORD_IN_STAGE; i++) {
				wordInStage[i].text = wordList[rand() % WORD];
				for (int j = 0; j < i; j++) {
					if (strcmp(wordInStage[i].text, wordInStage[j].text) == 0) { // �ߺ� �˻�
						i--;
						break;
					}
				}

				wordInStage[i].isPrint = false;
				wordInStage[i].x = (rand() % 56) + 1; // ���� x ��ǥ ����
				wordInStage[i].y = 1;
			}

			gameStatus->updateCount = 0;
			gotoxy(0, 2); printf("�������� %d ����!!", gameStatus->stage);
			system("pause>nul");

			/*
				�ܾ� �Էºο� ����� ���� �ʱ�ȭ
			*/
			int inputX = 9, inputY = 24;
			char inputBuffer[INPUT_BUFFER];
			int inputIndex = 0;

			for (int i = 0; i < INPUT_BUFFER; i++) {
				inputBuffer[i] = (char)NULL;
			}

			/*
				���۽ð� ����
				�ܾ� ���ϼӵ� �����ϱ� ����
			*/
			gameStatus->startClock = clock();
			/*
				�ܾ� ��� ����
			*/
			while(true) {
				/*
					������ 0�̰ų� ��� �������� Ŭ�����ϸ� break
					�ܾ� ��� while ���� break �� ��, ���� while �������� �۾� ����
				*/
				if (gameStatus->life == 0 || gameStatus->stage > STAGE) {
					break;
				}

				/*
					�ܾ� ��� �������� �Է��ϸ� ���� �������� ����
				*/
				if (gameStatus->correctAnswer == WORD_IN_STAGE) {
					system("cls");

					PlaySound(TEXT(SOUND_STAGE_CLEAR), NULL, SND_FILENAME | SND_ASYNC); // stageClear.wav ���

					gameStatus->score += gameStatus->stage * 100;
					gotoxy(0, 2); printf("�������� %d Ŭ����!!", gameStatus->stage++);

					gameStatus->correctAnswer = 0;
					system("pause>nul");

					break;
				}

				/*
					�ܾ� ��� �Է����� ��������, ������ �ʾ��� �� ���� �������� ����
				*/
				for (int i = 0; i < WORD_IN_STAGE; i++) {
					if (wordInStage[i].isPrint == false) {
						gameStatus->printCount++;
					}
				}

				if (gameStatus->updateCount >= WORD_IN_STAGE * 2) {
					if (gameStatus->printCount == WORD_IN_STAGE) {
						gameStatus->score += gameStatus->stage * 100;
						gameStatus->correctAnswer = 0;

						PlaySound(TEXT(SOUND_STAGE_CLEAR), NULL, SND_FILENAME | SND_ASYNC); // stageClear.wav ���

						gotoxy(0, 2); printf("�������� %d Ŭ����!!\n", gameStatus->stage++);
						system("pause>nul");

						break;
					}
					else {
						gameStatus->printCount = 0;
					}
				}
				else {
					gameStatus->printCount = 0;
				}

				/*
					�ܾ� ��� �κ�
					clock( ) �̿��Ͽ� ���ϼӵ� �������� ���� ����
					updateCount�� ¦���϶����� �ܾ� ������� ��� ���� 
				*/
				if ((clock() - gameStatus->startClock) % gameStatus->dropSpeed[gameStatus->stage - 1] == 0) {
					clearBoard();

					if (gameStatus->updateCount % 2 == 0 && gameStatus->updateCount < WORD_IN_STAGE * 2) {
						wordInStage[gameStatus->updateCount / 2].isPrint = true;
					}

					/*
						�ܾ� y�� �����Ͽ� ���� ����
						���� ó���� �ܾ �ٴڿ� ��� �������� �������� �ʵ��� ��µ� �ܾ ����
					*/
					for (int i = 0; i < WORD_IN_STAGE; i++) {
						if (wordInStage[i].isPrint == true) {
							wordInStage[i].y++;
						}
					}

					/*
						isPrint���� true�� �ܾ ���
					*/
					for (int i = 0; i < WORD_IN_STAGE; i++) {
						if (wordInStage[i].isPrint == true) {
							gotoxy(wordInStage[i].x, wordInStage[i].y);
							setColor(YELLOW);
							printf("%s", wordInStage[i].text);
						}
					}

					/*
						�ܾ �ٴڿ� �����ϸ� ������ ���� �� isPrint�� false�� ����
					*/
					for (int i = 0; i < WORD_IN_STAGE; i++) {
						if (wordInStage[i].y == 22 && wordInStage[i].isPrint == true) {
							gameStatus->life--;

							wordInStage[i].isPrint = false;

							clearStatus();
							printStatus(gameStatus);
							printDoubleBorderLine();
						}
					}

					gameStatus->updateCount++;
				}

				/*
					�ܾ� �Է� �κ�
					���� �����忡�� ������� ���ÿ� �����ϱ� ���� _kbhit() ���
					Ÿ���� �ð�ȿ���� ���ʿ� Ű �Է� ���� ���� _getch(), inputIndex ���
					
					<< #define ISSUE >>
					������ ����: ���� PC���� �׽�Ʈ�� ��� _getch()���� ������ ����� PC�� �׷��� ���� PC ������(���� �ľ� ����)
					���� �� �� ������ �ν��� �ȴٸ� �� ISSUE�� �ּ� �����ϰ� ������ ��
				*/
				while (_kbhit()) {
					int keyboardInput = _getch();

					/*
						Ŀ���� �� �տ� ���� �ʰ�, �齺���̽� �Է� �� �� ���� ����
					*/
					if (keyboardInput == BACKSPACE && inputX != 9) {
#ifndef ISSUE
						_getch(); // �Է� ��Ʈ�� ����
#endif
						gotoxy(--inputX, inputY); printf(" ");
						inputIndex--;
					}
					/*
						Ŀ�� �� �տ� ������, �齺���̽� �Է� ����
					*/
					else if (keyboardInput == BACKSPACE && inputX == 9) {
#ifndef ISSUE
						_getch(); // �Է� ��Ʈ�� ����
#endif
					}
					/*
						�����̽��� �Է� ����
					*/
					else if (keyboardInput == SPACEBAR) {
#ifndef ISSUE
						_getch(); // �Է� ��Ʈ�� ����
#endif
					}
					/*
						���� ����Ű �Է� �� ��� ���ӿ���
						�ٸ� ����Ű ���� �� �����Ⱚ �Է� ����
					*/
					else if (keyboardInput == ARROW) {
						keyboardInput = _getch();
						
						if (keyboardInput == LEFT_ARROW) {
							gameStatus->life = 0;
						}
						else {
							// empty!!
						}
					}
					/*
						����Ű �Է� ��
						���� �˻� �� gameStatus�� ����
						���� ���� ������� Inputâ �����
					*/
					else if (keyboardInput == ENTER) {
#ifndef ISSUE
						_getch(); // �Է� ��Ʈ�� ����
#endif
						inputX = 9; inputY = 24;
						gotoxy(inputX, inputY); printf("                  ");

						inputBuffer[inputIndex] = (char)NULL;
						for (int i = 0; i < WORD_IN_STAGE; i++) {
							/*
								�̹� ����ó�� �� �ܾ ���� ��µ��� ���� �ܾ �Է����� �� ����ó������ �ʱ� ����
								isPrint�� true�� �ܾ ���� �˻�
							*/
							if (strcmp(inputBuffer, wordInStage[i].text) == 0 && wordInStage[i].isPrint == true) {
								gameStatus->score += 10;
								clearStatus();
								printStatus(gameStatus);

								gameStatus->correctAnswer++;
								wordInStage[i].isPrint = false;

								PlaySound(TEXT(SOUND_CORRECT), NULL, SND_FILENAME | SND_ASYNC); // correct.wav ���

								/*
									�Ų����� �ִϸ��̼� ���� �ܾ� �ѹ� �� ���
								*/
								clearBoard();
								for (int j = 0; j < WORD_IN_STAGE; j++) {
									if (wordInStage[j].isPrint == true) {
										gotoxy(wordInStage[j].x, wordInStage[j].y);
										setColor(YELLOW);
										printf("%s", wordInStage[j].text);
										setColor(WHITE);
									}
								}
							}
							else {
								// empty!!
							}
						}

						/*
							�Է� �κ� ���� �ʱ�ȭ
						*/
						for (int i = 0; i < INPUT_BUFFER; i++) {
							inputBuffer[i] = (char)NULL;
						}
						inputIndex = 0;
					}
					/*
						�ܾ� ���� �Է�
					*/
					else if (inputX < 18) {
#ifndef ISSUE
						_getch(); // �Է� ��Ʈ�� ����
#endif

						setColor(YELLOW);
						gotoxy(inputX, inputY); printf("%c", keyboardInput);
						setColor(WHITE);
						inputX++;

						if (inputIndex < INPUT_BUFFER) {
							inputBuffer[inputIndex] = keyboardInput;
							if (inputIndex != INPUT_BUFFER - 1) {
								inputIndex++;
							}
						}
					}
					else {
#ifndef ISSUE
						_getch(); // �Է� ��Ʈ�� ����
#endif
					}
				}
			}
		}
	}
}
