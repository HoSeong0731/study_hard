#include <stdio.h>
int main()
{
	int num1;
	printf("���ڸ� �Է��ϼ���:");
	scanf("%d \n", &num1);			//�����Է�
	num1 = ~num1 + 1;				//num1�̶� ������ ��Ʈ�� �������ϰ� +1��. �� ����
	printf("�� ������ ������ %d�Դϴ�.\n", num1);
	return 0;
}