#include<stdio.h>	//����� ������� ����

int WhoIsFirst(int age1, int age2, int(*cmp)(int n1,int n2))	//���� ���ϴ� �Լ�  
{
	return cmp(age1, age2); //first���� ��ȯ  
}

int OlderFirst(int age1, int age2) //���ڰ��� OlderFirst�Լ��� �� ����  
{
	if(age1>age2)	//���ǹ� ������ ���ڰ� ū �� ��ȯ  
		return age1;
	else if(age1<age2)
		return age2;
	else
	return 0;
}

int YoungerFirst(int age1, int age2)//���ڰ��� YoungerFirst�Լ��� �� ����    
{

	if(age1<age2)	//���ǹ� ������ ���ڰ� ���� �� ��ȯ  
		return age1;
	else if(age1>age2)
		return age2;
	else
		return 0;
}

int main()	//main�Լ� ����  
{
	int age1 = 20;	//���� ��������1 
	int age2 = 30;	//���� ��������2 
	int first;		//������ ���� ���� ����  
	
	printf("������� 1 ");
	first = WhoIsFirst( age1, age2, OlderFirst);	//���� ���ϴ� �Լ� ����   
	printf("%d���� %d�� �� %d���� ���� ����! \n\n", age1, age2, first);
	
	printf("������� 2 ");
	first = WhoIsFirst( age1, age2, YoungerFirst);	//���� ���ϴ� �Լ� ����  
	printf("%d���� %d�� �� %d���� ���� ����! \n\n", age1, age2, first);
	return 0;	//main�Լ� ����  
}
