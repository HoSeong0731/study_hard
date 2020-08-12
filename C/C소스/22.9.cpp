#include <stdio.h>	//입출력 헤더파일 
#include <math.h>	//수학관련 헤더파일 

struct employe	//employe 라는 이름의 구조체 선언
{
	char name[20];	//이름 저장
	char num[20];	//번호 저장
	int money;	//급여 저장
};

int main()
{
	struct employe p;	//구조체 변수 선언

	printf("종업원 이름:");
	scanf("%s", p.name);//p라는 멤버 name 출력
	printf("주민등록 번호:"); 
	scanf("%s", p.num);//p라는 멤버 num 출력
	printf("급여정보:"); 
	scanf("%d", &(p.money));//p라는 멤버 money 출력
	
	printf("\n");	//개행  
	printf("이름: %s, 주민번호: %s, 급여: %d", p.name, p.num, p.money);	//출력 
	return 0;	//메인함수 종료 
}

