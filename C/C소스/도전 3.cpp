#include <stdio.h>
int cal(int *num1,int *num2)
{
	int i = 1, result = 0;
	while(1)
	{
	if(*num1%i==0 && *num2%i==0)
		{
		 return i;
		}i++;
	}
	
} 
int main()
{	
	int num1, num2;
	printf("두개의 숫자 입력");
	scanf("%d", &num1);
	scanf("%d", &num2);
	printf("두개의 최대 공약수: ");	
	cal(&num1, &num2);
	
	return 0;
}
