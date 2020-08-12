#include <stdio.h>	//표준입출력 헤더파일 생성
int main()	//main함수
{
int arr1[2][4] = {	//arr1에 데이터 먼저 입력  
{1,2,3,4},
{5,6,7,8}
};

int arr2[4][2]={ arr1[0][0], arr1[1][0], arr1[0][1],arr1[1][1],  arr1[0][2], 
  arr1[1][2], arr1[0][3], arr1[1][3],};		//무식하게 옮기는 방법  
int i, j;	//int형 i, j 변수 생성  

for(i=0; i<2; i++)	//반복문 중첩(세로) 
{
for(j=0; j<4; j++)	//반복문 중첩(가로)  
	{
	printf("%d", arr1[i][j]);
	}printf("\n");
}

for(i=0; i<4; i++)	//반복문 중첩(세로) 
{
for(j=0; j<2; j++) 	//반복문 중첩(가로)  
	{
	printf("%d", arr2[i][j]);
	}printf("\n");
}
return 0;	//메인함수종료
}

