#include <stdio.h>
int time(int *num)
{
	int min = *num/60;
	if(min>60)
	{
		min = *num-60;
	}
	printf("%d�ð� %d�� %d��", *num/3600, min, *num%60);
}
int main()
{
	int num;
	printf("�ʸ� �Է����ּ���.");
	scanf("%d",&num);
	time(&num);
	return 0;
}
