#include "gamestart.h"

void gameStart() {
	system("cls");
	// int theSpeedOfWordDrop[MAX_STAGE] = { 1000, 700, 650, 600, 550, 500, 450, 400, 350, 300 }; // 단어 떨어지는 스피드 조절

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
	gameStatus.correctAnswerCount = 0;
	gameStatus.printCount = 0;

	while (true) {
		int pulse = 0;
		gameStatus.updateCount = 0;

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

		// 현재 스테이지 단어 추출
		srand((unsigned int)time(NULL)); // 난수 시드값
		for (int i = 0; i < THE_NUMBER_OF_WORDS_IN_STAGE; i++) { // 전체 리스트에서 현재 스테이지에 쓸 단어 난수 추출
			wordInStage[i].word = wordList[rand() % THE_NUMBER_OF_WORDS];
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

		gotoxy(0, 2); printf("스테이지 %d 시작!!", gameStatus.stage);
		system("pause>nul");

		while (true) {
			pulse++;
			if (pulse % 50000000000 == 0) {
				gameStatus.updateCount++;
			}

			// 단어 모두 정답이면 -> stage*100만큼 score증가 / 스테이지 %d 클리어 출력 / stage++ / continue
			if (gameStatus.correctAnswerCount == THE_NUMBER_OF_WORDS_IN_STAGE) {
				gameStatus.score += gameStatus.stage * 100;
				gotoxy(0, 2); printf("스테이지 %d 클리어!!", gameStatus.stage++);
				gameStatus.correctAnswerCount = 0;
				system("pause>nul");

				break;
			}

			// (단어 다 맞추진 못함 && 죽진 않았을 시) 위에랑 똑같이 구현
			for (int i = 0; i < THE_NUMBER_OF_WORDS_IN_STAGE; i++) {
				if (wordInStage[i].isPrint == false) {
					gameStatus.printCount++;
				}
			}

			if (gameStatus.updateCount > THE_NUMBER_OF_WORDS_IN_STAGE) {
				if (gameStatus.printCount == THE_NUMBER_OF_WORDS_IN_STAGE) {
					gameStatus.score += gameStatus.stage * 100;
					gotoxy(0, 2); printf("스테이지 %d 클리어!!\n", gameStatus.stage++);
					system("pause>nul");

					break;
				}
				else {
					gameStatus.printCount = 0;
				}
			}
			
			if (gameStatus.life == 0) {
				break;
			}

			// 단어 출력 구현
			wordInStage[gameStatus.updateCount].isPrint = true;

			for (int i = 0; i < THE_NUMBER_OF_WORDS_IN_STAGE; i++) { // isPrint값이 true면 단어 출력
				if (wordInStage[i].isPrint == true) {
					gotoxy(wordInStage[i].x, wordInStage[i].y);
					printf("%s", wordInStage[i].word);
				}
			}

			for (int i = 0; i <= gameStatus.updateCount; i++) { // 출력된 단어들 y값 ++
				wordInStage[i].y++;
			}

			for (int i = 0; i < THE_NUMBER_OF_WORDS_IN_STAGE; i++) { // 라이프 깎이는 조건
				if (wordInStage[i].y == 22 && wordInStage[i].isPrint == true) { // 바닥에 도달하면 life--; isPrint 값을 false로 변경
					gameStatus.life--;

					wordInStage[i].isPrint = false;
				}
			}

			// 단어 입력 구현


		}
	}
}