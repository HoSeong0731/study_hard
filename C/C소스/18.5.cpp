#include <stdio.h>	//입출력 헤더파일 포함
void ShowArr2Dstyle(int(*arr)[4], int column)	//배열요소 전체출력 함수  
{
	int i, j;	// 반복문을 위한 i,j 변수 생성  
	for (i = 0; i < column; i++) //세로 반복조건 
	{
		for (j = 0; j < 4; j++)	//가로 반복조건 
		{
			printf("%d", arr[i][j]);	//참조된 배열 출력  
		}printf("\n");	//줄바꿈  
	}
}

int Sum2Darr(int arr[][4], int column)	//배열요소의 합 반환 함수  
{
	int i, j, sum= 0;	//반복문을 위한 i,j랑 요소들 다 합할 sum변수 생성  
	for (i = 0; i < column; i++)//세로 반복조건  
	{
		for (j = 0; j < 4; j++)	//가로 반복조건  
		{
			sum += arr[i][j];	//참조된 배열 더하기  
			
		}
	}
	return sum;	//sum값 반환  
}

int main()	//main함수 생성 
{
	int arr1[2][4] = { 1,2,3,4,5,6,7,8 };		//가로4 세로2 2차원배열 생성 
	int arr2[3][4] = { 1,1,1,1,3,3,3,3,5,5,5,5 };	//가로4 세로3 2차원배열 생성 

	ShowArr2Dstyle(arr1, sizeof(arr1) / sizeof(arr1[0]));	//배열요소 전체출력 함수 참조  
	ShowArr2Dstyle(arr2, sizeof(arr2) / sizeof(arr2[0]));	//배열요소 전체출력 함수 참조
	printf("arr1의 합: %d \n", Sum2Darr(arr1, sizeof(arr1) / sizeof(arr1[0])));	//배열요소의 합 반환 함수 참조  
	printf("arr2의 합: %d \n", Sum2Darr(arr2, sizeof(arr2) / sizeof(arr2[0])));	//배열요소의 합 반환 함수 참조  
	return 0;	//메인함수종료 
}
