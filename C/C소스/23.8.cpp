#include <stdio.h> 	//ǥ�� ����� ���̺귯��
#include <windows.h>//������ �������  

typedef struct student	//����ü student�� ���ǿ� Student�� ���� typedef ������ ���� ����
{
	char name[20];	//�̸� ����
	char stdnum[20];//�й� ����
	char school[20];//�б� �̸�����
	char major[20];	//���� ����
	int year;		//�г� ����
}Student;

typedef struct building	//����ü bill�� ���ǿ� Bill�� ���� typedef ������ ���� ����
{
	char name[20];	//�ǹ��̸� ����
	char num[20];	//���� ����
	int a;			//���� ����
	int b;			//���� ����
}Bui;

void Show(Bui * pptr)	//�ǹ����� ����ϱ� ���� �Լ� ����
{
	printf("�ǹ��̸�: %s \n", pptr->name);	//����ü ������ ��� ���
	printf("�ǹ� ����: %s\n", pptr->num);	//����ü ������ ��� ���
	printf("�ǹ�����: %d \n", pptr->a);		//����ü ������ ��� ���
	printf("�ǹ� ����: %d\n", pptr->b);	//����ü ������ ��� ���
}

void ShowStudentInfo(Student *sptr)	//�л����� ����ϱ� ���� �Լ� ����
{
	printf("�л� �̸�: %s \n", sptr->name);			//����ü ������ ��� ���
	printf("�л� ������ȣ: %s \n", sptr->stdnum);	//����ü ������ ��� ���
	printf("�б� �̸�: %s \n", sptr->school);		//����ü ������ ��� ���
	printf("���� ����: %s \n", sptr->major);		//����ü ������ ��� ���
	printf("�г�: %d \n", sptr->year);				//����ü ������ ��� ���
}

int main()	//�����Լ�
{
	Student arr[7];	//����üStudent �迭arr[7] ����
	Bui bbb[3];		//����üBui �迭bbb[3] ����
	int i;			//�ݺ��� ���� ����i ����

	for (i = 0; i < 1; i++)	//������ �Է� �ޱ� ���� �ݺ���
	{
		printf("�̸�:"); scanf("%s", arr[i].name);	//����ü ���� ��� �Է�
		printf("��ȣ:"); scanf("%s", arr[i].stdnum);//����ü ���� ��� �Է�
		printf("�б�:"); scanf("%s", arr[i].school);//����ü ���� ��� �Է�
		printf("����:"); scanf("%s", arr[i].major);	//����ü ���� ��� �Է�
		printf("�г�:"); scanf("%d", &arr[i].year);	//����ü ���� ��� �Է�
	}
	for (i = 0; i < 1; i++)	//������ �Է� �ޱ� ���� �ݺ���
	{
		printf("�ǹ��̸�:"); scanf("%s", bbb[i].name);	//����ü ���� ��� �Է�
		printf("���� ��:"); scanf("%s", bbb[i].num);	//����ü ���� ��� �Է�
		printf("����:"); scanf("%d", &bbb[i].a);		//����ü ���� ��� �Է�
		printf("����:"); scanf("%d", &bbb[i].b);		//����ü ���� ��� �Է�
	}
	for (i = 0; i < 1; i++)	//����� ���� �ݺ���
	{
		ShowStudentInfo(&arr[i]);	//�Լ� ȣ��
	}
	for (i = 0; i < 1; i++)			//����� ���� �ݺ���
	{
		Show(&bbb[i]);	//�Լ� ȣ��
	}
	system("PAUSE");	//�Ͻ�����  
	return 0;	//�����Լ� ����
}

