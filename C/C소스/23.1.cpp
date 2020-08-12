#include <stdio.h>	//표준 입출력 라이브러리
#include <windows.h>//윈도우 헤더파일  

typedef	int INT;		//int형 구조체  
typedef int *PTR_INT;	//int형 포인터 구조체 
typedef unsigned int UINT;		//unsigned int형 구조체
typedef unsigned int *PTR_UINT;	//unsigned int형 포인터 구조체 
typedef unsigned char UCHAR;		//unsigned char형 구조체
typedef unsigned char * PTR_UCHAR;	//unsigned char형 포인터 구조체

int main()	//메인함수  
{
	INT num1 = 120;
	PTR_INT pnum1 = &num1;	//num1에 pnum1을 연결  
 	UINT num2 = 190;
	PTR_UINT pnum2 = &num2;	//num2에 pnum2을 연결
	UCHAR ch = 'z';
	PTR_UCHAR pch = &ch;	//ch에 pch를 연결

	printf("%d, %u, %c \n", *pnum1, *pnum2, *pch);	//출력
	system("PAUSE");	//일시정지  
	return 0;	//메인함수 종료  
}
