#include <stdio.h>
int main()
{
	int result, num1, num2, num3 = 0;

	printf("������ ������ �Է��ϼ���. \n");
	scanf("%d %d %d", &num1, &num2, &num3);

	result = num1 + num2 + num3;
	printf(" %d + %d + %d = %d ", num1, num2, num3, result);
	return 0;
}
