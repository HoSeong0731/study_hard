#include <stdio.h>

int n=1;
int number=0;

int sumFunc(int count)
{
	if(count == 0)
	return 0;
	else
	number+=1;
	return count+sumFunc(count-1);
	
}

int main(void)
{
	while(n != 0)
	{
		printf("합계를 원하는 정수를입력하세요(종료는 0입력): ");
		scanf("%d", &n);
		printf("1부터 &d까지의 합: &d\n", n, sumFunc(n));
	}
	printf("합계 프로그램을 종료합니다. sumFunc함수는 총 %d번 호출되었습니다.\n", number);
	return 0;
}
