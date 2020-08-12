#include <stdio.h>
int main()
{
	char ch = 9;
	int inum = 1052;
	double dnum = 3.1415;		//변수의 크기를 묻고 있으므로 double형의 사이즈 값이 나온다.
	char num1 = 1, num2 = 2, result1 = 0;		//정확히 구분하면 result1은 char형, result2는 short형으로 값의 표현범위가 다르다.
	short num3 = 300, num4 = 400, result2 = 0;

	printf("변수 ch의 크기: %d \n", sizeof(ch));		//작성자가 지정한 변수의 자료형의 사이즈를 출력한다.
	printf("변수 inum의 크기: %d \n", sizeof(inum));
	printf("변수 dnum의 크기: %d \n\n", sizeof(dnum));

	printf("char의 크기: %d \n", sizeof(char));			//c언어에서 지정한 자료형들이다.
	printf("int의 크기: %d \n", sizeof(int));
	printf("long의 크기: %d \n", sizeof(long));
	printf("char의 크기: %d \n", sizeof(long long));
	printf("char의 크기: %d \n", sizeof(float));
	printf("char의 크기: %d \n\n", sizeof(double));


	printf("size of num1 & num2: %d, %d \n", sizeof(num1), sizeof(num2));
	printf("size of num3 & num4: %d, %d \n", sizeof(num3), sizeof(num4));
	printf("size of char add: %d \n", sizeof(num1 + num2));			//num1과 num2의 바이트크기 연산
	printf("size of char add: %d \n", sizeof(num3 + num4));			//num3과 num4의 바이트크기 연산

	result1 = num1 + num2;		//변수에 저장되있는 값은 연산 num1 + num2이므로 변수값은 3이다.
	result2 = num3 + num4;
	printf("size of result1 & result2: %d, %d", sizeof(result1), sizeof(result2));
	return 0;
}