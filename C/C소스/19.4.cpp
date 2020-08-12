#include <stdio.h>	//입출력 헤더파일 포함

int main(int argc, char *argv[])	//exe파일실행시켜서 문자 입력할 것  
{
	int i=0;
	printf("전달된 문자열의 수: %d \n", argc);	//argc의 문자열 수 출력  
	
	for(i=0; i<argc; i++)
		printf("%d번째 문자열: %s \n", i+1, argv[i]);	//단어 단위로 출력  
	return 0;	//main함수종료  
	}


