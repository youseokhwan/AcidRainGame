#include "gamestart.h"
#include "consoleprint.h"

// ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ 쓰레드에 사용할 함수 정의 ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
void* topThreadFunc(void* arg) {

	int theSpeedOfWordDrop[MAX_STAGE] = { 1200, 1000, 900, 800, 750, 700, 650, 600, 550, 200 }; // 단어 떨어지는 스피드 조절
	int pulseCount = 0; // 단어 내려가는 작업이 진행된 횟수
	gameStatus.correctInputCountInStage = 0; // 유저가 해당 스테이지에서 맞춘 정답의 개수
	
	srand(time(NULL)); // 난수 시드값
	for (int i = 0; i < THE_NUMBER_OF_WORDS_IN_STAGE; i++) { // 해당 언어의 랜덤 x값 지정
		wordInCurrentStage[i].x = (rand() % 56) + 1;
	}

	clearBoard(); // 화면 지우기
	printStatus(); // 스테이지, 라이프, 점수 출력
	printUpAndDownBorderLine(); // 경계선 출력
	printPrompt(); // 유저 입력창 출력
	gotoxy(0, 2);  printf("Stage %d START!!", gameStatus.stage);
	system("pause>nul");

	while (true) {
		clearBoard(); // 화면 지우기
		printStatus(); // 스테이지, 라이프, 점수 출력
		printUpAndDownBorderLine(); // 경계선 출력
		printPrompt(); // 유저 입력창 출력

		if (gameStatus.life == 0) { // 남은 목숨이 0이면 게임 종료 및 ranking( ) 실행
			gotoxy(0, 2); printf("Game Over!!\n");
			system("pause>nul");

			// ranking( ) 실행
			break;
		}

		if (gameStatus.correctInputCountInStage == THE_NUMBER_OF_WORDS_IN_STAGE) { // 단어를 모두 입력하면 다음 스테이지로 넘어감
			gameStatus.score += gameStatus.stage * 100; // 클리어 시 스테이지*100 만큼 점수 증가
			gotoxy(0, 2); printf("%d 스테이지 클리어!!\n", gameStatus.stage);
			system("pause>nul");

			break;
		}

		wordInCurrentStage[pulseCount].isPrint = true; // 단어 하나씩 isPrint값 true로 변경

		for (int i = 0; i < THE_NUMBER_OF_WORDS_IN_STAGE; i++) { // isPrint값이 true면 단어 출력
			if (wordInCurrentStage[i].isPrint == true) {
				gotoxy(wordInCurrentStage[i].x, wordInCurrentStage[i].y);
				printf("%s", wordInCurrentStage[i].word);
			}
		}

		for (int i = 0; i <= pulseCount; i++) { // 출력된 단어들 y값 ++
			wordInCurrentStage[i].y++;

			if (wordInCurrentStage[i].y == 22 && wordInCurrentStage[i].isPrint == true) { // 바닥에 도달하면 isPrint 값을 false로 변경하고, life--;
				wordInCurrentStage[i].isPrint = false;
				gameStatus.life--;
			}
		}

		pulseCount++;

		Sleep(theSpeedOfWordDrop[gameStatus.stage-1]); // 단어의 낙하속도 조절부
	}

	return NULL;
}

void* bottomThreadFunc(void* arg) {
	int x = 9, y = 24; // gotoxy(x, y)의 arg로 각각 사용 - 초깃값은 (10, 24)

	while (true) {
		if ((gameStatus.life == 0) || (gameStatus.correctInputCountInStage == THE_NUMBER_OF_WORDS_IN_STAGE)) { // topThread와 동시에 종료
			break;
		}

		if (_kbhit()) {
			int keyboardInput = _getch(); _getch(); // 유저 키보드 값 입력받음

			if (keyboardInput == BACKSPACE_KEY && x != 9) { // 백스페이스 구현
				gotoxy(x - 1, y);  printf(" "); // 한 글자 지우기
				x--;
			}
			else if (keyboardInput == BACKSPACE_KEY && x == 9) {
				// empty
			}
			else if (keyboardInput == SPACEBAR_KEY) {
				// empty
			}
			else if (keyboardInput == ENTER_KEY) { // 엔터키 구현
				gotoxy(9, 24); printf("                                   "); // 1) 커서 맨 앞으로 두고 문장을 다 지운다
				x = 9; y = 24; // 2) 커서를 초깃값으로 돌린다

				// 입력 버퍼 만들고 정답 맞으면 -> score++, correctAnswer++, isPrint->false
				// 정답 관계없이 엔터눌리면 버퍼 값 초기화도 해야함
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
// ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ 쓰레드에 사용할 함수 정의 ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲

void gameStart() {
	// 전체 단어 리스트 생성
	char* wordList[THE_NUMBER_OF_WORDS] = { "art", "able", "acid", "about", "air", "aim", "also", "ant", "arm", "army",
						"ball", "blue", "bag", "band", "beat", "beef", "belt", "bill", "bike", "boat",
						"cafe", "cake", "call", "camp", "camo", "care", "case", "cave", "cat", "chef",
						"data", "dark", "day", "deer", "deep", "dog", "door", "draw", "drum", "drug",
						"each", "easy", "echo", "edge", "egg", "evil", "even", "exam", "eye", "else" }; // 나중에 파일 입출력으로 다시 구성

	// gameStatus 초기화
	gameStatus.life = 5;
	gameStatus.score = 0;
	gameStatus.stage = 1;

	while (true) {
		system("cls");

		if (gameStatus.life == 0) {
			// ranking( ) 실행

			break;
		}

		if (gameStatus.stage > MAX_STAGE) { // 모든 스테이지 클리어
			printUpAndDownBorderLine();
			gotoxy(0, 2); printf("모든 스테이지를 클리어하셨습니다!!\n");

			// ranking( ) 실행

			break;
		}	

		srand(time(NULL)); // 난수 시드값
		for (int i = 0; i < THE_NUMBER_OF_WORDS_IN_STAGE; i++) { // 전체 리스트에서 현재 스테이지에 쓸 단어 난수 추출
			wordInCurrentStage[i].word = wordList[rand() % THE_NUMBER_OF_WORDS];
			for (int j = 0; j < i; j++) {
				if (strcmp(wordInCurrentStage[i].word, wordInCurrentStage[j].word) == 0) { // 중복 검사
					i--;
					break;
				}
			}
			// 나머지 제원 값 초기화
			wordInCurrentStage[i].isPrint = false;
			wordInCurrentStage[i].x = 0;
			wordInCurrentStage[i].y = 2;
		}

		int intTemp = 0;
		void* voidPointerTemp = &intTemp;

		pthread_create(&topThread, NULL, topThreadFunc, (void*)voidPointerTemp); // topThread 생성
		pthread_create(&bottomThread, NULL, bottomThreadFunc, (void*)voidPointerTemp); // bottomThread 생성

		pthread_join(topThread, (void**)&intTemp); // topThread 해제
		pthread_join(bottomThread, (void**)&intTemp); // bottomThread 해제

		gameStatus.stage++; // 스테이지 증가
	}
}