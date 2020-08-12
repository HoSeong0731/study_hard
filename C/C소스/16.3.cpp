#include <stdio.h>	//표준입출력 헤더파일 생성 
int main()	//main함수
{
	int arr[3][2];	//int형 arr배열 생성
	int i, j;		//int형 i, j배열 생성  
	for(i=0; i<3; i++)	//반복문 중첩(세로) 
		for(j=0; j<2; j++)	//반복문 중첩(가로) 
			printf("%p \n", &arr[i][j]);	//출력 
	return 0;	//메인함수종료  
}
