#include <stdio.h>
int main()
{
	int i ;
	int num1 = 0;
	float num2 = 0.0;
	double num3 = 0.0;

	for (i = 0; i < 100; i++)		//for�� ���� i�� 0���� �����ϰ� i���� 100���� ������������ ���������Ѵ�.
		num1 += 1;

	for (i = 0; i < 100; i++)
		num2 += 0.1;

	for (i = 0; i < 100; i++)
		num3 += 0.1;

	printf("�����: %d ", num1);
	printf("�����: %f ", num2);
	printf("�����: %lf ", num3); // �Ǽ����� %d�� ������ ���� ����. 
	return 0;
}
