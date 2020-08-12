#include <stdio.h>	//표준입출력헤더파일 포함
#include <stdlib.h>	//표준라이브러리헤더파일 포함  


int main()	//main함수  
{
	// 1~30의 숫자를 랜덤하게 가지는 2차원 배열
	int data[4][4]
		= { rand() % 31 , rand() % 31 ,rand() % 31 ,rand() % 31 ,
		 rand() % 31 , rand() % 31 , rand() % 30, rand() % 31 ,
		 rand() % 31 , rand() % 31 , rand() % 31, rand() % 31 ,
		 rand() % 31 , rand() % 31 , rand() % 31, rand() % 31 };

	int leftdata[3];	//left데이터 값 저장 배열  
	int updata[3];	//up데이터 값 저장 배열
	int leftdiadata[3];	//leftdia데이터 값 저장 배열
	int rightdiadata[3];	//rightdia	데이터 값 저장 배열

	int i, j, result = 1, middle = 0;	//반복문과 조건문들을 위한 변수 생성  
	int left = data[0][0] * data[0][1];	//처음 left값  
	int up = data[0][0] * data[1][0];	//처음 right값
	int leftdia = data[0][1] * data[1][0];	//처음 leftdia값
	int rightdia = data[0][3] * data[1][2];	//처음 rightdia값

	printf("랜덤하게 섞여있는 데이터 값\n");	//기존의 섞여있는 값 출력  
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%3d ", data[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < 4; i++)	//양옆의 곱셈 중 최대 값 구함. 
	{
		for (j = 0; j < 3; j++)
		{
			if (left < data[i][j] * data[i][j + 1])
			{
				left = data[i][j] * data[i][j + 1];
				leftdata[0] = data[i][j];	//값 저장  
				leftdata[1] = data[i][j + 1];	//값 저장  
				leftdata[2] = data[i][j] * data[i][j + 1];	//값 저장(곱한 값) 
			}
		}
	}

	for (i = 0; i < 3; i++)	//위 아래의 곱셈 중 최대 값 구함. 
	{
		for (j = 0; j < 4; j++)
		{
			if (up < data[i][j] * data[i + 1][j])
			{
				up = data[i][j] * data[i + 1][j];	//후에 비교를 위해 저장  
				updata[0] = data[i][j];	//값 저장  
				updata[1] = data[i + 1][j];	//값 저장  
				updata[2] = data[i][j] * data[i + 1][j];	//값 저장  (결과 값) 
			}
		}
	}

	for (i = 0; i < 3; i++)	//왼쪽 대각선  최대 값 구함. 
	{
		for (j = 0; j < 3; j++)
		{
			if (leftdia < data[i][j + 1] * data[i + 1][j])
			{
				leftdia = data[i][j + 1] * data[i + 1][j];	//후에 비교를 위해 저장  
				leftdiadata[0] = data[i][j + 1];	//값 저장  
				leftdiadata[1] = data[i + 1][j];	//값 저장  
				leftdiadata[2] = data[i][j + 1] * data[i + 1][j];	//값 저장  (결과 값) 
			}
		}
	}

	for (i = 0; i < 3; i++)	//오른쪽 대각선 최대 값 구함  
	{
		for (j = 0; j < 3; j++)
		{
			if (rightdia < data[i][j] * data[i + 1][j + 1])
			{
				rightdia = data[i][j] * data[i + 1][j + 1]; //후에 비교를 위해 저장 
				rightdiadata[0] = data[i][j];		//값 저장 
				rightdiadata[1] = data[i + 1][j + 1];	//값 저장 
				rightdiadata[2] = data[i][j] * data[i + 1][j + 1];	//값 저장 (결과 값)  

			}
		}
	}


	if (result < leftdata[2])		//결과 값 정하기 (switch문 사용을 위해) 
	{
		result = 1;
		middle = leftdata[2];
	}
	if (middle < updata[2])
	{
		result = 2;
		middle = updata[2];
	}
	if (middle < leftdiadata[2])
	{
		result = 3;
		middle = leftdiadata[2];
	}
	if (middle < rightdiadata[2])
	{
		result = 4;
		middle = rightdiadata[2];
	}

	switch (result) {	//switch문을 이용해 결과 출력  
	case 1:
		printf("Biggest product1: = %d X %d = %d", leftdata[0], leftdata[1], leftdata[2]);
		break;

	case 2:
		printf("Biggest product2: = %d X %d = %d", updata[0], updata[1], updata[2]);
		break;

	case 3:
		printf("Biggest product3: = %d X %d = %d", leftdiadata[0], leftdiadata[1], leftdiadata[2]);
		break;

	case 4:
		printf("Biggest product4: = %d X %d = %d", rightdiadata[0], rightdiadata[1], rightdiadata[2]);
		break;
	}

	return 0;	//main함수 종료  
}