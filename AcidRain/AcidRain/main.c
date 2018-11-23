// AcidRain C console game. Made by youseokhwan.
// https://github.com/youseokhwan/AcidRainGame
// 18.11.18 v1.0 기능구현 완료
// 18.11.20 v1.1 UI 업데이트
// 18.11.21 v1.2 단어 간격 조정 및 도움말 업데이트
// 18.11.21 v1.3 개발자 설정 업데이트
// 18.11.21 v1.3.1 dropSpeed 관련 hotfix, Use safety function
// 18.11.21 v1.3.2 log 페이지 업데이트
// 18.11.22 v1.3.3 도움말 GUI 업데이트
// 18.11.23 v1.3.4 주석 수정 및 코드 가독성 보완

#include "console.h"

int main(int argc, char* argv[]) {
	/*
		여러 소스파일에서 참조하기 위해 struct들을 포인터로 선언

		gameStatus: 스테이지, 라이프, 점수 등 총괄
		record: 랭킹 등록 시 사용
		settingValue: 설정 값 유지하기 위해 사용
	*/
	struct _gameStatus gs;
	struct _gameStatus* gameStatus = &gs;

	struct _record rc[RECORD];
	struct _record* record = &rc[0];

	struct _settingValue sv = { 1, 0 }; // 초기 설정(커서 숨기기, 낙하속도 일반)
	struct _settingValue* settingValue = &sv;
	
	/*
		title 및 콘솔 사이즈 변경
	*/
	consoleSetting(gameStatus);
	addLog("start a program\n", false); // 로그 추가

	/*
		mi는 가리키고 있는 메뉴의 인덱스
		GUI 구현하기 위해 포인터로 선언하여 console.c에서 참조
	*/
	int mi = 0;
	int* menuIndex = &mi;

	while (true) {
		int userSelect = mainMenu(menuIndex);

		switch (userSelect) {
		case 0: // 게임시작
			gameStart(record, gameStatus);
			break;
		case 1: // 랭킹
			rankingFromMenu(record);
			break;
		case 2: // 도움말
			printHelp();
			break;
		case 3: // 로그보기
			showLog();
			break;
		case 4: // 개발자 설정
			setting(settingValue, gameStatus);
			break;
		case 5: // 끝내기
			system("cls");
			gotoxy(0, 0); printf("※ 게임을 종료합니다.\n");
			gotoxy(0, 2);

			addLog("end a program\n", false); // 로그 추가
			exit(0); // 프로그램 종료
		default: // 잘못된 입력 시 실행
			gotoxy(0, 9); printf("※ 잘못된 입력입니다.");
			system("pause>nul");
		}
	}

	return 0;
}
