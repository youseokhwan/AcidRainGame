#include "game.h"

//#define ANSWER_COUNT_TEST
//#define WORD_FILE_IO_CANCEL_FOR_TEST
//#define NORMAL_SPEED
//#define FAST_SPEED_FOR_TEST
#define SLOW_SPEED_FOR_TEST

void gameStart() { // 게임시작
	system("cls");
	PlaySound(TEXT(SOUND_SELECT), NULL, SND_FILENAME | SND_ASYNC);

#ifdef WORD_FILE_IO_CANCEL_FOR_TEST
	// 전체 단어 리스트 생성
	char* wordList[WORD] = { "art", "able", "acid", "about", "air", "aim", "also", "ant", "arm", "army",
		"ball", "blue", "bag", "band", "beat", "beef", "belt", "bill", "bike", "boat",
		"cafe", "cake", "call", "camp", "camo", "care", "case", "cave", "cat", "chef",
		"data", "dark", "day", "deer", "deep", "dog", "door", "draw", "drum", "drug",
		"each", "easy", "echo", "edge", "egg", "evil", "even", "exam", "eye", "else" };
#endif
#ifndef WORD_FILE_IO_CANCEL_FOR_TEST
	// 전체 단어 리스트 생성(파일 입출력)
	FILE *fp;
	char fileBuffer[FILE_BUFFER];

	fp = fopen("word_list.txt", "rt");
	while (!feof(fp)) {
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

	// gameStatus 초기화
	gameStatus.life = 5;
	gameStatus.score = 0;
	gameStatus.stage = 1;
	gameStatus.correctAnswer = 0;
	gameStatus.printCount = 0;
	for (int i = 0; i < STAGE; i++) { // 단어 낙하속도 조절
#ifdef NORMAL_SPEED
		gameStatus.dropSpeed[i] = 800 - 80 * i;
#endif
#ifdef FAST_SPEED_FOR_TEST
		gameStatus.dropSpeed[i] = 200;
#endif
#ifdef SLOW_SPEED_FOR_TEST
		gameStatus.dropSpeed[i] = 500;
#endif
	}

	while (true) { // 스테이지 진입
		printStatus(); // status값 출력
		printBorderLine(); // 경계선 출력
		printPrompt(); // 입력 창 출력

		if (gameStatus.life == 0) { // 라이프 0이면 게임 종료
			clearStatus();
			clearBoard();
			clearPrompt();

			PlaySound(TEXT(SOUND_FAIL), NULL, SND_FILENAME | SND_ASYNC);
			gotoxy(0, 2); printf("Game Over!!\n");
			gotoxy(0, 3); printf("완료한 스테이지: %d / 최종 스코어: %d", --gameStatus.stage, gameStatus.score);
			system("pause>nul");

			rankingFromGame(); // 랭킹으로 진입

			break;
		}
		else if (gameStatus.stage > STAGE) { // 모든 스테이지 클리어
			clearStatus();
			clearBoard();

			PlaySound(TEXT(SOUND_ALL_CLEAR), NULL, SND_FILENAME | SND_ASYNC);
			gotoxy(0, 2); printf("모든 스테이지를 클리어하였습니다!!\n");
			gotoxy(0, 3); printf("최종 스코어: %d", gameStatus.score);
			gameStatus.stage--; // 스테이지 값이 11이므로 1 감소
			system("pause>null");

			rankingFromGame(); // 랭킹으로 진입

			break;
		}
		else {
			// 현재 스테이지 단어 추출
			srand((unsigned int)time(NULL)); // 난수 시드값
			for (int i = 0; i < WORD_IN_STAGE; i++) { // 전체 리스트에서 현재 스테이지에 쓸 단어 난수 추출
				wordInStage[i].word = wordList[rand() % WORD];
				for (int j = 0; j < i; j++) {
					if (strcmp(wordInStage[i].word, wordInStage[j].word) == 0) { // 중복 검사
						i--;

						break;
					}
				}

				wordInStage[i].isPrint = false;
				wordInStage[i].x = (rand() % 56) + 1; // 해당 언어의 랜덤 x값 지정
				wordInStage[i].y = 2;
			}

			gameStatus.updateCount = 0;
			gotoxy(0, 2); printf("스테이지 %d 시작!!", gameStatus.stage);
			system("pause>nul");

			// 단어 입력부분 초깃값 설정
			int inputX = 9, inputY = 24; // 초깃값
			char inputBuffer[INPUT_BUFFER];
			int iterator = 0;

			for (int i = 0; i < INPUT_BUFFER; i++) {
				inputBuffer[i] = (char)NULL;
			}

			gameStatus.startClock = clock();
			while(true) { // 단어 출력 및 입력 구현

#ifdef ANSWER_COUNT_TEST
				gotoxy(0, 26); printf("           ");
				gotoxy(0, 26); printf("%d", gameStatus.correctAnswer1);
#endif

				// 라이프 0이거나 모든 스테이지 클리어 시 종료
				if (gameStatus.life == 0 || gameStatus.stage > STAGE) {
					// break 후 상위 while 루프에서 작업 수행

					break;
				}

				// 단어 모두 정답이면
				if (gameStatus.correctAnswer == WORD_IN_STAGE) {
					clearBoard();

					PlaySound(TEXT(SOUND_STAGE_CLEAR), NULL, SND_FILENAME | SND_ASYNC);

					gameStatus.score += gameStatus.stage * 100;
					gotoxy(0, 2); printf("스테이지 %d 클리어!!", gameStatus.stage++);

					gameStatus.correctAnswer = 0;
					system("pause>nul");

					break;
				}

				// 단어 모두 맞추지 못했지만 죽진 않았을 시
				for (int i = 0; i < WORD_IN_STAGE; i++) {
					if (wordInStage[i].isPrint == false) {
						gameStatus.printCount++;
					}
				}

				if (gameStatus.updateCount >= WORD_IN_STAGE) { // clock( ) 이용해서 바꿔야함
					if (gameStatus.printCount == WORD_IN_STAGE) {
						gameStatus.score += gameStatus.stage * 100;
						gameStatus.correctAnswer = 0;

						PlaySound(TEXT(SOUND_STAGE_CLEAR), NULL, SND_FILENAME | SND_ASYNC);

						gotoxy(0, 2); printf("스테이지 %d 클리어!!\n", gameStatus.stage++);
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

				// 단어 출력 부분
				if ((clock() - gameStatus.startClock) % gameStatus.dropSpeed[gameStatus.stage - 1] == 0) {
					clearBoard();

					if (gameStatus.updateCount <= WORD_IN_STAGE) {
						wordInStage[gameStatus.updateCount].isPrint = true;
					}

					for (int i = 0; i < WORD_IN_STAGE; i++) { // isPrint값이 true면 단어 출력
						if (wordInStage[i].isPrint == true) {
							gotoxy(wordInStage[i].x, wordInStage[i].y);
							printf("%s", wordInStage[i].word);
						}
					}

					for (int i = 0; i < WORD_IN_STAGE; i++) { // 라이프 깎이는 조건
						if (wordInStage[i].y == 22 && wordInStage[i].isPrint == true) { // 바닥에 도달하면 life--; isPrint 값을 false로 변경
							gameStatus.life--;

							wordInStage[i].isPrint = false;

							clearStatus();
							printStatus();
							printBorderLine();
						}
					}

					for (int i = 0; i <= gameStatus.updateCount; i++) { // 출력된 단어들 y값 ++
						wordInStage[i].y++;
					}

					gameStatus.updateCount++;
				}

				// 단어 입력 부분
				while (_kbhit()) {
					int keyboardInput = _getch(); _getch(); // 키보드 값 입력받음, 뒤 바이트 버리기위해 _getch() 두 번 사용

					if (keyboardInput == BACKSPACE && inputX != 9) { // 커서가 맨 앞에 있지 않을 때 백스페이스 입력 시 한글자 지움
						gotoxy(--inputX, inputY); printf(" ");
						iterator--;
					}
					else if (keyboardInput == BACKSPACE && inputX == 9) { // 커서 맨 앞에 있으면 백스페이스 무시
						// empty!!
					}
					else if (keyboardInput == SPACEBAR) { // 스페이스바 입력 무시
						// empty!!
					}
					else if (keyboardInput == ENTER) { // 엔터 입력 시
						// 정답 여부 관계없이 입력부 초기화
						inputX = 9; inputY = 24;
						gotoxy(inputX, inputY); printf("                  ");

						// 정답 검사
						inputBuffer[iterator] = (char)NULL;
						for (int i = 0; i < WORD_IN_STAGE; i++) {
							if (strcmp(inputBuffer, wordInStage[i].word) == 0 && wordInStage[i].isPrint == true) {
								gameStatus.score += 10;
								clearStatus();
								printStatus();

								gameStatus.correctAnswer++;
								wordInStage[i].isPrint = false;

								PlaySound(TEXT(SOUND_CORRECT), NULL, SND_FILENAME | SND_ASYNC);
								// 재 출력
								clearBoard();
								for (int j = 0; j < WORD_IN_STAGE; j++) { // isPrint값이 true면 단어 출력
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

						// 입력 버퍼 초기화
						for (int i = 0; i < INPUT_BUFFER; i++) {
							inputBuffer[i] = (char)NULL;
						}
						iterator = 0;
					}
					else if (inputX < 18) { // 단어 입력
						gotoxy(inputX, inputY); printf("%c", keyboardInput);
						inputX++;

						if (iterator < INPUT_BUFFER) {
							inputBuffer[iterator] = keyboardInput;
							if (iterator != INPUT_BUFFER - 1) {
								iterator++;
							}
						}
					}
					else {
						// empty!!
					}
				}//while (_kbhit( ))
			}//while(true)
		}//else
	}//while(true)
}//void gameStart( )
