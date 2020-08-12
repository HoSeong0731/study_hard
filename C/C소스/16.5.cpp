#include <stdio.h>	//표준입출력 헤더파일 생성 
int main()	//main함수
{
	int mean=0, i, j;		//int 형 mean, i, j변수 선언  
	int record [3][3][2]={ 	//높이, 세로, 가로  int형 3차원 배열  
	{
	{70,80}, 
	{94,90},
	{70,85}
	},
	{
	{83,90},
	{95,60},
	{90,82}
	},
	{
	{98,89},
	{99,94},
	{91,87}
	}
};

for(i=0; i<3; i++)	//세로 반복문	(반 마다(높이인 부분) 평균 구하는 것을 3번으로 나뉘어져 있어 중첩한 번으로 나옴. 
	for(j=0; j<2; j++)	//가로 반복문  
		mean+= record[0][i][j];	//전부 더함  
printf("A학급 전체 평균: %g \n", (double)mean/6);	//학생 수 만큼 나눔  
mean=0;	//mean값 초기화  

for(i=0; i<3; i++)
	for(j=0; j<2; j++)
		mean+= record[1][i][j];
printf("B학급 전체 평균: %g \n", (double)mean/6);
mean=0;

for(i=0; i<3; i++)
	for(j=0; j<2; j++)
		mean+= record[2][i][j];
printf("C학급 전체 평균: %g \n", (double)mean/6);
mean=0;
return 0;	//메인함수종료  
}

