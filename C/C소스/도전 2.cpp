#include <stdio.h>
int cal(int *num1,int *num2)
{
	int temp = 0;
	if(num1>num2)
	{
		temp = *num1;
		*num1 = *num2;
		*num2 = temp;
	}

}
int main()
{
	int num1, num2;
	printf("숫자 입력 2개:");
	scanf("%d",&num1);
	scanf("%d",&num2);
	cal(&num1,&num2);
	while(num1<=num2)
	{
	for(int i=1;i<10;i++)
		{
			printf("%d X %d = %d",num1, i, num1*i);
			printf("\n");
		}
		num1++;
	}
	return 0;
}
