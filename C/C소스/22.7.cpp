#include<stdio.h>	//����� �������
#include<math.h>	//���а��� �������

struct point	//point��� �̸��� ����ü ����
{
	int xpos;	//��ǥ �� 
	int ypos;	//��ǥ ��
};

struct circle	//circle��� �̸��� ����ü ����
{
	double radius;	//������ ����
	struct point * center;	//����ü ������ ����� ����ü ������ ������ ����
};

int main()
{
	struct point cen = { 2,7 };	//����ü ���� ����
	double rad = 5.5;	//������ ��
	struct point ptr = cen;	//����ü ������ ���� �� cen�� ����Ų��
	double arr;	//���簢���� ���̸� ������ ����
	struct circle ring = { rad,&cen };	//����ü ���� ����
	
	printf("���� ������: %g\n", ring.radius);	//ring�̶�� ��� radius���
	printf("���� �߽� [%d, %d]\n", (ring.center)->xpos, (ring.center)->ypos);	//��ǥ �� ���
	
	ptr.xpos = ptr.xpos * 5;	//x��ǥ 5�� ����
	ptr.ypos = ptr.ypos * 5;	//y��ǥ 5�� ����
	
	arr = (ptr.xpos - cen.xpos)*(ptr.ypos - cen.ypos);	//���� ���ϴ� ����
	printf("���� �߽ɰ� 5�� ������ ���� �밢������ �ϴ� ���簢���� ���̴�:%lf�̴�", arr);	//���  
	return 0;	//�����Լ� ����  
}

