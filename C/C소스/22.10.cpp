#include <stdio.h>	//����� ������� 
#include <math.h>	//���а��� ������� 

struct employe	//employe��� �̸��� ����ü ����
{
	char name[20];	//�̸� ����
	char num[20];	//��ȣ ����
	char money[20];	//�޿� ����
};

int main()
{
	struct employe person[3];	//����ü �迭 ����
	int i;	//�ݺ��� ���� ���� ����
	for (i = 0; i < 3; i++)	//�� ���� �Է� �޴´�
	{
		printf("������ �̸�:");
		scanf("%s", person[i].name);
		printf("�ֹε�� ��ȣ:");
		scanf("%s", person[i].num);
		printf("�޿�����:");
		scanf("%s", person[i].money);
	}
	
	for (i = 0; i < 3; i++)	//�� ����� �����Ͽ� ����� ���� ���
	{
		printf("\n%d���� ����:\n",i);
		printf("�̸�:%s �ֹε�� ��ȣ:%s �޿�����:%s  \n", person[i].name, person[i].num, person[i].money);
	}
	return 0;	//�����Լ� ����  
}

