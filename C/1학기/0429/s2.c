#include <stdio.h>
int insert(int num)		//�Է¹޴� �Լ�(��������δ� scanf�Լ��� ����
{
	scanf("%d, ", &num);
	return num;
}
int maxpoint(int N1, int N2, int N3)	//�ִ밪 ����Լ�
{
	if (N1 > N2)
		return(N1 > N3) ? N1 : N3;
	else
		return (N2 > N3) ? N2 : N3;
}
int minpoint(int n1, int n2, int n3)	//�ּҰ� ����Լ�
{
	if (n1 < n2)
		return (n1 < n3) ? n1 : n3;
	else
		return (n1 < n3) ? n1 : n3;
}
int main()				
{
	int num1 = 0, num2 = 0, num3 = 0; 
	printf("�����Է�1:");		
	num1 = insert(num1);		//num1 �� �Է¹ޱ�
	printf("\n�����Է�2:");
	num2 = insert(num2);		//num2 �� �Է¹ޱ�
	printf("\n�����Է�3;");
	num3 = insert(num3);		//num3 �� �Է¹ޱ�
	printf("���� ū �� ���: %d \n", maxpoint(num1, num2, num3));
	printf("���� ���� �� ���: %d \n", minpoint(num1, num2, num3));
	return 0;
}