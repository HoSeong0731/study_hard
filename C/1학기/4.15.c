#include <stdio.h>
int main()
{
	int num;
	printf("0이상 정수입력: ");
	scanf("%d", &num);
	switch(num/10)						//10으로 나누고 int형이므로 소수점부분은 버려짐
	{
		case 0:
			printf("0 이상 10미만 \n");
			break;
		case 1:
			printf("10이상 20미만 \n");
			break;
		case 2:
			printf("20이상 30미만 \n");
			break;
		default:
			printf("30이상이거나 음수인 정수");
	}
	return 0;
}