#include <stdio.h>
int time(int *num)
{
	int min = *num/60;
	if(min>60)
	{
		min = *num-60;
	}
	printf("%d시간 %d분 %d초", *num/3600, min, *num%60);
}
int main()
{
	int num;
	printf("초를 입력해주세요.");
	scanf("%d",&num);
	time(&num);
	return 0;
}
