#include <stdio.h>
int main()
{
	double num1 = 245;
	int num2 = 3.1415;
	int num3 = 129;	
	char ch = num3;		//char형에서 바로 129를 입력하면 char형의 범위를 넘는 수 이므로 경고가 뜬다.

	printf("정수 245를 실수로: %f \n", num1);		//	형변환을 발생하지 않게 하려면 %d가 맞다.
	printf("정수 245를 실수로: %lf \n", num1);		//	%f와 %lf의 값의 차이를 보기위해 작성했다.
	printf("실수 3.1415를 정수로: %d \n", num2);	//	소수점아래부분은 삭제된다.
	printf("큰정수 129를 작은정수로: %d \n", ch);	//	char형을 넘는 숫자이므로 값이 달라진다.
	printf("큰정수 129를 문자로: %c \n", ch);		//	아스키코드에는 음수가 없다. 즉 값이 지정되어 있지 않으므로 ?가 출력된다.
	return 0;
	
}