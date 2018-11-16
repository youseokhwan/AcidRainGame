#include "log.h"

void showLog() { // 로그보기
	system("cls");
	PlaySound(TEXT(SOUND_SELECT), NULL, SND_FILENAME | SND_ASYNC);

	gotoxy(0, 0); printf("<< Log >>");
	gotoxy(0, 2); printf("로고 출력(추후 업데이트)");

	system("pause>nul");
}