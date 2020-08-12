#include <stdio.h>
int main()
{
	int num1 = 2, num2 = 4, num3 = 6;
	num1 += 3; //num1에 3을 더함
	num2 *= 4; //num2에 4를 곱함
	num3 %= 5; //num3을 5로 나눈값의 나머지
	printf("결과: %d, %d, %d,", num1, num2, num3);
	return 0;
}