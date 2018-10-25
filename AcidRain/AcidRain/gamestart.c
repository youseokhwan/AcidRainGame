#include "gamestart.h"

void gameStart() {
	system("cls");
	int theSpeedOfWordDrop[MAX_STAGE] = { 1000, 700, 650, 600, 550, 500, 450, 400, 350, 300 }; // �ܾ� �������� ���ǵ� ����

	// ��ü �ܾ� ����Ʈ ����
	char* wordList[THE_NUMBER_OF_WORDS] = { "art", "able", "acid", "about", "air", "aim", "also", "ant", "arm", "army",
		"ball", "blue", "bag", "band", "beat", "beef", "belt", "bill", "bike", "boat",
		"cafe", "cake", "call", "camp", "camo", "care", "case", "cave", "cat", "chef",
		"data", "dark", "day", "deer", "deep", "dog", "door", "draw", "drum", "drug",
		"each", "easy", "echo", "edge", "egg", "evil", "even", "exam", "eye", "else" }; // ���߿� ���� ��������� �ٽ� ����

	// gameStatus �ʱ�ȭ
	gameStatus.life = 5;
	gameStatus.score = 0;
	gameStatus.stage = 1;

	while (true) {
		clearBoard(); // ȭ�� �����
		printStatus(); // ��������, ������, ���� ���
		printBorderLine(); // ��輱 ���
		printPrompt(); // ���� �Է�â ���

		if (gameStatus.life == 0) { // ������ 0���� ����
			gotoxy(0, 2); printf("Game Over!!\n");
			gotoxy(0, 3); printf("Ŭ������ ��������: %d / ���� ���ھ�: %d", gameStatus.stage-1, gameStatus.score);
			system("pause>nul");

			rankingFromGame();

			break;
		}

		if (gameStatus.stage > MAX_STAGE) { // ��� �������� Ŭ����
			gotoxy(0, 2); printf("��� ���������� Ŭ�����Ͽ����ϴ�!!\n");
			gotoxy(0, 3); printf("���� ���ھ�: %d", --gameStatus.score);
			system("pause>null");

			rankingFromGame();

			break;
		}

		if (gameStatus.correctAnswerCount == THE_NUMBER_OF_WORDS_IN_STAGE) { // �ܾ ��� �Է��ϸ� ���� ���������� �Ѿ
			gameStatus.score += gameStatus.stage * 100; // Ŭ���� �� ��������*100 ��ŭ ���� ����
			gotoxy(0, 2); printf("�������� %d Ŭ����!!\n", gameStatus.stage++);
			system("pause>nul");
		}

		// (�ܾ� �� ������ ���� && ���� �ʾ��� ��) ���� �������� ����
		for (int i = 0; i < THE_NUMBER_OF_WORDS_IN_STAGE; i++) {
			if (wordInCurrentStage[i].isPrint == false) {
				gameStatus.isPrintCount++;
			}
		}

		if (gameStatus.pulseCount > 10) { // �ܾ� 10���� ��� ��µ� ����
			if (gameStatus.isPrintCount == THE_NUMBER_OF_WORDS_IN_STAGE) {
				gameStatus.score += gameStatus.stage * 100; // Ŭ���� �� ��������*100 ��ŭ ���� ����
				gotoxy(0, 2); printf("Stage %d Clear!!\n", gameStatus.stage++);
				system("pause>nul");
			}
			else {
				gameStatus.isPrintCount = 0;
			}
		}

		// ���� �������� �ܾ� ����
		srand((unsigned int)time(NULL)); // ���� �õ尪
		for (int i = 0; i < THE_NUMBER_OF_WORDS_IN_STAGE; i++) { // ��ü ����Ʈ���� ���� ���������� �� �ܾ� ���� ����
			wordInCurrentStage[i].word = wordList[rand() % THE_NUMBER_OF_WORDS];
			for (int j = 0; j < i; j++) {
				if (strcmp(wordInCurrentStage[i].word, wordInCurrentStage[j].word) == 0) { // �ߺ� �˻�
					i--;
					break;
				}
			}
			
			wordInCurrentStage[i].isPrint = false;
			wordInCurrentStage[i].x = (rand() % 56) + 1; // �ش� ����� ���� x�� ����
			wordInCurrentStage[i].y = 2;
		}

		// �ܾ� ��� ����
		// �ܾ� �Է� ����
	}
}