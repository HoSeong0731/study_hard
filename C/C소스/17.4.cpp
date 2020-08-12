#include <stdio.h>	//표준입출력 헤더파일 생성
int main ()	//main함수
{
	int num1 = 10, num2 =20, num3 = 30;	//변수 생성  
	int *ptr1 = &num1;	//포인터연결 
	int *ptr2 = &num2;	//포인터연결 
	int *ptr3 = &num3;	//포인터연결 
	
	int *ptrArr[]={ptr1, ptr2, ptr3};	//포인터배열인자값으로 포인터를 넣음  
	int **dptr = ptrArr;		//이중포인터를 포인터배열과 연결  
	
	printf(" %d %d %d \n",*(ptrArr[0]), *(ptrArr[1]), *(ptrArr[2]));	//포인터배열출력  
	printf(" %d %d %d \n",*(dptr[0]), *(dptr[1]), *(dptr[2])); 	//이중포인터 출력  
	return 0; //메인함수 종료 
}

