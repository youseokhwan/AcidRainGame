//#include <stdio.h>
//#include <Windows.h> // system("cls"), system("pause"), Sleep( ) ���
//#include <stdlib.h> // rand( ) ���
//#include <time.h> // srand( ) ���
//
//struct word {
//	char* name;
//	int dropCount; // �� ��(0)���κ����� ���� ��ġ -> ���ڰ� �������� ������, �ִ� 9����, 10�̸� ����
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