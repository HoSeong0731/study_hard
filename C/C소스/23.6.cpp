#include <stdio.h>	//ǥ�� ����� ���̺귯��
#include <windows.h>//������ �������  

typedef struct point	//����ü point�� ���ǿ� Point�� ���� typedef ������ ���� ����
{
	int xpos;	//��ǥ �� ����
	int ypos;	//��ǥ �� ����
} Point;

typedef struct grade	//����ü grade�� ���ǿ� Grade�� ���� typedef ������ ���� ����
{
	char name[20];	//�л��� �̸� ����
	char point[20];	//�л��� ���� ����
} Grade;

int main()	//�����Լ�
{
	Point pos1 = { 1,2 };	//����üPoint ���� pos1����
	Point pos2;				//����üPoint ���� pos2����
	pos2 = pos1;
	Grade man1 = { "��ȣ��", "4.5" };	//����üGrade ���� man1����
	Grade man2;							//����üGrade ���� man2����
	man2 = man1;
	
	printf("ũ��: %d \n", sizeof(pos1));			//���
	printf("[%d, %d] \n", pos1.xpos, pos1.ypos);	//���
	
	printf("ũ��: %d \n", sizeof(pos2));			//���
	printf("[%d, %d] \n", pos2.xpos, pos2.ypos);	//���
	printf("�̸�: %s, ����: %s \n", man1.name, man1.point);	//���
	printf("�̸�: %s, ����: %s", man2.name, man2.point);	//���
	system("PAUSE");	//�Ͻ�����  
	return 0;	//�����Լ� ����
}
