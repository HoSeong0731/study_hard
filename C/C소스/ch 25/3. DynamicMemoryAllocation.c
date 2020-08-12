#include <stdio.h>	//표준 입출력 헤더파일
#include <stdlib.h>	//표준 메모리라이브러리  

int main(void)
{
	int * ptr1 = (int *)malloc(sizeof(int));	//int형 *1 = 4 
	int * ptr2 = (int *)malloc(sizeof(int)*7);	//int형 *7 = 28 
	int i;
	
	*ptr1 = 20;
	for(i=0; i<7; i++)
		ptr2[i]=i+1;
	
	printf("%d \n", *ptr1);
	for(i=0; i<7; i++)
		printf("%d ", ptr2[i]);
	
	free(ptr1);	//메모리 동적할당 한 것을 소멸시킴 
	free(ptr2);
	return 0;	//main함수종료  
}
