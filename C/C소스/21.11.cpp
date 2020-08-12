#include<stdio.h>	//표준입출력헤더파일
#include<stdlib.h>	//표준라이브러리헤더파일  

int main()	//main함수 
{
	char str[20];	//크기가 20인 1차원 배열을 생성  
	
	printf("정수 입력: ");
	scanf("%s", str);		//입력받음  
	printf("%d \n", atoi(str));	//int형으로 변환  
	
	printf("실수 입력: ");
	scanf("%s", str);	//입력받음 
	printf("%g \n", atof(str));	//double형으로 변환  
	
	return 0;	//메인함수종료  
}
