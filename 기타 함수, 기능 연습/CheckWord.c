#include <stdio.h>
#include <conio.h>

char getKey();

int main(void) {
	//char* testWord = "test";
	//char* userInput = "";

	char key;
	while (1) {
		key = getKey();
		if (key != '\0') {
			printf("%c", key);
		}
	}

	return 0;
}

char getKey() {
	if (_kbhit()) {
		return _getch(); // �Էµ� �� ����
	}

	return '\0'; // �Է°��� ������ NULL�� ����
}