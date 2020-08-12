#include <stdio.h>	//표준입출력헤더파일
int main()	//main함수 
{
	int ch1, ch2;	//문자입력받을 변수 생성 
	
	ch1 = getchar();	//문자입력 
	ch2 = fgetc(stdin); //엔터 키 입력  
	
	putchar(ch1); //문자출력 
	fputc(ch2, stdout);	//엔터 키 출력 
	return 0;	//main함수종료 
}
