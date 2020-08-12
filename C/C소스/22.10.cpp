#include <stdio.h>	//입출력 헤더파일 
#include <math.h>	//수학관련 헤더파일 

struct employe	//employe라는 이름의 구조체 선언
{
	char name[20];	//이름 저장
	char num[20];	//번호 저장
	char money[20];	//급여 저장
};

int main()
{
	struct employe person[3];	//구조체 배열 선언
	int i;	//반복을 위한 변수 선언
	for (i = 0; i < 3; i++)	//각 값을 입력 받는다
	{
		printf("종업원 이름:");
		scanf("%s", person[i].name);
		printf("주민등록 번호:");
		scanf("%s", person[i].num);
		printf("급여정보:");
		scanf("%s", person[i].money);
	}
	
	for (i = 0; i < 3; i++)	//각 멤버에 접근하여 저장된 값을 출력
	{
		printf("\n%d번쨰 정보:\n",i);
		printf("이름:%s 주민등록 번호:%s 급여정보:%s  \n", person[i].name, person[i].num, person[i].money);
	}
	return 0;	//메인함수 종료  
}

