#include<stdio.h>

int main(void) {
	double num1, num2, value = 0;
	char i = 0;

	printf("����, ��ȣ, ���ڼ����� �Է��ϼ��� : ");
	scanf("%lf %c %lf", &num1, &i, &num2);

	switch (i) {  //char i�� ���� ���� case�� ����
	case '+': //char a�� ���� +�ϰ�� +������ �Ѵ�.
		value = num1 + num2;
		printf("%lf %c %lf = %lf", num1, i, num2, value);
		break;
	case '-': //char a�� ���� -�ϰ�� -������ �Ѵ�.
		value = num1 - num2;
		printf("%lf %c %lf = %lf", num1, i, num2, value);
		break;
	case '*':  //char a�� ���� *�ϰ�� *������ �Ѵ�.
		value = num1 * num2;
		printf("%lf %c %lf = %lf", num1, i, num2, value);
		break;
	case '/':  //char a�� ���� /�ϰ�� /������ �Ѵ�.
		printf("%lf/%lf = %lf", num1, num2, num1 / num2);
		break;
	default:
		printf("��Ģ������ �ƴ� �ٸ� ��ȣ�� �־����ϴ�.");
		break;
	}

	return 0;
}

