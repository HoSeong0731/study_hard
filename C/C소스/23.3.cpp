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

void Showpoint(Grade num)	//����ü Grade�� ���   
{
	printf("�̸�: %s ����: %s \n", num.name, num.point);	//���
}	

void ShowPosition(Point pos)//����ü Point�� ���  
{
	printf("[%d, %d] \n", pos.xpos, pos.ypos);	//���
}

Grade GetCurrentgrade()		//����ü Grade�� �Է�  
{
	Grade num;	//����üGrade ����num����
	printf("�л��� �̸��� �Է��ϼ���: ");	//���
	scanf("%s", num.name);					//�Է�  
	printf("\n�л��� ������ �Է��ϼ���:");	//���
	scanf("%s", num.point);					//�Է�
	return num;		//num���� �ǵ���  
}

Point GetCurrentPosition()	//����ü Point�� �Է�  
{
	Point cen;	//����üPoint ����cen����
	printf("Input current pos(x): ");	//���
	scanf("%d", &cen.xpos);				//�Է�
	printf("Input current pos(y): ");	//���
	scanf("%d", &cen.ypos);				//�Է�
	return cen;		//cen���� �ǵ���  
}

int main()	//�����Լ�
{
	Point curPos = GetCurrentPosition();//����üPoint ����curPos����
	ShowPosition(curPos);				//curPos���  
	Grade grade = GetCurrentgrade();	//����üGrade ����grade����
	Showpoint(grade);				  	//grade��� 
	system("PAUSE");	//�Ͻ�����  	
	return 0;	//�����Լ� ����
}
