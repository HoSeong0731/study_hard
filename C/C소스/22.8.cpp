#include <stdio.h>	//����� �������
#include <math.h>	//���а��� �������

struct point	//point ��� �̸���; ����ü ����
{
	int xpos;	//��ǥ �� ����
	int ypos;	//��ǥ �� ����
	struct point * ptr;	//����ü ������ ����� ����ü ������ ������ ����
};
int main()
{
	struct point pos1= {1 , 1};	//����ü ���� ����
	struct point pos2= {2 , 2 };
	struct point pos3= {3 , 3 };
	int a, b, c;	//�� �� ������ �Ÿ��� ���� �� ����
	pos1.ptr = &pos2;	//pos1�� pos2�� ����
	pos2.ptr = &pos3;	//pos2�� pos3�� ����
	pos3.ptr = &pos1;	//pos3�� pos1�� ����

	printf("���� ���� ����----\n");
	printf("[%d, %d]��(��) [%d, %d] ���� \n", pos1.xpos, pos1.ypos, pos1.ptr->xpos, pos1.ptr->ypos);
	printf("[%d, %d]��(��) [%d, %d] ���� \n", pos2.xpos, pos2.ypos, pos2.ptr->xpos, pos2.ptr->ypos);
	printf("[%d, %d]��(��) [%d, %d] ���� \n", pos3.xpos, pos3.ypos, pos3.ptr->xpos, pos3.ptr->ypos);
	
	printf("����� ���� ���� ����---\n");	//ó������ �ڱ� ���� ����� ���� �����ڸ� ������� ����� ���� ���
	a = sqrt((double)(pos1.xpos - pos1.ptr->xpos)*(pos1.xpos - pos1.ptr->xpos) + (pos1.ypos - pos1.ptr->ypos)*(pos1.ypos - pos1.ptr->ypos));
	b = sqrt((double)(pos2.xpos - pos2.ptr->xpos)*(pos2.xpos - pos2.ptr->xpos) + (pos2.ypos - pos2.ptr->ypos)*(pos2.ypos - pos2.ptr->ypos));
	c = sqrt((double)(pos3.xpos - pos3.ptr->xpos)*(pos3.xpos - pos3.ptr->xpos) + (pos3.ypos - pos3.ptr->ypos)*(pos3.ypos - pos3.ptr->ypos));
	//�Ÿ� ���ϴ� ����
	
	printf("1��° ��ǥ:%d\n", a);
	printf("2��° ��ǥ:%d\n", b);
	printf("3��° ��ǥ:%d\n", c);
	return 0;	//main�Լ�����  
}

