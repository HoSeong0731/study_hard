#include <stdio.h>
int main()
{
	int result, num1, num2;

	printf("정수 입력1: \n");
	scanf("%d", &num1);

	printf("\n정수 입력2 \n");
	scanf(" %d", &num2);

	result = num1 + num2;
	printf("\n %d + %d = %d", num1, num2, result);
	return 0;
}