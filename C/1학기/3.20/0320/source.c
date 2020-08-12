#include <stdio.h>
int main()
{
	int i ;
	int num1 = 0;
	float num2 = 0.0;
	double num3 = 0.0;

	for (i = 0; i < 100; i++)		//for문 조건 i를 0으로 시작하고 i값이 100보다 작을때까지만 후위증가한다.
		num1 += 1;

	for (i = 0; i < 100; i++)
		num2 += 0.1;

	for (i = 0; i < 100; i++)
		num3 += 0.1;

	printf("결과값: %d ", num1);
	printf("결과값: %f ", num2);
	printf("결과값: %lf ", num3); // 실수형을 %d로 받을시 오류 생김. 
	return 0;
}
