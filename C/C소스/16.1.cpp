#include <stdio.h>	//표준입출력 헤더파일 생성 
int main()	//main함수 
{
int arr1[3][4];	//int형 arr1배열 생성 
int arr2[7][9];	//int형 arr2배열 생성 
printf("세로3, 가로4: %d \n", sizeof(arr1));
printf("세로7, 가로9: %d \n", sizeof(arr2));
return 0;	//메인함수 종료 
}
