#include <stdio.h>		//����� ������� ����

void SosimpleFunc(void)
{
	printf(" I'm so simple");
	
}

int main(void)	//main�Լ� ���� 
{
	int num =20;	//�������� 
	void * ptr;		//�����ͺ�������  
	
	ptr= &num;	//���� num���� �ּ� �� ����   
	printf("%p \n", ptr);	
	
	ptr = SosimpleFunc; //�Լ� So...�� �ּ� �� ����  
	printf("%p \n", ptr);
	return 0;
}

