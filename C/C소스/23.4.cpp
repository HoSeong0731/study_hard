#include <stdio.h>	//ǥ�� ����� ���̺귯��
#include <windows.h>//������ �������  

typedef struct person	//����ü person�� ���ǿ� Person�� ���� typedef ������ ���� ����
{
	char name[20];		//�̸� ����
	char phoneNum[20];	//��ȣ ����
	int age;			//���� ����
}Person;

typedef struct building	//����ü building�� ���ǿ� Bui�� ���� typedef ������ ���� ����
{
	char name[20];	//�ǹ� �̸� ����
	char num[20];	//������ ����
	int a;			//���� ����
	int b;			//���� ����
}Bui;

void ShowPersonInfo(Person man,Bui a)		//����� ���� �Լ� ����
{
	printf("name: %s \n", man.name);		//������ ����� ����� �� ���
	printf("phone: %s \n", man.phoneNum);	//������ ����� ����� �� ���
	printf("age: %d \n", man.age);			//������ ����� ����� �� ���
	printf("name: %s \n", a.name);			//������ ����� ����� �� ���
	printf("������: %s \n", a.num);			//������ ����� ����� �� ���
	printf("����: %d \n", a.a);				//������ ����� ����� �� ���
	printf("����: %d \n", a.b);				//������ ����� ����� �� ���
}

Person ReadPersonInfo(void)	//�Է��� ���� �Լ� ����
{
	Person man;				//����ü ���� ����
	printf("name: "); scanf("%s", man.name);		//����ü ������ ��� �Է�
	printf("phone: "); scanf("%s", man.phoneNum);	//����ü ������ ��� �Է�
	printf("age: "); scanf("%d", &man.age);			//����ü ������ ��� �Է�
	return man;
}

Bui Read(void)	//�Է��� ���� �Լ� ����
{
	Bui a;	//����ü ���� ����
	printf("name: "); scanf("%s", a.name);	//����ü ������ ��� �Է�
	printf("������: "); scanf("%s", a.num);	//����ü ������ ��� �Է�
	printf("����: "); scanf("%d", &a.a);	//����ü ������ ��� �Է�
	printf("����: "); scanf("%d", &a.b);	//����ü ������ ��� �Է�
	return a;	//a�� ��ȯ �� ����
}

int main()	//�����Լ�
{
	Person man = ReadPersonInfo();	//����ü ���� ���� �� �Լ� ȣ��

	printf("\n");					//�� �ٲ�  
	Bui a = Read();					//����ü ���� ���� �� �Լ� ȣ��

	printf("\n");					//�� �ٲ�  
	ShowPersonInfo(man,a);			//�Լ� ȣ��
	system("PAUSE");	//�Ͻ�����  
	return 0;	//�����Լ� ����
}
