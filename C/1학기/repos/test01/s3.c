#include <Stdio.h>
int main()
{
	int num1 = 0xA7, num2 = 0x43, num3 = 032, num4 = 024;
	/*
	16진수는 앞에 0x로 시작 8진수는 0으로 시작 10진수는 아무것도 없이
	%#d, %#x등 #이 들어가면 몇진수인지 표현해준다.
	*/

	printf("num1(0xA7)의 10진수 값: %d \n", num1);
	printf("num2(0x43)의 10진수 값: %d \n", num2);
	printf("num3 (032)의 10진수 값: %d \n", num3);
	printf("num4 (024)의 10진수 값: %d \n \n", num4);

	printf("num1(0xA7)의 16진수 값: %#x \n", num1);
	printf("num2(0x43)의 16진수 값: %#x \n", num2);
	printf("num3 (032)의 16진수 값: %#x \n", num3);
	printf("num4 (024)의 16진수 값: %#x \n \n", num4);

	printf("num1(0xA7)의 8진수 값: %#o \n", num1);
	printf("num2(0x43)의 8진수 값: %#o \n", num2);
	printf("num3 (032)의 8진수 값: %#o \n", num3);
	printf("num4 (024)의 8진수 값: %#o \n \n", num4);

	printf(" %d - %d = %d", num1, num2, num1 - num2);
	printf(" %#x - %#x = %#x", num3, num4, num3 - num4);
	return 0;
}