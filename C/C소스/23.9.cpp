#include <stdio.h>	//ǥ�� ����� ���̺귯��
#include <windows.h>//������ �������  

typedef struct student	//����ü student�� ���ǿ� Student�� ���� typedef ������ ���� ����
{
	char name[20];	//�̸� ����
	char num[20];	//��ȣ ����
	int a;	//���� ���� ����
	int b;	//���� ���� ����
	int c;	//���� ���� ����
}Student;

typedef struct point	//����ü point�� ���ǿ� Point�� ���� typedef ������ ���� ����
{
	int xpos;	//��ǥ �� ����
	int ypos;	//��ǥ �� ����
}Point;

typedef struct circle	//����ü circle�� ���ǿ� Circle�� ���� typedef ������ ���� ����
{
	Point cen;	//����üPoint ����cen ����
	double rad;	//������ �� ����
	Student a;	//����üStudent ����a ����
}Circle;

void ShowCircleInfo(Circle *cptr)//����� ���� �Լ� ����
{
	printf("[%d, %d] \n", (cptr->cen).xpos, (cptr->cen).ypos);	//���
	printf("radius: %g \n\n", cptr->rad);						//���
	printf("�̸�:%s \n�й�:%s \n����:%d \n����:%d \n����:%d\n\n", (cptr->a).name, (cptr->a).num, (cptr->a).a, (cptr->a).b, (cptr->a).c);
	//���
}
int main()	//�����Լ�
{
	Circle c1 = {{1,2},3.5,"��ȣ��","2019202052",98,99,90 };	//����üCircle ����c1 ����
	Circle c2 = {2,4,3.9,"�ڼ���","2019803070",100,100,100};	//����üCircle ����c2 ����
	

	ShowCircleInfo(&c1);	//����� ���� �Լ� ȣ��
	ShowCircleInfo(&c2);	//����� ���� �Լ� ȣ��
	system("PAUSE");	//�Ͻ�����  
	return 0;	//�����Լ� ����
}

