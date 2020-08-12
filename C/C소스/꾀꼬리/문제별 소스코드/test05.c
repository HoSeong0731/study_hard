#include <stdio.h>

int main()
{

	double arr1[3][3];	//첫 번째 배열의 값 들어감  
	
	/*
	arr1[0][0] arr1[0][1] arr1[0][2]
	arr1[1][0] arr1[1][1] arr1[1][2]
	arr1[2][0] arr1[2][1] arr1[2][2]
	행렬식 arr1[0][0] = arr1[1][1]*arr1[2][2] - arr1[1][2]*arr1[2][1]...
	역행렬 조건 = arr1[0][0]*(arr1[1][1]*arr1[2][2] - arr1[1][2]*arr1[2][1])
				- arr1[0][1]*(arr1[1][0]*arr1[2][2] - arr1[1][2]*arr1[2][0])
				+ arr1[0][2]*(arr1[1][0]*arr1[2][1] - arr1[1][1]*arr1[2][0])
	*/
	
	double arr2[3][3];	//두 번째 배열의 값 들어감  
	double arr3[3][3];	//두 배열의 합에 이용
	double arr4[3][3];	//두 배열의 차에 이용
	double arr5[3][3];	//두 배열의 곱에 이용

	
	printf("arr1에 데이터 값을 저장합니다.(공백으로 구분합니다.)");	
	for(int i = 0; i < 3; i++)	//첫 번째 배열에 값 입력  
	{
		for(int j = 0; j < 3; j++)
		{
			scanf_s("%lf", &arr1[i][j]);
		}
	}

	printf("arr2에 데이터 값을 저장합니다.(공백으로 구분합니다.)");		
		for(int i = 0; i < 3; i++)	//두 번째 배열에 값 입력
	{
		for(int j = 0; j < 3; j++)
		{
			scanf_s("%lf", &arr2[i][j]);
		}
	} 
	
		for(int i = 0; i < 3; i++)	//배열간 덧셈 반복  
	{
		for(int j = 0; j < 3; j++)
		{
			arr3[i][j]=arr1[i][j]+arr2[i][j];
		}
	}
	
	for(int i = 0; i < 3; i++)		//배열간 뺄셈 반복  
	{
		for(int j = 0; j < 3; j++)
		{
			arr4[i][j]=arr1[i][j]-arr2[i][j];
		}
	}
	
	for(int i = 0; i < 3; i++)		//배열간 곱셈 반복  
	{
		for(int j = 0; j < 3; j++)
		{
			arr5[i][j]=arr1[i][j]*arr2[i][j];
		}
	}
	
	printf("arr1을 출력합니다. \n");	//첫 번째 배열 출력  
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			printf("%13g", arr1[i][j]);
		}
		printf("\n");
	}
	
	printf("arr2를 출력합니다. \n"); //두 번째 배열 출력  
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			printf("%13g", arr2[i][j]);
		}
		printf("\n");
	}
	
	printf("두 배열의 합을 출력합니다. \n"); //배열의 합 출력   
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			printf("%13g", arr3[i][j]);
		}
		printf("\n");
	}
	
	printf("두 배열의 차를 출력합니다. \n"); //배열의 차 출력   
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			printf("%13g", arr4[i][j]);
		}
		printf("\n");
	}
	
	printf("두 배열의 곱을 출력합니다. \n"); //배열의 곱 출력   
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			printf("%13g", arr5[i][j]);
		}
		printf("\n");
	}

		// deteriment 구하기( det가 0이면 역행렬이 존재하지 않음.) 
	double det1 = arr1[0][0]*(arr1[1][1]*arr1[2][2] - arr1[1][2]*arr1[2][1]);
	double det2 = -arr1[0][1]*(arr1[1][0]*arr1[2][2] - arr1[1][2]*arr1[2][0]);
	double det3 = arr1[0][2]*(arr1[1][0]*arr1[2][1] - arr1[1][1]*arr1[2][0]);
	double det  = det1 + det2 + det3;
	
	//전치행렬 구하기 
	double arr11[3][3] = {
	arr1[1][1]*arr1[2][2] - arr1[1][2]*arr1[2][1], arr1[0][1]*arr1[2][2]-arr1[0][2]*arr1[2][1], arr1[0][1]*arr1[1][2]-arr1[0][2]*arr1[2][1],
	arr1[1][0]*arr1[2][2] - arr1[1][2]*arr1[2][0], arr1[0][0]*arr1[2][2]-arr1[0][2]*arr1[2][0], arr1[0][0]*arr1[1][2]-arr1[0][2]*arr1[1][0],
	arr1[1][0]*arr1[2][1] - arr1[1][1]*arr1[2][0], arr1[0][0]*arr1[2][1]-arr1[0][1]*arr1[2][0] ,arr1[0][0]*arr1[1][1]-arr1[0][1]*arr1[1][0]
	};
	
	//전치행렬 * det분 의 1 곱한 배열  = 역행렬  
	double arr111[3][3] = {
	 arr11[0][0]*det, arr11[0][1]*det, arr11[0][2]*det,
	 arr11[1][0]*det, arr11[1][1]*det, arr11[1][2]*det,
	 arr11[2][0]*det, arr11[2][1]*det, arr11[2][2]*det
	};
	
	//역행렬 구하기
	
	if(det == 0) 
	{
	 	printf("역행렬은 존재하지 않습니다.");
	}
	else{
	printf("역행렬을 출력합니다. \n");	//역행렬 출력  
		for(int i = 0; i < 3; i++)
			{
				for(int j = 0; j < 3; j++)
					{
						printf("%13g", arr111[i][j]);
					}
				printf("\n");
				
			}
		}
	return 0;	
}
