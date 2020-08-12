#include <stdio.h>	//입출력 헤더파일 포함
int main()			//main함수 생성 
{
	int num1 = 10, num2 = 20, num3 = 30, num4 = 40;		//변수 4개 생성  
	int arr2d[2][4] = { 1,2,3,4,5,6,7,8 };	//int형인 2차원 배열 가로4 세로2 생성  
	int i, j;		//반복문을 위한 i, j 변수 생성  

	int* whoA[4] = { &num1, &num2, &num3, &num4, };	//포인터배열:배열 요소로 포인터 변수를 가지는 배열
	int(*whoB)[4] = arr2d; //배열포인터:배열을 가리킬 수 있는 포인터

	printf("%d %d %d %d \n", *whoA[0], *whoA[1], *whoA[2], *whoA[3]);	//포인터배열 1,2,3,4번째 출력  
	for (i = 0; i < 2; i++)		//세로 출력 반복  
	{
		for (j = 0; j < 4; j++)	//가로 출력 반복  
		{
			printf("%d", whoB[i][j]); //배열포인터 출력 
		}printf("\n");	//줄 바꿈 
	}
	return 0;	//main함수종료  
}
