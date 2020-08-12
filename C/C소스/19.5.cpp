#include <stdio.h> 	//입출력 헤더파일 포함

int main(int argc, char *argv[])	//인자 값 argc정수형, argv문자형  
{
	int i=0;
	printf("전달된 문자열의 수: %d \n", argc);	//argc의 문자열 수 출력  
	
	while(argv[i]!=NULL)	//null값이 오기 전까지 반복  
	{
		printf("%d번째 문자열: %s \n", i+1, argv[i]);	//단어 단위로 출력  
		i++; //반복문 종료시키는 조건  
	}
	return 0;	//main함수종료  
 } 
