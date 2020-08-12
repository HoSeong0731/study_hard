#include<stdio.h>	//표준입출력헤더파일
#include<string.h>	//C 형식 문자열 (널 종료 문자열) 을 다룰 수 있는 함수들을 포함

int main()	//main함수 
{
	char str1[20];	//크기가 20인 1차원 배열 생성  
	char str2[20];	//크기가 20인 1차원 배열 생성  
	
	printf("문자열 입력 1: ");
	scanf("%s", str1);	//입력받음  
	printf("문자열 입력 2: ");
	scanf("%s", str2);	//입력받음  
	
	if(!strcmp(str1, str2))	//두 개의 문자열을 비교함(전체) 
	{
		puts("두 문자열은 완벽히 동일합니다.");

	 }
	else
	{
		puts("두 문자열은 동일하지 않습니다.");
		 if(!strncmp(str1, str2, 3))//두 개의 문자열의 앞의 3개만 비교함  
		 {
		 	puts("그러나 앞 세 글자는 동일합니다.");
		 }
	 } 
	 return 0;	//main함수 종료  
}
