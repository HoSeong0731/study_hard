#include<stdio.h>	//표준입출력헤더파일
#include<string.h>	//C 형식 문자열 (널 종료 문자열) 을 다룰 수 있는 함수들을 포함

void RemoveBSN(char str[])	//널값까지 들어가서 계산되는 거에서 -1해주는 함수  
{
	int len = strlen(str);	//인자값에 입력받은 것의 길이의 크기와 len을 연결  
	str[len-1]=0;	//len - 1은 기존 입력받은 값에 널값이 빠진 것 
}

int main()
{
	char str[100];	//크기가 100인 1차원 배열 생성 
	printf("문자열 입력: ");
	fgets(str, sizeof(str), stdin);	//입력받음  
	printf("길이: %d, 내용: %s \n", strlen(str), str);	//기존엔 널값까지 들어가서 계산됨. 
	
	RemoveBSN(str);	//함수실행  
	printf("길이: %d, 내용: %s \n", strlen(str), str);	//제대로 된 계산 
	return 0;	//main함수종료 
}
