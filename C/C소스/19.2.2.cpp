#include<stdio.h>	//����� ������� ����

int OlderFirst(int age1, int age2)	//���ڰ��� OlderFirst�Լ��� �� ���� 
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
	first = OlderFirst(age1, age2);
	printf("%d���� %d�� �� % d���� ���� ����! \n\n", age1, age2, first);	//��ȯ�� first�� ���  
	
	printf("������� 2 ");
	first = YoungerFirst(age1, age2);
	printf("%d���� %d�� �� % d���� ���� ����! \n\n", age1, age2, first);	//��ȯ�� first�� ��� 	
	return 0;	//main�Լ�����  
}

