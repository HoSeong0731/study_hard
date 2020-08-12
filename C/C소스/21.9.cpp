#include<stdio.h>	//표준입출력헤더파일
#include<string.h>	//C 형식 문자열 (널 종료 문자열) 을 다룰 수 있는 함수들을 포함

int main()	//main함수 
{
	char str1[20]="First~";			//크기가 20인 1차원 배열 출력  
	char str2[20]="Second";			//크기가 20인 1차원 배열 출력  
	char str3[20]="Simple num: ";	//크기가 20인 1차원 배열 출력   
	char str4[20]="1234567890";		//크기가 20인 1차원 배열 출력  
	
	/****case 1****/
	strcat(str1, str2);	//str1에 str2를 붙임  
	puts(str1);	//str1출력  
	
	/****case 2****/
	strncat(str3, str4, 7);	//str3에 str4의 7번째까지만 붙임(널값포함시 8) 
	puts(str3);	//str3 출력  
	return 0;	//main함수종료  
}
	

