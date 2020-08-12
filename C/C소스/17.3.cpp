#include <stdio.h>	//표준입출력 헤더파일 생성
void SwapIntPtr(int **dp1, int **dp2) //swap함수 (이중포인터로 전달 받음) 
{
	int * temp= *dp1;	
	*dp1=*dp2;	
	*dp2=temp;//p2를 p1이 가르키는 곳으로 바꿈(값도 같이 바뀜)  
}

int main()	//main함수
{
	int num1=10, num2=20;	//변수생성  
	int *ptr1, *ptr2;	//포인터변수 선언  
	ptr1=&num1, ptr2=&num2;	//포인터 연결  
	printf("*ptr1, *ptr2: %d %d \n", *ptr1, *ptr2);	//함수 실행전  
	
	SwapIntPtr(&ptr1, &ptr2); //swap함수 실행(인자값이 전달되면서 ptr의 주소와 연결됨) 
	printf("*ptr1, *ptr2: %d %d \n", *ptr1, *ptr2); //함수 실행후  
	return 0;	//메인함수 종료  
}
