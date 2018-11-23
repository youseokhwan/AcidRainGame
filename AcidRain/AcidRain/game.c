#include "game.h"

//#define WORD_FILE_IO_CANCEL_FOR_TEST

/*
	게임 진행하는 함수
	단어 생성, 화면 출력, 단어 입출력, 정답 검사 등 진행
*/
void gameStart(struct _record* record, struct _gameStatus* gameStatus) {
	system("cls");
	PlaySound(TEXT(SOUND_SELECT), NULL, SND_FILENAME | SND_ASYNC); // select.wav 재생

	/*
		wordInStage 구조체 선언
		각 단어의 텍스쳐, 좌표, 출력 여부 등 정보 저장
	*/
	struct _word wordInStage[WORD_IN_STAGE];

	/*
		파일 입출력 사용하지 않음
	*/
#ifdef WORD_FILE_IO_CANCEL_FOR_TEST
	// 전체 단어 리스트 생성
	char* wordList[WORD] = { "art", "able", "acid", "about", "air", "aim", "also", "ant", "arm", "army",
		"ball", "blue", "bag", "band", "beat", "beef", "belt", "bill", "bike", "boat",
		"cafe", "cake", "call", "camp", "camo", "care", "case", "cave", "cat", "chef",
		"data", "dark", "day", "deer", "deep", "dog", "door", "draw", "drum", "drug",
		"each", "easy", "echo", "edge", "egg", "evil", "even", "exam", "eye", "else" };
#endif
	/*
		파일 입출력 사용
	*/
#ifndef WORD_FILE_IO_CANCEL_FOR_TEST
	FILE *fp;
	char fileBuffer[FILE_BUFFER];

	fopen_s(&fp, "dataFile\\word_list.txt", "rt");

	if (fp == NULL) {
		system("cls");
		gotoxy(0, 0); printf("word_list.txt 파일이 없습니다!");
		gotoxy(0, 2); printf("프로그램을 종료합니다.");
		gotoxy(0, 3);

		free(record);

		exit(1);
	}
	else {
		fgets(fileBuffer, FILE_BUFFER, fp);
	}

	fclose(fp);

	/*
		파일 입출력으로 단어 목록 받아서 토큰으로 분할하여 저장
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
		gameStatus 구조체 초기화
	*/
	gameStatus->life = 5;
	gameStatus->score = 0;
	gameStatus->stage = 1;
	gameStatus->correctAnswer = 0;
	gameStatus->printCount = 0;

	addLog("enter a game\n", false); // 로그 추가
	/*
		스테이지 진입
	*/
	while (true) {
		printStatus(gameStatus);
		printDoubleBorderLine();
		printPrompt();

		/*
			라이프 0이면 게임 종료하여 랭킹으로 진입
		*/
		if (gameStatus->life == 0) {
			clearStatus();
			clearBoard();
			clearPrompt();

			PlaySound(TEXT(SOUND_FAIL), NULL, SND_FILENAME | SND_ASYNC); // fail.wav 재생
			gotoxy(0, 2); printf("Game Over!!\n");
			gotoxy(0, 3); printf("완료한 스테이지: %d / 최종 스코어: %d", --gameStatus->stage, gameStatus->score);

			/*
				보통 죽기 직전에 급하게 타이핑을 하다가 죽는 경우가 많은데
				system("pause>nul")을 사용하면 죽자마자 연속된 키 입력으로 의도치않게 진행됨
				따라서 오른쪽 방향키를 입력해야 진행되도록 함
			*/
			gotoxy(0, 5); printf("오른쪽 방향키를 누르면 진행됩니다.");
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
				랭킹으로 진입
				ranking.c 참고
			*/
			rankingFromGame(gameStatus, record);

			break;
		}
		/*
			모든 스테이지 클리어하면 게임 종료하여 랭킹으로 진입
		*/
		else if (gameStatus->stage > STAGE) {
			clearStatus();
			clearBoard();

			PlaySound(TEXT(SOUND_ALL_CLEAR), NULL, SND_FILENAME | SND_ASYNC); // allClear.wav 재생
			gotoxy(0, 2); printf("모든 스테이지를 클리어하였습니다!!\n");
			gotoxy(0, 3); printf("최종 스코어: %d", gameStatus->score);
			gameStatus->stage--; // 현재 스테이지 값이 11이므로 1 감소
			system("pause>null");

			/*
				랭킹으로 진입
				ranking.c 참고
			*/
			rankingFromGame(gameStatus, record);

			break;
		}
		else {
			/*
				현재 스테이지에서 사용할 단어 난수 추출
			*/
			srand((unsigned int)time(NULL));
			for (int i = 0; i < WORD_IN_STAGE; i++) {
				wordInStage[i].text = wordList[rand() % WORD];
				for (int j = 0; j < i; j++) {
					if (strcmp(wordInStage[i].text, wordInStage[j].text) == 0) { // 중복 검사
						i--;
						break;
					}
				}

				wordInStage[i].isPrint = false;
				wordInStage[i].x = (rand() % 56) + 1; // 랜덤 x 좌표 지정
				wordInStage[i].y = 1;
			}

			gameStatus->updateCount = 0;
			gotoxy(0, 2); printf("스테이지 %d 시작!!", gameStatus->stage);
			system("pause>nul");

			/*
				단어 입력부에 사용할 변수 초기화
			*/
			int inputX = 9, inputY = 24;
			char inputBuffer[INPUT_BUFFER];
			int inputIndex = 0;

			for (int i = 0; i < INPUT_BUFFER; i++) {
				inputBuffer[i] = (char)NULL;
			}

			/*
				시작시간 저장
				단어 낙하속도 조절하기 위함
			*/
			gameStatus->startClock = clock();
			/*
				단어 출력 시작
			*/
			while(true) {
				/*
					라이프 0이거나 모든 스테이지 클리어하면 break
					단어 출력 while 루프 break 한 후, 상위 while 루프에서 작업 수행
				*/
				if (gameStatus->life == 0 || gameStatus->stage > STAGE) {
					break;
				}

				/*
					단어 모두 정답으로 입력하면 다음 스테이지 진행
				*/
				if (gameStatus->correctAnswer == WORD_IN_STAGE) {
					system("cls");

					PlaySound(TEXT(SOUND_STAGE_CLEAR), NULL, SND_FILENAME | SND_ASYNC); // stageClear.wav 재생

					gameStatus->score += gameStatus->stage * 100;
					gotoxy(0, 2); printf("스테이지 %d 클리어!!", gameStatus->stage++);

					gameStatus->correctAnswer = 0;
					system("pause>nul");

					break;
				}

				/*
					단어 모두 입력하지 못했지만, 죽지는 않았을 시 다음 스테이지 진행
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

						PlaySound(TEXT(SOUND_STAGE_CLEAR), NULL, SND_FILENAME | SND_ASYNC); // stageClear.wav 재생

						gotoxy(0, 2); printf("스테이지 %d 클리어!!\n", gameStatus->stage++);
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
					단어 출력 부분
					clock( ) 이용하여 낙하속도 스테이지 별로 조절
					updateCount가 짝수일때마다 단어 순서대로 출력 시작 
				*/
				if ((clock() - gameStatus->startClock) % gameStatus->dropSpeed[gameStatus->stage - 1] == 0) {
					clearBoard();

					if (gameStatus->updateCount % 2 == 0 && gameStatus->updateCount < WORD_IN_STAGE * 2) {
						wordInStage[gameStatus->updateCount / 2].isPrint = true;
					}

					/*
						단어 y값 증가하여 낙하 구현
						정답 처리된 단어가 바닥에 닿아 라이프가 감소하지 않도록 출력된 단어만 증가
					*/
					for (int i = 0; i < WORD_IN_STAGE; i++) {
						if (wordInStage[i].isPrint == true) {
							wordInStage[i].y++;
						}
					}

					/*
						isPrint값이 true인 단어만 출력
					*/
					for (int i = 0; i < WORD_IN_STAGE; i++) {
						if (wordInStage[i].isPrint == true) {
							gotoxy(wordInStage[i].x, wordInStage[i].y);
							setColor(YELLOW);
							printf("%s", wordInStage[i].text);
						}
					}

					/*
						단어가 바닥에 도달하면 라이프 감소 및 isPrint값 false로 변경
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
					단어 입력 부분
					단일 쓰레드에서 입출력을 동시에 구현하기 위해 _kbhit() 사용
					타이핑 시각효과와 불필요 키 입력 제한 위해 _getch(), inputIndex 사용
					
					<< #define ISSUE >>
					선언한 이유: 여러 PC에서 테스트한 결과 _getch()에서 문제가 생기는 PC와 그렇지 않은 PC 존재함(원인 파악 못함)
					만약 두 번 눌러야 인식이 된다면 이 ISSUE를 주석 해제하고 실행할 것
				*/
				while (_kbhit()) {
					int keyboardInput = _getch();

					/*
						커서가 맨 앞에 있지 않고, 백스페이스 입력 시 한 글자 지움
					*/
					if (keyboardInput == BACKSPACE && inputX != 9) {
#ifndef ISSUE
						_getch(); // 입력 스트림 비우기
#endif
						gotoxy(--inputX, inputY); printf(" ");
						inputIndex--;
					}
					/*
						커서 맨 앞에 있으면, 백스페이스 입력 무시
					*/
					else if (keyboardInput == BACKSPACE && inputX == 9) {
#ifndef ISSUE
						_getch(); // 입력 스트림 비우기
#endif
					}
					/*
						스페이스바 입력 무시
					*/
					else if (keyboardInput == SPACEBAR) {
#ifndef ISSUE
						_getch(); // 입력 스트림 비우기
#endif
					}
					/*
						왼쪽 방향키 입력 시 즉시 게임오버
						다른 방향키 누를 시 쓰레기값 입력 방지
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
						엔터키 입력 시
						정답 검사 후 gameStatus값 조정
						정답 여부 관계없이 Input창 지우기
					*/
					else if (keyboardInput == ENTER) {
#ifndef ISSUE
						_getch(); // 입력 스트림 비우기
#endif
						inputX = 9; inputY = 24;
						gotoxy(inputX, inputY); printf("                  ");

						inputBuffer[inputIndex] = (char)NULL;
						for (int i = 0; i < WORD_IN_STAGE; i++) {
							/*
								이미 정답처리 된 단어나 아직 출력되지 않은 단어를 입력했을 시 정답처리하지 않기 위해
								isPrint가 true인 단어에 한해 검사
							*/
							if (strcmp(inputBuffer, wordInStage[i].text) == 0 && wordInStage[i].isPrint == true) {
								gameStatus->score += 10;
								clearStatus();
								printStatus(gameStatus);

								gameStatus->correctAnswer++;
								wordInStage[i].isPrint = false;

								PlaySound(TEXT(SOUND_CORRECT), NULL, SND_FILENAME | SND_ASYNC); // correct.wav 출력

								/*
									매끄러운 애니메이션 위해 단어 한번 더 출력
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
							입력 부분 버퍼 초기화
						*/
						for (int i = 0; i < INPUT_BUFFER; i++) {
							inputBuffer[i] = (char)NULL;
						}
						inputIndex = 0;
					}
					/*
						단어 문자 입력
					*/
					else if (inputX < 18) {
#ifndef ISSUE
						_getch(); // 입력 스트림 비우기
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
						_getch(); // 입력 스트림 비우기
#endif
					}
				}
			}
		}
	}
}
