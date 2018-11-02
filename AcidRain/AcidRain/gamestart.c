#include "gamestart.h"

void gameStart() {
	system("cls");
	// int theSpeedOfWordDrop[MAX_STAGE] = { 1000, 700, 650, 600, 550, 500, 450, 400, 350, 300 }; // �ܾ� �������� ���ǵ� ����

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
	gameStatus.correctAnswerCount = 0;
	gameStatus.printCount = 0;

	while (true) {
		int pulse = 0;
		gameStatus.updateCount = 0;

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

		// ���� �������� �ܾ� ����
		srand((unsigned int)time(NULL)); // ���� �õ尪
		for (int i = 0; i < THE_NUMBER_OF_WORDS_IN_STAGE; i++) { // ��ü ����Ʈ���� ���� ���������� �� �ܾ� ���� ����
			wordInStage[i].word = wordList[rand() % THE_NUMBER_OF_WORDS];
			for (int j = 0; j < i; j++) {
				if (strcmp(wordInStage[i].word, wordInStage[j].word) == 0) { // �ߺ� �˻�
					i--;

					break;
				}
			}

			wordInStage[i].isPrint = false;
			wordInStage[i].x = (rand() % 56) + 1; // �ش� ����� ���� x�� ����
			wordInStage[i].y = 2;
		}

		gotoxy(0, 2); printf("�������� %d ����!!", gameStatus.stage);
		system("pause>nul");

		while (true) {
			pulse++;
			if (pulse % 50000000000 == 0) {
				gameStatus.updateCount++;
			}

			// �ܾ� ��� �����̸� -> stage*100��ŭ score���� / �������� %d Ŭ���� ��� / stage++ / continue
			if (gameStatus.correctAnswerCount == THE_NUMBER_OF_WORDS_IN_STAGE) {
				gameStatus.score += gameStatus.stage * 100;
				gotoxy(0, 2); printf("�������� %d Ŭ����!!", gameStatus.stage++);
				gameStatus.correctAnswerCount = 0;
				system("pause>nul");

				break;
			}

			// (�ܾ� �� ������ ���� && ���� �ʾ��� ��) ������ �Ȱ��� ����
			for (int i = 0; i < THE_NUMBER_OF_WORDS_IN_STAGE; i++) {
				if (wordInStage[i].isPrint == false) {
					gameStatus.printCount++;
				}
			}

			if (gameStatus.updateCount > THE_NUMBER_OF_WORDS_IN_STAGE) {
				if (gameStatus.printCount == THE_NUMBER_OF_WORDS_IN_STAGE) {
					gameStatus.score += gameStatus.stage * 100;
					gotoxy(0, 2); printf("�������� %d Ŭ����!!\n", gameStatus.stage++);
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

			// �ܾ� ��� ����
			wordInStage[gameStatus.updateCount].isPrint = true;

			for (int i = 0; i < THE_NUMBER_OF_WORDS_IN_STAGE; i++) { // isPrint���� true�� �ܾ� ���
				if (wordInStage[i].isPrint == true) {
					gotoxy(wordInStage[i].x, wordInStage[i].y);
					printf("%s", wordInStage[i].word);
				}
			}

			for (int i = 0; i <= gameStatus.updateCount; i++) { // ��µ� �ܾ�� y�� ++
				wordInStage[i].y++;
			}

			for (int i = 0; i < THE_NUMBER_OF_WORDS_IN_STAGE; i++) { // ������ ���̴� ����
				if (wordInStage[i].y == 22 && wordInStage[i].isPrint == true) { // �ٴڿ� �����ϸ� life--; isPrint ���� false�� ����
					gameStatus.life--;

					wordInStage[i].isPrint = false;
				}
			}

			// �ܾ� �Է� ����


		}
	}
}