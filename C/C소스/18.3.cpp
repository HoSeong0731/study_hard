#include <stdio.h>	//입출력 헤더파일 포함 
int main()			//main함수 생성 
{
	int arr1[2][2]={	//arr1 가로2 세로2 배열 생성  
		{1,2},{3,4}
	};

	int arr2[3][2]={	//arr2 가로2 세로3 배열 생성  
		{1,2},{3,4},{5,6}
	};

	int arr3[4][2]={	//arr3 가로2 세로4 배열 생성  
		{1,2},{3,4},{5,6},{7,8}
	};

	int(*ptr)[2];	//가로2인 배열 생성  
	int i;		//반복문을 위한 i변주 생성  
	ptr = arr1;	//ptr이 arr1가르킴  
	printf(" ** Show 2,2 arr1 **\n");	//arr1에 있는 값 출력 안내  
	for (i = 0; i < 2; i++)		//출력을 위한 반복문  
		printf("%d %d \n", ptr[i][0], ptr[i][1]);	//배열안에 있는 값 출력  
	printf("\n");	//줄 바꿈  

	ptr = arr2;	//ptr이 arr2가르킴  
	printf(" ** Show 3,2 arr2 **\n");	//arr1에 있는 값 출력 안내 
	for (i = 0; i < 3; i++)		//출력을 위한 반복문  
		printf("%d %d \n", ptr[i][0], ptr[i][1]);	//배열안에 있는 값 출력  
	printf("\n");	//줄 바꿈  

	ptr = arr3;	//ptr이 arr3가르킴  
	printf(" ** Show 4,2 arr3 **\n");	//arr1에 있는 값 출력 안내 
	for (i = 0; i < 4; i++)		//출력을 위한 반복문  
		printf("%d %d \n", ptr[i][0], ptr[i][1]);	//배열안에 있는 값 출력  
	printf("\n");	//줄 바꿈  

	return 0;	//main함수 종료  
}

