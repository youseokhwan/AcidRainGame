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
		return _getch(); // 입력된 값 리턴
	}

	return '\0'; // 입력값이 없으면 NULL값 리턴
}