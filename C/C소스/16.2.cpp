#include <stdio.h>	//표준입출력 헤더파일 생성 
int main()	//main함수
{
int villa[4][2];	//int형 villa배열 생성 
int popu, i, j;		//int형 popu, i, j변수 생성  


//가구별 거주인원 입력 받기
for(i=0; i<4; i++) //2차원 배열이므로 반복문 중첩  
{
for(j=0; j<2; j++)	//가로 먼저 증가(중첩 안에 있는 것 부터)  
	{
	printf("%d층 %d로 인구수: ", i+1, j+1);
	scanf("%d", &villa[i][j]);
	}
}

//빌라의 층별 인구수 출력하기
 
	
for(i=0; i<4; i++)	// 가로의 경우 2개만 있으므로 반복문 중첩이 아닌 세로만 반복  
		{
		popu = 0;
		popu += villa[i][0];
		popu += villa[i][1];
		printf("%d층 인구수: %d \n", i+1, popu);

		}
	
	return 0;	//메인함수 종료 
	
}

