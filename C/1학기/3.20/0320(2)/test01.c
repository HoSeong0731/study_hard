#include <stdio.h>
int main()
{
	int num1;
	printf("숫자를 입력하세요:");
	scanf("%d \n", &num1);			//숫자입력
	num1 = ~num1 + 1;				//num1이란 변수의 비트를 역수취하고 +1함. 즉 보수
	printf("그 숫자의 보수는 %d입니다.\n", num1);
	return 0;
}