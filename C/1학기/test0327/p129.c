#include <stdio.h>
int main()
{
	int num1, num2;
	double divResult;
	printf("���� �Է��ϼ���: ");
	scanf("%d %d", &num1, &num2);		//�����Է¹޴� ����
	divResult = num1 / num2;			//������
	printf("\n ������ ���(f��): %f\n ������ ���(lf��)%lf", divResult, divResult);
	return 0;
}