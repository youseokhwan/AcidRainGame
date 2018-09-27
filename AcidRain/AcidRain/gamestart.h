#ifndef __GAMESTART_H__
#define __GAMESTART_H__

void gotoxy(int x, int y);

void gameStart(); // 게임시작 눌렀을 때 진입하는 함수

typedef struct _gameStatus {
	int leftLife; // 남은 목숨(최초 5개)
	int stage;
	int score;
	int correctInputCount; // 올바르게 입력한 횟수
	int notCorrectInputCount; // 올바르지않게 입력한 횟수
};

struct word {
	char* word; // 단어
	int isPrint; // 단어가 화면에 나타나고 있는지 여부(true가 나타남)
	int printCount; // 단어가 현재 몇 번째 줄에 위치하는지에 대한 값 
};

#endif