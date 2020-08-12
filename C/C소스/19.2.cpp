#include<stdio.h>	//입출력 헤더파일 포함

int WhoIsFirst(int age1, int age2, int(*cmp)(int n1,int n2))	//순서 정하는 함수  
{
	return cmp(age1, age2); //first값에 반환  
}

int OlderFirst(int age1, int age2) //인자값이 OlderFirst함수일 때 실행  
{
	if(age1>age2)	//조건문 실행후 숫자가 큰 값 반환  
		return age1;
	else if(age1<age2)
		return age2;
	else
	return 0;
}

int YoungerFirst(int age1, int age2)//인자값이 YoungerFirst함수일 때 실행    
{

	if(age1<age2)	//조건문 실행후 숫자가 작은 값 반환  
		return age1;
	else if(age1>age2)
		return age2;
	else
		return 0;
}

int main()	//main함수 생성  
{
	int age1 = 20;	//나이 변수생성1 
	int age2 = 30;	//나이 변수생성2 
	int first;		//순서를 위한 변수 생성  
	
	printf("입장순서 1 ");
	first = WhoIsFirst( age1, age2, OlderFirst);	//순서 정하는 함수 실행   
	printf("%d세와 %d세 중 %d세가 먼저 입장! \n\n", age1, age2, first);
	
	printf("입장순서 2 ");
	first = WhoIsFirst( age1, age2, YoungerFirst);	//순서 정하는 함수 실행  
	printf("%d세와 %d세 중 %d세가 먼저 입장! \n\n", age1, age2, first);
	return 0;	//main함수 종료  
}
