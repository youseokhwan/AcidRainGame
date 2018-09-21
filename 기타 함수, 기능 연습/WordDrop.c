//#include <stdio.h>
//#include <Windows.h> // system("cls"), system("pause"), Sleep( ) 사용
//#include <stdlib.h> // rand( ) 사용
//#include <time.h> // srand( ) 사용
//
//struct word {
//	char* name;
//	int dropCount; // 맨 위(0)으로부터의 현재 위치 -> 숫자가 높을수록 밑으로, 최대 9까지, 10이면 종료
//};
//
//void wordPrint(struct word _WORD);
//
//int main(void) {
//	srand(time(NULL));
//
//	struct word testWord;
//	testWord.name = "test";
//	testWord.dropCount = 0;
//
//	wordPrint(testWord);
//
//	system("pause");
//
//	return 0;
//}
//
//void wordPrint(struct word _WORD) {
//	int leftSpaceCount = rand() % 30;
//
//	while (1) {
//		if (_WORD.dropCount == 10) {
//			break;
//		}
//
//		system("cls");
//
//		for (int i = 0; i < _WORD.dropCount; i++) {
//			printf("\n");
//		}
//		for (int i = 0; i < leftSpaceCount; i++) {
//			printf(" ");
//		}
//		printf("%s", _WORD.name);
//
//		_WORD.dropCount++;
//
//		Sleep(1000);
//	}
//
//	printf("\n");
//}