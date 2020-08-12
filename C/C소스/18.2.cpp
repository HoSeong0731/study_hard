#include <stdio.h>	//입출력 헤더파일 포함 
int main()				//main함수 생성 
{

	int arr1[3][2];	//int형 2차원 배열 생성(가로2, 세로3) 
	int arr2[2][3];	//int형 2차원 배열 생성(가로3, 세로2) 

	printf("arr1: %p \n", arr1);		//arr1의 포인터 주소 출력 
	printf("arr1+1: %p \n", arr1 + 1);	//arr1의 포인터 주소 출력(가로가 2이므로 4*2 = 8 증가) 
	printf("arr1+2: %p \n\n", arr1 + 2);//arr1의 포인터 주소 출력(가로가 2이므로 4*2 = 8 증가)

	printf("arr2: %p \n", arr2);		//arr2의 포인터 주소 출력(가로가 3이므로 4*3 = 12 증가) 
	printf("arr2+1: %p \n", arr2 + 1);	//arr2의 포인터 주소 출력(가로가 3이므로 4*3 = 12 증가) 
	return 0;	//main함수 종료  
}
