#include <stdio.h>
int main()
{
	int result, num1, num2, num3 = 0;

	printf("세게의 정수를 입력하세요. \n");
	scanf("%d %d %d", &num1, &num2, &num3);

	result = num1 + num2 + num3;
	printf(" %d + %d + %d = %d ", num1, num2, num3, result);
	return 0;
}
