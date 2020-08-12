#include <stdio.h>	//ǥ�� ����� ���̺귯��
#include <windows.h>//������ �������  

typedef struct point	//����ü point�� ���ǿ� Point�� ���� typedef ������ ���� ����
{
	int xpos;	//��ǥ �� ����
	int ypos;	//��ǥ �� ����
}Point;

typedef struct score//����ü score�� ���ǿ� Score�� ���� typedef ������ ���� ����
{
	int r;		//����� ����
	int d;		//����� ����
	int t;		//���м��� ����
	double i;	//��հ� ����
}Score;

void OrgSymTrans(Point * ptr)	//x�� ��Ī�� y�� ��Ī�� ���� �Լ� ����
{
	int a, b;			//�ӽ� ���� �ޱ� ���� ����
	a = (ptr->ypos)*-1;	//x���Ī
	b = (ptr->xpos)*-1;	//y���Ī
	ptr->xpos = a;	//�����ڸ� ������� �ϴ� ������ a�� ����
	ptr->ypos = b;	//�����ڸ� ������� �ϴ� ������ b�� ����
}

void average(Score * aaa)	//����� ���ϱ� ���� �Լ� ����
{
	
	aaa->i = (aaa->r + aaa->d + aaa->t) / 3;	//��հ� ���ϱ�
}

void ShowPosition(Point pos)	//����� ���� �Լ� ����
{
	printf("[%d, %d] \n", pos.xpos, pos.ypos);	//���
}

void showpoint(Score abc)	//������ ����ϱ� ���� �Լ�
{
	printf("����:%d ����:%d ����:%d\n���:%lf", abc.r, abc.d, abc.t,abc.i);	//���
}

int main()	//�����Լ�
{
	Point pos = { 7,-5 };	//����üPoint ����pos ����
	Score abc = { 90,98,95 };//����üScore ����abc ����
	OrgSymTrans(&pos);		//��Ī�ϱ� ���� �Լ� ȣ��
	ShowPosition(pos);		//�ٲ� ��ǥ�� Ȯ���ϱ� ���� �Լ� ȣ��
	OrgSymTrans(&pos);		//��Ī�ϱ� ���� �Լ� ȣ��
	ShowPosition(pos);		//�ٲ� ��ǥ ���� Ȯ�� �ϱ� ���� �Լ� ȣ��
	average(&abc);			//����� ���ϱ� ���� �Լ� ȣ��
	showpoint(abc);			//������ ����ϱ� ���� �Լ� ȣ��
	system("PAUSE");		//�Ͻ�����  
	return 0;	//�����Լ� ����
}
