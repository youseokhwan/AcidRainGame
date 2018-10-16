#include <stdio.h>
#include <pthread.h>
#include <Windows.h>

void* addThreadFunction(void* arg);
void* subThreadFunction(void* arg);

int main(void) {
	int a = 0;
	int* num = &a;

	int status; // pthread_join( ) 에 사용되는 인자

	pthread_t addThread, subThread;

	printf("숫자가 5나 -5에 도달하면 종료됩니다.\n");
	printf("아무 키나 누르면 시작합니다.\n");

	system("pause");
	system("cls");

	pthread_create(&addThread, NULL, addThreadFunction, (void*)num);
	pthread_create(&subThread, NULL, subThreadFunction, (void*)num);

	pthread_join(addThread, (void**)&status);
	pthread_join(subThread, (void**)&status);

	printf("Main함수 종료합니다.\n");
	system("pause");

	return 0;
}

void* addThreadFunction(void* arg) {
	int* _num = (int*)arg;

	while (1) {
		if (*(_num) == 5) {
			printf("5 도달!\n");
			break;
		}
		else if (*(_num) == -5) {
			break;
		}
		(*(_num))++;
		printf("+++ 쓰레드 실행 / 현재 num값은 >> %d\n", *(_num));
		Sleep(800);
	}

	return NULL;
}

void* subThreadFunction(void* arg) {
	int* _num = (int*)arg;

	while (1) {
		if (*(_num) == -5) {
			printf("-5 도달!\n");
			break;
		}
		else if (*(_num) == 5) {
			break;
		}
		(*(_num))--;
		printf("--- 쓰레드 실행 / 현재 num값은 >> %d\n", *(_num));
		Sleep(1500);
	}

	return NULL;
}