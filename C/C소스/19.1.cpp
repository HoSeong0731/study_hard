#include<stdio.h>	//입출력 헤더파일 포함

void SimpleAdder(int n1, int n2)	//인자값을 받아 덧셈을 실행하는 함수  
{
	printf(" %d + %d = %d \n", n1, n2, n1 + n2);

}

void ShowString(char *str)	//인자값을 받아 출력하는 함수  
{
	printf("%s \n", str);
}

int main()	//main함수  
{
	char *str = "Function Pointer";	//문자형 포인터변수 생성 
	int num1 = 10, num2 = 20;	//변수 생성  

	void(*fptr1)(int, int) = SimpleAdder;	//SimpleAdder와 동일한 형의 포인터변수 생성  
	void(*fptr2)(char *) = ShowString;		//ShowString와 동일한 형의 포인터변수 생성  

	
	fptr1(num1, num2);	//함수 포인터 변수에 의한 호출
	fptr2(str);	//함수 포인터 변수에 의한 호출
	return 0;	//main함수 종료  

}

