#include <stdio.h>	//����� ������� 
#include <math.h>	//���а��� ������� 

struct employe	//employe ��� �̸��� ����ü ����
{
	char name[20];	//�̸� ����
	char num[20];	//��ȣ ����
	int money;	//�޿� ����
};

int main()
{
	struct employe p;	//����ü ���� ����

	printf("������ �̸�:");
	scanf("%s", p.name);//p��� ��� name ���
	printf("�ֹε�� ��ȣ:"); 
	scanf("%s", p.num);//p��� ��� num ���
	printf("�޿�����:"); 
	scanf("%d", &(p.money));//p��� ��� money ���
	
	printf("\n");	//����  
	printf("�̸�: %s, �ֹι�ȣ: %s, �޿�: %d", p.name, p.num, p.money);	//��� 
	return 0;	//�����Լ� ���� 
}

