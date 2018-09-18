#ifndef __GAMESTART_H__
#define __GAMESTART_H__

void gameStart(); // 게임시작 눌렀을 때 진입하는 함수

struct gameStatus {
	int leftLife; // 남은 목숨(최초 5개)
	int stage;
	int score;
	int correctInputCount; // 올바르게 입력한 횟수
	int notCorrectInputCount; // 올바르지않게 입력한 횟수
};

struct word {
	char* wordName;
	int currentLocation; // 0부터 시작해서 10되면 라이프 감소하는 알고리즘
};

#endif