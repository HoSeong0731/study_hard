#include <stdio.h>
int main()
{
	double rad, area;
	printf("���� ������ �Է�:");		
	scanf("%lf", &rad);					//scanf�� \n �� �ٹٲ޹��ڰ� ���� �ι��Է��ؾ��ϴ� �����������.(�ڿ��Է��� ���� ���õȴ�.)

	area = rad * rad*3.1415;			//���� ���� R*R*��
	printf("���� ����: %lf \n", area);
	return 0;
}