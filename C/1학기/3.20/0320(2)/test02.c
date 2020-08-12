#include <stdio.h>
int main()
{
	int num1 = 3;
	num1 = num1 << 3; //버퍼를 3칸이동함. 즉 8배
	num1 = num1 >> 2; //버퍼를 2칸이동함. 즉 1/4배
	printf("결과: %d", num1);
	return 0;
}