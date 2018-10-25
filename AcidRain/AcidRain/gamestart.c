#include "gamestart.h"

void gameStart() {
	system("cls");
	int theSpeedOfWordDrop[MAX_STAGE] = { 1000, 700, 650, 600, 550, 500, 450, 400, 350, 300 }; // 단어 떨어지는 스피드 조절

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
		clearBoard(); // 화면 지우기
		printStatus(); // 스테이지, 라이프, 점수 출력
		printBorderLine(); // 경계선 출력
		printPrompt(); // 유저 입력창 출력

		if (gameStatus.life == 0) { // 라이프 0으로 죽음
			gotoxy(0, 2); printf("Game Over!!\n");
			gotoxy(0, 3); printf("클리어한 스테이지: %d / 최종 스코어: %d", gameStatus.stage-1, gameStatus.score);
			system("pause>nul");

			rankingFromGame();

			break;
		}

		if (gameStatus.stage > MAX_STAGE) { // 모든 스테이지 클리어
			gotoxy(0, 2); printf("모든 스테이지를 클리어하였습니다!!\n");
			gotoxy(0, 3); printf("최종 스코어: %d", --gameStatus.score);
			system("pause>null");

			rankingFromGame();

			break;
		}

		if (gameStatus.correctAnswerCount == THE_NUMBER_OF_WORDS_IN_STAGE) { // 단어를 모두 입력하면 다음 스테이지로 넘어감
			gameStatus.score += gameStatus.stage * 100; // 클리어 시 스테이지*100 만큼 점수 증가
			gotoxy(0, 2); printf("스테이지 %d 클리어!!\n", gameStatus.stage++);
			system("pause>nul");
		}

		// (단어 다 맞추진 못함 && 죽진 않았을 시) 다음 스테이지 진입
		for (int i = 0; i < THE_NUMBER_OF_WORDS_IN_STAGE; i++) {
			if (wordInCurrentStage[i].isPrint == false) {
				gameStatus.isPrintCount++;
			}
		}

		if (gameStatus.pulseCount > 10) { // 단어 10개가 모두 출력된 이후
			if (gameStatus.isPrintCount == THE_NUMBER_OF_WORDS_IN_STAGE) {
				gameStatus.score += gameStatus.stage * 100; // 클리어 시 스테이지*100 만큼 점수 증가
				gotoxy(0, 2); printf("Stage %d Clear!!\n", gameStatus.stage++);
				system("pause>nul");
			}
			else {
				gameStatus.isPrintCount = 0;
			}
		}

		// 현재 스테이지 단어 추출
		srand((unsigned int)time(NULL)); // 난수 시드값
		for (int i = 0; i < THE_NUMBER_OF_WORDS_IN_STAGE; i++) { // 전체 리스트에서 현재 스테이지에 쓸 단어 난수 추출
			wordInCurrentStage[i].word = wordList[rand() % THE_NUMBER_OF_WORDS];
			for (int j = 0; j < i; j++) {
				if (strcmp(wordInCurrentStage[i].word, wordInCurrentStage[j].word) == 0) { // 중복 검사
					i--;
					break;
				}
			}
			
			wordInCurrentStage[i].isPrint = false;
			wordInCurrentStage[i].x = (rand() % 56) + 1; // 해당 언어의 랜덤 x값 지정
			wordInCurrentStage[i].y = 2;
		}

		// 단어 출력 구현
		// 단어 입력 구현
	}
}