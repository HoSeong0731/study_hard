#include <stdio.h>
int main()
{
	int num1 = 3;
	num1 = num1 << 3; //���۸� 3ĭ�̵���. �� 8��
	num1 = num1 >> 2; //���۸� 2ĭ�̵���. �� 1/4��
	printf("���: %d", num1);
	return 0;
}