#include "game.h"

#define NORMAL_SPEED
//#define FAST_SPEED_FOR_TEST
//#define SLOW_SPEED_FOR_TEST
//#define PRINT_STATUS_FOR_TEST
//#define WORD_FILE_IO_CANCEL_FOR_TEST

void gameStart(struct _record* record) { // ���ӽ���
	system("cls");
	PlaySound(TEXT(SOUND_SELECT), NULL, SND_FILENAME | SND_ASYNC); // select.wav ���

	// struct ����
	struct _gameStatus gs;
	struct _gameStatus* gameStatus = &gs;
	struct _word wordInStage[WORD_IN_STAGE];

#ifdef WORD_FILE_IO_CANCEL_FOR_TEST
	// ��ü �ܾ� ����Ʈ ����
	char* wordList[WORD] = { "art", "able", "acid", "about", "air", "aim", "also", "ant", "arm", "army",
		"ball", "blue", "bag", "band", "beat", "beef", "belt", "bill", "bike", "boat",
		"cafe", "cake", "call", "camp", "camo", "care", "case", "cave", "cat", "chef",
		"data", "dark", "day", "deer", "deep", "dog", "door", "draw", "drum", "drug",
		"each", "easy", "echo", "edge", "egg", "evil", "even", "exam", "eye", "else" };
#endif
#ifndef WORD_FILE_IO_CANCEL_FOR_TEST
	// ��ü �ܾ� ����Ʈ ����(���� �����)
	FILE *fp;
	char fileBuffer[FILE_BUFFER];

	fp = fopen("dataFile\\word_list.txt", "rt");

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

	char* wordList[WORD];
	char* ptr = strtok(fileBuffer, " ");

	for (int i = 0; i < WORD; i++) {
		wordList[i] = ptr;
		ptr = strtok(NULL, " ");
	}
#endif

	// gameStatus �ʱ�ȭ
	gameStatus->life = 5;
	gameStatus->score = 0;
	gameStatus->stage = 1;
	gameStatus->correctAnswer = 0;
	gameStatus->printCount = 0;
	for (int i = 0; i < STAGE; i++) { // �ܾ� ���ϼӵ� ����
#ifdef NORMAL_SPEED
		gameStatus->dropSpeed[i] = 800 - 60 * i;
#endif
#ifdef FAST_SPEED_FOR_TEST
		gameStatus->dropSpeed[i] = 200;
#endif
#ifdef SLOW_SPEED_FOR_TEST
		gameStatus->dropSpeed[i] = 500;
#endif
	}

	addLog("enter a game\n", false);
	while (true) { // �������� ����
		printStatus(gameStatus); // status�� ���
		printDoubleBorderLine(false); // ��輱 ���
		printPrompt(); // �Է� â ���

		if (gameStatus->life == 0) { // ������ 0�̸� ���� ����
			clearStatus();
			clearBoard();
			clearPrompt();

			PlaySound(TEXT(SOUND_FAIL), NULL, SND_FILENAME | SND_ASYNC); // fail.wav ���
			gotoxy(0, 2); printf("Game Over!!\n");
			gotoxy(0, 3); printf("�Ϸ��� ��������: %d / ���� ���ھ�: %d", --gameStatus->stage, gameStatus->score);

			gotoxy(0, 5); printf("������ ����Ű�� ������ ����˴ϴ�.");
			while (true) {
				if (_kbhit()) {
					if (_getch() == ARROW) {
						if (_getch() == RIGHT_ARROW) { // ������ ����Ű�� ������ break
							break;
						}
					}
				}
			}

			rankingFromGame(gameStatus, record); // ��ŷ���� ����(ranking.c)

			break;
		}
		else if (gameStatus->stage > STAGE) { // ��� �������� Ŭ����
			clearStatus();
			clearBoard();

			PlaySound(TEXT(SOUND_ALL_CLEAR), NULL, SND_FILENAME | SND_ASYNC); // allClear.wav ���
			gotoxy(0, 2); printf("��� ���������� Ŭ�����Ͽ����ϴ�!!\n");
			gotoxy(0, 3); printf("���� ���ھ�: %d", gameStatus->score);
			gameStatus->stage--; // ���� �������� ���� 11�̹Ƿ� 1 ����
			system("pause>null");

			rankingFromGame(gameStatus, record); // ��ŷ���� ����(ranking.c)

			break;
		}
		else {
			// ���� �������� �ܾ� ����
			srand((unsigned int)time(NULL)); // ���� �õ尪
			for (int i = 0; i < WORD_IN_STAGE; i++) { // ��ü ����Ʈ���� ���� ���������� �� �ܾ� ���� ����
				wordInStage[i].text = wordList[rand() % WORD];
				for (int j = 0; j < i; j++) {
					if (strcmp(wordInStage[i].text, wordInStage[j].text) == 0) { // �ߺ� �˻�
						i--;
						break;
					}
				}

				wordInStage[i].isPrint = false;
				wordInStage[i].x = (rand() % 56) + 1; // �ش� ����� ���� x�� ����
				wordInStage[i].y = 1;
			}

			gameStatus->updateCount = 0;
			gotoxy(0, 2); printf("�������� %d ����!!", gameStatus->stage);
			system("pause>nul");

			// �ܾ� �Էºκ� �ʱ갪 ����
			int inputX = 9, inputY = 24; // �ʱ갪
			char inputBuffer[INPUT_BUFFER];
			int iterator = 0; // �Է�â���� �� iterator

			for (int i = 0; i < INPUT_BUFFER; i++) {
				inputBuffer[i] = (char)NULL;
			}

			gameStatus->startClock = clock(); // ���۽ð� ����
			while(true) { // �ܾ� ��� �� �Է� ����
#ifdef PRINT_STATUS_FOR_TEST
				gotoxy(0, 26); printf("           ");
				gotoxy(0, 26); printf("%d", gameStatus.correctAnswer1);
				gotoxy(3, 26); printf("%d", gameStatus.life1);
#endif

				// ������ 0�̰ų� ��� �������� Ŭ���� �� ����
				if (gameStatus->life == 0 || gameStatus->stage > STAGE) {
					// break �� ���� while �������� �۾� ����

					break;
				}

				// �ܾ� ��� �����̸�
				if (gameStatus->correctAnswer == WORD_IN_STAGE) {
					clearBoard();

					PlaySound(TEXT(SOUND_STAGE_CLEAR), NULL, SND_FILENAME | SND_ASYNC); // stageClear.wav ���

					gameStatus->score += gameStatus->stage * 100;
					gotoxy(0, 2); printf("�������� %d Ŭ����!!", gameStatus->stage++);

					gameStatus->correctAnswer = 0;
					system("pause>nul");

					break;
				}

				// �ܾ� ��� ������ �������� ���� �ʾ��� ��
				for (int i = 0; i < WORD_IN_STAGE; i++) {
					if (wordInStage[i].isPrint == false) {
						gameStatus->printCount++;
					}
				}

				if (gameStatus->updateCount >= WORD_IN_STAGE) {
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

				// �ܾ� ��� �κ�
				if ((clock() - gameStatus->startClock) % gameStatus->dropSpeed[gameStatus->stage - 1] == 0) { // ������ dropSpeed���� ���� �ӵ� ����
					clearBoard();

					if (gameStatus->updateCount % 2 == 0 && gameStatus->updateCount < WORD_IN_STAGE * 2) { // updateCount�� 10�����̸� ���ʴ�� �ܾ� ��½���
						wordInStage[gameStatus->updateCount / 2].isPrint = true;
					}

					for (int i = 0; i < WORD_IN_STAGE; i++) { // ��µ� �ܾ�� y�� ++
						if (wordInStage[i].isPrint == true) {
							wordInStage[i].y++;
						}
					}

					for (int i = 0; i < WORD_IN_STAGE; i++) { // isPrint���� true�� �ܾ� ���
						if (wordInStage[i].isPrint == true) {
							gotoxy(wordInStage[i].x, wordInStage[i].y);
							setColor(YELLOW);
							printf("%s", wordInStage[i].text);
							setColor(YELLOW);
						}
					}

					for (int i = 0; i < WORD_IN_STAGE; i++) { // ������ ���̴� ����
						if (wordInStage[i].y == 22 && wordInStage[i].isPrint == true) { // �ٴڿ� �����ϸ� life--;
							gameStatus->life--;

							wordInStage[i].isPrint = false; // �ٴڿ� �����ϸ� �� �̻� ������ �ʵ��� ����

							clearStatus();
							printStatus(gameStatus);
							printDoubleBorderLine();
						}
					}

					gameStatus->updateCount++;
				}

				// �ܾ� �Է� �κ�
				while (_kbhit()) {
					int keyboardInput = _getch(); // Ű���� �� �Է¹���

					if (keyboardInput == BACKSPACE && inputX != 9) { // Ŀ���� �� �տ� ���� ���� �� �齺���̽� �Է� �� �ѱ��� ����
						_getch(); // �� ����Ʈ ������
						gotoxy(--inputX, inputY); printf(" ");
						iterator--;
					}
					else if (keyboardInput == BACKSPACE && inputX == 9) { // Ŀ�� �� �տ� ������ �齺���̽� ����
						_getch(); // �� ����Ʈ ������
					}
					else if (keyboardInput == SPACEBAR) { // �����̽��� �Է� ����
						_getch(); // �� ����Ʈ ������
					}
					else if (keyboardInput == ARROW) { // ������ ����Ű �Է� �� �������� �� �ٸ� ����Ű�� ����
						keyboardInput = _getch();
						
						if (keyboardInput == LEFT_ARROW) {
							gameStatus->life = 0;
						}
						else {
							// empty!!
						}
					}
					else if (keyboardInput == ENTER) { // ���� �Է� ��
						_getch(); // �� ����Ʈ ������
						// ���� ���� ������� ���ʹ����� �Է¹��� �ʱ�ȭ
						inputX = 9; inputY = 24;
						gotoxy(inputX, inputY); printf("                  ");

						// ���� �˻�
						inputBuffer[iterator] = (char)NULL; // �Էµ� ���ڵ��� ������ ���ڿ��� �νĽ�Ű�� ���� �� �ڿ� '\0'�� �־���
						for (int i = 0; i < WORD_IN_STAGE; i++) {
							if (strcmp(inputBuffer, wordInStage[i].text) == 0 && wordInStage[i].isPrint == true) { // �̹� ���� �ܾ �� �Է����� �� �ߺ� ������ �����ϱ� ���� isPrint���� true�� �ܾ ���� �˻�)
								gameStatus->score += 10;
								clearStatus();
								printStatus(gameStatus);

								gameStatus->correctAnswer++;
								wordInStage[i].isPrint = false; // ���߸� isPrint���� false�� �����Ͽ� �� �̻� ������ �ʵ��� ��

								PlaySound(TEXT(SOUND_CORRECT), NULL, SND_FILENAME | SND_ASYNC); // correct.wav ���

								// �ܾ� �� ���(������Ʈ�� ���� �Ǵ� �� ó�� ���̰� �ϱ� ����)
								clearBoard();
								for (int j = 0; j < WORD_IN_STAGE; j++) { // isPrint���� true�� �ܾ� ���
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

						// �Է� ���� �ʱ�ȭ
						for (int i = 0; i < INPUT_BUFFER; i++) {
							inputBuffer[i] = (char)NULL;
						}
						iterator = 0;
					}
					else if (inputX < 18) { // �ܾ� �Է�(x ��ǥ�� 18 �̻��̸� �� �̻� �Էµ��� �ʵ��� ����)
						_getch(); // �� ����Ʈ ������

						setColor(YELLOW);
						gotoxy(inputX, inputY); printf("%c", keyboardInput);
						setColor(WHITE);
						inputX++;

						if (iterator < INPUT_BUFFER) {
							inputBuffer[iterator] = keyboardInput;
							if (iterator != INPUT_BUFFER - 1) {
								iterator++;
							}
						}
					}
					else {
						_getch(); // �� ����Ʈ ������
					}
				}//while (_kbhit( ))
			}//while(true)
		}//else
	}//while(true)
}//void gameStart( )
