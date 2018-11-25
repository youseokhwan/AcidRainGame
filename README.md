# AcidRainGame
㈜한글과컴퓨터 한컴타자연습의 산성비를 모방한 C 콘솔게임

> 1. 내려오는 단어를 타이핑하여 없애는 게임입니다.
> 2. 단어가 바닥까지 내려올 경우 라이프를 잃습니다.
> 3. 총 10개의 스테이지로 구성되어 있습니다.

* 개발 환경
> 1. Windows 10 64bit 환경에서 개발 및 테스트하였습니다.
> 2. C Language / Visual Studio 2017 Community

* 버전 정보
> 18.11.18 v1.0 기능 구현 완료<br>
> 18.11.20 v1.1 UI 업데이트<br>
> 18.11.21 v1.2 단어 간격 조정 및 도움말 업데이트<br>
> 18.11.21 v1.3 개발자 설정 업데이트<br>
> 18.11.21 v1.3.1 dropSpeed 관련 수정, safety 함수 수정<br>
> 18.11.21 v1.3.2 log 페이지 업데이트<br>
> 18.11.22 v1.3.3 도움말 GUI 업데이트<br>
> 18.11.23 v1.3.4 주석 수정 및 코드 가독성 보완<br>
> 18.11.25 v1.3.5 이름 등록 UI 추가<br>

* 한계점 및 issue
> 1. 영어 소문자로만 구현 -> 한글 구현 시 입력 바이트 처리 오류
> 2. 콘솔 종료하면 랭킹 정보 초기화 -> 파일 입출력으로 보완해야 함
> 3. PC마다 getch( ) 인식이 다름(?) -> 두 번 입력해야 입력되는 ISSUE<br>
> 모든 환경에서 그런 것은 아니며 문제 발생 시 "#define issue"를 주석 해제하면 임시 해결<br>
> (그러나 단어 낙하 부분에서 버그 발생함)

* 스크린샷<br>

<img src="https://i.imgur.com/kUTPYI1.png" width="410" height="346"> <img src="https://i.imgur.com/oway0Y2.png" width="410" height="346">

> [exe파일](https://github.com/youseokhwan/AcidRainGame/blob/master/AcidRain/AcidRain/download/AcidRain.zip?raw=true)
