#include <stdio.h>		//입출력 헤더파일 포함

void SosimpleFunc(void)
{
	printf(" I'm so simple");
	
}

int main(void)	//main함수 생성 
{
	int num =20;	//변수생성 
	void * ptr;		//포인터변수생성  
	
	ptr= &num;	//변수 num값의 주소 값 저장   
	printf("%p \n", ptr);	
	
	ptr = SosimpleFunc; //함수 So...의 주소 값 저장  
	printf("%p \n", ptr);
	return 0;
}

