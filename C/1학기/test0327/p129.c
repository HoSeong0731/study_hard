#include <stdio.h>
int main()
{
	int num1, num2;
	double divResult;
	printf("값을 입력하세요: ");
	scanf("%d %d", &num1, &num2);		//숫자입력받는 공간
	divResult = num1 / num2;			//계산실행
	printf("\n 나눗셈 결과(f형): %f\n 나눗셈 결과(lf형)%lf", divResult, divResult);
	return 0;
}