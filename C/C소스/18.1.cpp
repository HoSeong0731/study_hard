#include <stdio.h>		//입출력 헤더파일 포함 
int main()				//main함수 생성 
{
	int arr2d[3][3];	//int형 2차원 배열 생성 
	printf("%d \n", arr2d);				//arr2d(0,0) 주소 값 출력 (이하 x,y) 
	printf("%d \n", arr2d[0]);			//arr2d(0,0) 주소 값 출력 	
	printf("%d \n\n", &arr2d[0][0]);	//arr2d(0,0) 주소값 출력 


	printf("%d \n", arr2d[1]);			//arr2d(0,1) 주소값 출력  
	printf("%d \n\n", &arr2d[1][0]);	//arr2d(0,1) 주소값 출력  

	printf("%d \n", arr2d[2]);			//arr2d(0,2) 주소값 출력  
	printf("%d \n\n", &arr2d[2][0]);	//arr2d(0,2) 주소값 출력  

	printf("sizeof(arr2d): %d \n", sizeof(arr2d));	//size = 4*3*3
	printf("sizeof(arr2d[0]): %d \n", sizeof(arr2d[0]));	//size = 4*3
	printf("sizeof(arr2d[1]): %d \n", sizeof(arr2d[1]));	//size = 4*3
	printf("sizeof(arr2d[2]): %d \n", sizeof(arr2d[2]));	//size = 4*3
	return 0;	//main함수 종료  
}

