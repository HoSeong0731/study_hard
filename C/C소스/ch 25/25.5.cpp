#include <stdio.h>	//표준 입출력 헤더파일
#include <stdlib.h>	//표준 메모리라이브러리  

char * ReadUserName()	//입력받는 함수 	
{
	char * name = (char *)calloc(30, sizeof(char));
	printf("What's your name? ");
	gets(name);
	return name;
}

int main(void)
{
	char * name1;
	char * name2;
	name1=ReadUserName();
	printf("name1: %s \n", name1);
	name2=ReadUserName();
	printf("name2: %s \n", name2);

	printf("again name1: %s \n", name1);
	printf("again name2: %s \n", name2);
	free(name1);	//메모리 동적할당 한 것을 소멸시킴 
	free(name2);	//메모리 동적할당 한 것을 소멸시킴 
	return 0;		//main함수 종료  
}
