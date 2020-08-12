#include<stdio.h>	//표준입출력헤더파일
#include<string.h>	//C 형식 문자열 (널 종료 문자열) 을 다룰 수 있는 함수들을 포함

int main()	//main함수 
{
	char str1[20]="1234567890";	//값이 들어가 있는 크기가 20인 1차원 배열 생성 
	char str2[20];	//크기가 20인 1차원 배열 생성 
	char str3[5];	//크기고 5인 1차원 배열 생성 
	
	/****case 1****/
	strcpy(str2, str1);	//str2에 str1의 값 복사  
	puts(str2);	//str2 출력  
	
	/****case 2****/
	strncpy(str3, str1, sizeof(str3));	//str3에 str1값 복사(크기는 5만큼)  
	puts(str3);	//str3 출력  
	
	/****case 3****/
	strncpy(str3, str1, sizeof(str3)-1);	//case2와 동일  
	str3[sizeof(str3-1)]=0;	//case2와 동일하지만 널값이 없음  
	puts(str3);	//str3 출력  
	return 0;	//main함수 종료
}
