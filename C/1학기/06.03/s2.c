#include <stdio.h>
void Swap(int*ptr1, int*ptr2, int*ptr3)
{
	int temp = *ptr3;
	*ptr3 = *ptr2;
	*ptr2 = *ptr1;
	*ptr1 = temp;
}
int main()
{
	int num1, num2, num3;
	printf("숫자 3개 입력:");
	scanf("%d", &num1);
	scanf("%d", &num2);
	scanf("%d", &num3);

	Swap(&num1, &num2, &num3);
	printf("%d, %d, %d \n", num1, num2, num3);
	return 0;
}