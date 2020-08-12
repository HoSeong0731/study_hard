#include <stdio.h>	//입출력 헤더파일 포함
#include <stdlib.h>	//표준 라이브러리 헤더파일 포함

int main()	//main함수생성  
{
	int i;	//반복문을 위한 변수 생성  
	printf("난수의 범위: 0부터 99까지 \n");
	for(i=0; i<5; i++)	//난수 5번 출력  
	{
		printf("난수 출력: %d \n", rand()%100);	// 많은 난수 중 100으로 나눈 값의 나머지 츨력  
	}
	return 0;	//main함수종료  
 } 
