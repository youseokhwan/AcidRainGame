#include <stdio.h>
#include <pthread.h>
#include <Windows.h>

void* addThreadFunction(void* arg);
void* subThreadFunction(void* arg);

int main(void) {
	int a = 0;
	int* num = &a;

	int status; // pthread_join( ) �� ���Ǵ� ����

	pthread_t addThread, subThread;

	printf("���ڰ� 5�� -5�� �����ϸ� ����˴ϴ�.\n");
	printf("�ƹ� Ű�� ������ �����մϴ�.\n");

	system("pause");
	system("cls");

	pthread_create(&addThread, NULL, addThreadFunction, (void*)num);
	pthread_create(&subThread, NULL, subThreadFunction, (void*)num);

	pthread_join(addThread, (void**)&status);
	pthread_join(subThread, (void**)&status);

	printf("Main�Լ� �����մϴ�.\n");
	system("pause");

	return 0;
}

void* addThreadFunction(void* arg) {
	int* _num = (int*)arg;

	while (1) {
		if (*(_num) == 5) {
			printf("5 ����!\n");
			break;
		}
		else if (*(_num) == -5) {
			break;
		}
		(*(_num))++;
		printf("+++ ������ ���� / ���� num���� >> %d\n", *(_num));
		Sleep(800);
	}

	return NULL;
}

void* subThreadFunction(void* arg) {
	int* _num = (int*)arg;

	while (1) {
		if (*(_num) == -5) {
			printf("-5 ����!\n");
			break;
		}
		else if (*(_num) == 5) {
			break;
		}
		(*(_num))--;
		printf("--- ������ ���� / ���� num���� >> %d\n", *(_num));
		Sleep(1500);
	}

	return NULL;
}