#include <stdio.h>	//ǥ������� ������� ����
void SwapIntPtr(int *p1, int *p2) //swap�Լ� (ptr�� ����Ű�� �� ���� ) 
{
	int * temp=p1;	
	p1=p2;	//p1�� p2�� ����Ű�� ������ �ٲ�(���� ���� �ٲ�)  
	p2=temp;//p2�� p1�� ����Ű�� ������ �ٲ�(���� ���� �ٲ�)  
}

int main()	//main�Լ�
{
	int num1=10, num2=20;	//��������  
	int *ptr1, *ptr2;	//�����ͺ��� ����  
	ptr1=&num1, ptr2=&num2;	//������ ����  
	printf("*ptr1, *ptr2: %d %d \n", *ptr1, *ptr2);	//�Լ� ������  
	
	SwapIntPtr(ptr1, ptr2); //swap�Լ� ����(���� ���� ���޵ǰ� ������� ����)
	printf("*ptr1, *ptr2: %d %d \n", *ptr1, *ptr2); //�Լ� ������  
	return 0;	//�����Լ� ����  
}
