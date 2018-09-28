#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "gamestart.h"

#define NUMBER_OF_WORD_LIST 50
#define MAX_STAGE 10
#define NUMBER_OF_WORD_IN_CURRENT_STAGE 10

void gotoxy(int x, int y) {
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

// ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ 쓰레드에 사용할 함수 정의 ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
void* topThreadFunc(void* arg) {
	printf("topThread가 정상적으로 실행됨\n");
	// Not yet completed

	return NULL;
}

void* bottomThreadFunc(void* arg) {
	Sleep(200);
	printf("bottomThread가 정상적으로 실행됨\n");
	system("pause>nul");
	// Not yet completed

	return NULL;
}
// ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ 쓰레드에 사용할 함수 정의 ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲

void gameStart() {
	// TEST
	printf("gameStart() 함수가 정상적으로 실행됨\n");


	// 전체 단어 리스트 생성
	char* wordList[NUMBER_OF_WORD_LIST] = { "art", "able", "acid", "about", "air", "aim", "also", "ant", "arm", "army",
						"ball", "blue", "bag", "band", "beat", "beef", "belt", "bill", "bike", "boat",
						"cafe", "cake", "call", "camp", "camo", "care", "case", "cave", "cat", "chef",
						"data", "dark", "day", "deer", "deep", "dog", "door", "draw", "drum", "drug",
						"each", "easy", "echo", "edge", "egg", "evil", "even", "exam", "eye", "else" }; // 나중에 파일 입출력으로 다시 구성

	// gameStatus 생성
	struct _gameStatus gameStatus = { 5, 1, 0, 0 };

	while (1) {
		system("cls");

		// ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ 모든 스테이지 클리어하면 나타나는 문구  ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
		if (gameStatus.stage > MAX_STAGE) {
			gotoxy(0, 0); printf("============================================================\n");
			printf("모든 스테이지를 클리어하셨습니다!!\n");
			gotoxy(0, 20); printf("============================================================\n");
			// ranking( ) 으로 넘어가는 루틴 짜야함
			break;
		}
		// ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ 모든 스테이지 클리어하면 나타나는 문구 ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲


		// ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ 현재 스테이지 단어 초기화 ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
		struct word wordInCurrentStage[NUMBER_OF_WORD_IN_CURRENT_STAGE];
		for (int i = 0; i < NUMBER_OF_WORD_IN_CURRENT_STAGE; i++) {
			wordInCurrentStage[i].word = wordList[rand() % NUMBER_OF_WORD_LIST]; // 전체 리스트에서 난수를 통해 현재 스테이지에 쓸 단어들 초기화
			for (int j = 0; j < i; j++) {
				if (strcmp(wordInCurrentStage[i].word, wordInCurrentStage[j].word) == 0) {
					i--;
					break;
				}
			}
			wordInCurrentStage[i].isPrint = 0;
			wordInCurrentStage[i].printCount = 1; // 1부터 시작해서 10에 도달하면 점수 깎임
		}
		// ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ 현재 스테이지 단어 초기화 ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲


		/* // 최초 테스트 과정
		// ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ 스테이지 진행 ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ // 이건 다시 쓰레드와 함께 함수로 만들어야함
		gotoxy(0, 0); printf("============================================================\n");
		printf("%d단계 진행합니다!\n", gameStatus.stage);
		gotoxy(0, 20); printf("============================================================\n");
		system("pause>nul");
		// ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ 스테이지 진행 ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
		*/


		// ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ 쓰레드 호출 ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
		intTemp = 0;
		voidPointerTemp = &intTemp;

		pthread_create(&topThread, NULL, topThreadFunc, (void*)voidPointerTemp); // topThread 생성
		pthread_create(&bottomThread, NULL, bottomThreadFunc, (void*)voidPointerTemp); // bottomThread 생성

		pthread_join(topThread, (void**)&intTemp); // topThread 해제
		pthread_join(bottomThread, (void**)&bottomThread); // bottomThread 해제
		// ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲ 쓰레드 호출 ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲


		gameStatus.stage++; // 스테이지 1 증가
	}

}