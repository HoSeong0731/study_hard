#include <stdio.h>	//표준 입출력 헤더파일  

char * ReadUserName(void)	//문자열 입력받는 함수  
{
	char name[30];
	printf("What's your name? ");
	gets(name);
	return name;	//받은 값 반환  
}

int main(void)	//main함수  
{
	char * name1;
	char * name2;
	name1=ReadUserName();
	printf("name1: %s \n", name1);
	name2=ReadUserName();	
	printf("name2: %s \n", name2);
	return 0;	//메인함수 종료  
}
