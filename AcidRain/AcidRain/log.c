#include "log.h"

void showLog() { // �α׺���
	system("cls");
	PlaySound(TEXT(SOUND_SELECT), NULL, SND_FILENAME | SND_ASYNC);

	gotoxy(0, 0); printf("<< Log >>");
	gotoxy(0, 2); printf("�ΰ� ���(���� ������Ʈ)");

	system("pause>nul");
}