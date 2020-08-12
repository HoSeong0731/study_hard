#include<stdio.h>

int main(void) {
	double num1, num2, value = 0;
	char i = 0;

	printf("숫자, 기호, 숫자순으로 입력하세요 : ");
	scanf("%lf %c %lf", &num1, &i, &num2);

	switch (i) {  //char i의 값에 따라서 case를 설정
	case '+': //char a의 값이 +일경우 +연산을 한다.
		value = num1 + num2;
		printf("%lf %c %lf = %lf", num1, i, num2, value);
		break;
	case '-': //char a의 값이 -일경우 -연산을 한다.
		value = num1 - num2;
		printf("%lf %c %lf = %lf", num1, i, num2, value);
		break;
	case '*':  //char a의 값이 *일경우 *연산을 한다.
		value = num1 * num2;
		printf("%lf %c %lf = %lf", num1, i, num2, value);
		break;
	case '/':  //char a의 값이 /일경우 /연산을 한다.
		printf("%lf/%lf = %lf", num1, num2, num1 / num2);
		break;
	default:
		printf("사칙연산이 아닌 다른 기호를 넣었습니다.");
		break;
	}

	return 0;
}

