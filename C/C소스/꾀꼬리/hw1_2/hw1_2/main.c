#include <stdio.h>	//표준입출력헤더파일 포함

int main()	//main함수 생성  
{
	int num, n1, n2, n3, n4, n5;	//입력받을 num과 n1~n5 생성 

back:
	printf("0~50000중 숫자를 입력하시오. ");
	scanf_s("%d", &num);	//숫자 입력 받음  

	if (num < 0 || num>50000) {		//예외처리  
		printf("잘못된 값을 입력하셨습니다.\n");
		goto back;
	}

	n1 = num / 10000;	//10000의 자리 계산  
	n2 = (num - (n1 * 10000)) / 1000;	//1000의 자리 계산  
	n3 = (num - (n1 * 10000) - (n2 * 1000)) / 100;	//100의 자리 계산  
	n4 = (num - (n1 * 10000) - (n2 * 1000) - (n3 * 100)) / 10;	//10의 자리 계산  
	n5 = num % 10;	//1의 자리 계산  

	printf("%d	%d	%d	%d	%d \n", n1, n2, n3, n4, n5);	//이후 출력  
	printf("%d	%d	%d	%d	\n", n2, n3, n4, n5);
	printf("%d	%d	%d	\n", n3, n4, n5);
	printf("%d	%d	\n", n4, n5);
	printf("%d	\n", n5);

	return 0;	//main함수종료  
}