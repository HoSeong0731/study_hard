#include <stdio.h>
int sumFunc(int count)	// num부터 1까지 더하는 함수 생성
{
	if (count == 0)		//count가 0일때 sumFunc함수 종료 
		return 0;
	else
		return count + sumFunc(count - 1);	//그 전까진 반복
}
int main()
{
	int num;
	printf("합계를 원하는 정수를 입력하세요:");
	scanf("%d", &num);
	printf("1부터 %d까지의 합: %d", num, sumFunc(num));	//함수 실행해서 합계산 
	return 0;
}
/*
걸린시간 5분 
*/