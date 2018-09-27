#include <stdio.h>
#include <conio.h>
#include <pthread.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "gamestart.h"

void gotoxy(int x, int y) {
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

void gameStart() {
	// ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ TEST ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
	printf("gameStart() 함수가 정상적으로 실행됨\n");
	// ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ TEST ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲

	// 전체 단어 리스트 생성
	char* wordList[50] = { "art", "able", "acid", "about", "air", "aim", "also", "ant", "arm", "army",
						"ball", "blue", "bag", "band", "beat", "beef", "belt", "bill", "bike", "boat",
						"cafe", "cake", "call", "camp", "camo", "care", "case", "cave", "cat", "chef",
						"data", "dark", "day", "deer", "deep", "dog", "door", "draw", "drum", "drug",
						"each", "easy", "echo", "edge", "egg", "evil", "even", "exam", "eye", "else" };

	// gameStatus 생성
	struct _gameStatus gameStatus = { 5, 1, 0, 0, 0 };

	while (1) {
		system("cls");

		if (gameStatus.stage == 11) {
			gotoxy(0, 0); printf("============================================================\n");
			printf("모든 스테이지를 클리어하셨습니다!!\n");
			gotoxy(0, 20); printf("============================================================\n");
			// ranking( ) 으로 넘어가는 루틴 짜야함
			break;
		}

		// ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ 현재 스테이지 단어 초기화 ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
		struct word wordInCurrentStage[10];
		for (int i = 0; i < 10; i++) {
			wordInCurrentStage[i].word = wordList[rand() % 30]; // 전체 리스트에서 난수를 통해 현재 스테이지에 쓸 단어들 초기화
			for (int j = 0; j < i; j++) {
				if (strcmp(wordInCurrentStage[i].word, wordInCurrentStage[j].word) == 0) {
					i--;
					break;
				}
			}
		}
		for (int i = 0; i < 10; i++) {
			wordInCurrentStage[i].isPrint = 0;
			wordInCurrentStage[i].printCount = 1; // 1부터 시작해서 10에 도달하면 점수 깎임
		}
		// ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ 현재 스테이지 단어 초기화 ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲

		// ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ 스테이지 진행 ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ // 이건 다시 쓰레드와 함께 함수로 만들어야함
		gotoxy(0, 0); printf("============================================================\n");
		printf("%d단계 진행합니다!\n", gameStatus.stage);
		gotoxy(0, 20); printf("============================================================\n");
		system("pause>nul");
		// ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ 스테이지 진행 ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲

	

		gameStatus.stage++; // 스테이지 1 증가
	}


}