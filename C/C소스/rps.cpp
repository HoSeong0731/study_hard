#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int computer(void)	//컴퓨터 세팅 함수 
{
	int sel = rand() % 3 + 1;	//랜덤값 정하기 
	if (sel == 1)
		printf("컴퓨터는 바위 선택, ");
	else if (sel == 2)
		printf("컴퓨터는 가위 선택, ");
	else
		printf("컴퓨터는 보 선택, ");

	return sel;
}

int user(void)	//유저 UI 함수 
{
	int sel;
	printf("바위는 1, 가위는 2, 보는 3 : ");
	scanf("%d", &sel);	//유저 선택 
 
	if (sel == 1)
		printf("당신은 바위 선택, ");
	else if (sel == 2)
		printf("당신은 가위 선택, ");
	else
		printf("당신은 보 선택, ");

	return sel;
}

int WhoWin(int s1, int s2)	//누가 이길지 정하는 함수
{
	if (s1 == s2)	// 무승부 
		return 0;
	else if (s1 % 3 == (s2 + 1) % 3)	// 컴퓨터 승
		return 1;
	else			// 유저 승 
		return -1;
}

int main(void) 
{
	int com, usr;	//컴퓨터와 유저선택 
	int result;		//반복문 조건 탈출 
	int win = 0, same = 0;	//승, 무를 기록 
	srand((int)time(NULL));	//랜덤값 

 	while (1)	//무한반복(조건에 맞을때 까지)
	{
		usr = user();		//유저의 선택 UI제공
		com = computer();	//컴퓨터 자동선택 
		result = WhoWin(com, usr);		//누가 이기는지 정하는 함수 실행 

		if (result == 1)
		{
			printf("당신이 이겼습니다. \n");
			win++;	//승리증가 
		}
		else if (result == -1)
		{
			printf("당신이 졌습니다. \n");
			break;	//반복문 탈출
		}
		else
		{
			printf("비겼습니다. \n");
			same++;	//무승부증가 
		}
	}
	
	printf("게임의 결과: %d승, %d무 \n", win, same);	//승률 출력 
	return 0;	//main함수종료
}
