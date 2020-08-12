#include<stdio.h>	//표준입출력헤더파일 
int main()	//main함수 
{
	char * str="Simple String";	//str포인터변수에 문자열 저장  
	
	printf("1. puts test ------ \n");	
	puts(str);	//문자열 출력 함수(오직 모니터로만 출력한다.) 
	puts("so simple string");
	
	printf("2. fputs test ----- \n");
	fputs(str, stdout); printf("\n");	//문자열 출력 함수(stdout을 통해 모니터로 출력된다.(설정 가능)) 
	fputs("So Simple String", stdout); printf("\n");
	
	printf("3. end of main ----\n");
	return 0;	//main함수 종료  
 } 
