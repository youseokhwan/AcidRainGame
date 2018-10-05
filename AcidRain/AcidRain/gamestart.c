#include "gamestart.h"
#include "consoleprint.h"

// ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ 쓰레드에 사용할 함수 정의 ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
void* topThreadFunc(void* arg) {
	int theSpeedOfWordDrop[MAX_STAGE] = { 1500, 1000, 900, 800, 750, 700, 650, 600, 550, 200 }; // 단어 떨어지는 스피드 조절
	int pulseCount = 0; // 단어 내려가는 작업이 진행된 횟수
	gameStatus.correctInputCountInStage = 0; // 유저가 해당 스테이지에서 맞춘 정답의 개수
	
	for (int i = 0; i < THE_NUMBER_OF_WORDS_IN_STAGE; i++) {
		wordInCurrentStage[i].x = (rand() % 60) + 2; // 해당 단어의 랜덤 x값 지정
	}

	clearBoard(); // 화면 지우기
	printStatus(); // 스테이지, 라이프, 점수 출력
	printUpAndDownBorderLine(); // 경계선 출력
	gotoxy(0, 2);  printf("Stage %d START!!", gameStatus.stage);
	system("pause>nul");

	while (true) {
		clearBoard(); // 화면 지우기
		printStatus(); // 스테이지, 라이프, 점수 출력
		printUpAndDownBorderLine(); // 경계선 출력

		if (gameStatus.life == 0) { // 남은 목숨이 0이면 게임 종료 및 ranking( ) 실행
			gotoxy(0, 2); printf("Game Over!!\n");
			
			system("pause>nul");
			// ranking( ) 실행
			break;
		}

		if (gameStatus.correctInputCountInStage == THE_NUMBER_OF_WORDS_IN_STAGE) { // 단어를 모두 입력하면 다음 스테이지로 넘어감
			gotoxy(0, 2); printf("%d 스테이지 클리어!!\n", gameStatus.stage);

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

			if (wordInCurrentStage[i].y == 22) { // 바닥에 도달하면 isPrint 값을 false로 변경하고, life--;
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
	//Sleep(200);
	//printf("bottomThread가 정상적으로 실행됨\n");

	//struct word* _word = (struct word*)arg;

	//for (int i = 0; i < THE_NUMBER_OF_WORDS_IN_STAGE; i++) {
	//	printf("%d\n", _word[i].printCount);
	//}

	//system("pause>nul");

	//return NULL;
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
	gameStatus.correctInputCount = 0;

	while (true) {
		system("cls");

		if (gameStatus.life == 0) {
			// ranking( ) 실행

			break;
		}

		// ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ 모든 스테이지 클리어하면 나타나는 문구  ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
		if (gameStatus.stage > MAX_STAGE) {
			printUpAndDownBorderLine();
			gotoxy(0, 2); printf("모든 스테이지를 클리어하셨습니다!!\n");

			// ranking( ) 실행

			break;
		}	
		// ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ 모든 스테이지 클리어하면 나타나는 문구 ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲

		// ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ 현재 스테이지 단어 초기화 ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
		for (int i = 0; i < THE_NUMBER_OF_WORDS_IN_STAGE; i++) {
			wordInCurrentStage[i].word = wordList[rand() % THE_NUMBER_OF_WORDS]; // 전체 리스트에서 난수를 통해 현재 스테이지에 쓸 단어들 초기화
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
		// ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ 현재 스테이지 단어 초기화 ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲

		// ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ 쓰레드 호출 ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
		int intTemp = 0;
		void* voidPointerTemp = &intTemp;

		pthread_create(&topThread, NULL, topThreadFunc, (void*)voidPointerTemp); // topThread 생성
		pthread_create(&bottomThread, NULL, bottomThreadFunc, (void*)voidPointerTemp); // bottomThread 생성

		pthread_join(topThread, (void**)&intTemp); // topThread 해제
		pthread_join(bottomThread, (void**)&bottomThread); // bottomThread 해제
		// ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ 쓰레드 호출 ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲

		gameStatus.stage++; // 스테이지 증가
	}

}