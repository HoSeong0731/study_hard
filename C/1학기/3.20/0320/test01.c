#include <stdio.h>
int main()
{
	int num1;
	printf("���ڸ� �Է��ϼ���.");
	scanf_s("%d \n", &num1);			//�����Է�
	num1 = ~num1 +1;				//num1�̶� ������ ��Ʈ���ٲٰ� +1��.
	printf("�� ������ ������ %d�Դϴ�.\n",num1) ;
	return 0;

}