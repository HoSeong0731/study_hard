#include <stdio.h>	//ǥ�� ����� ���̺귯��
#include <math.h>	//���İ��� �������  
#include <windows.h>//������ �������  

typedef struct point	//����ü point�� ���ǿ� Point�� ���� typedef ������ ���� ����
{
	int xpos;	//��ǥ �� ����
	int ypos;	//��ǥ �� ����
} Point;

Point AddPoint(Point pos1, Point pos2)	//�����Լ�  
{
	Point pos = { pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos };
	return pos;	//pos�� �ǵ���  
}

Point MinPoint(Point pos1, Point pos2)	//�����Լ�  
{
	Point pos = { pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos };
	return pos;	//pos�� �ǵ���  
}

int main()	//�����Լ�
{
	Point pos1 = { 5, 6 };	//����üPoint ���� pos1����
	Point pos2 = { 2, 9 };	//����üPoint ���� pos2����
	Point result;			//����üPoint ���� result����
	double Distance = sqrt((double)(pos1.xpos - pos2.xpos)*(pos1.xpos - pos2.xpos) + (pos1.ypos - pos2.ypos)*(pos1.ypos - pos2.ypos));
	//�Ÿ�����
	 
	result = AddPoint(pos1, pos2);						//�����Լ�����  
	printf("[%d, %d] \n", result.xpos, result.ypos);	//���  

	result = MinPoint(pos1, pos2);						//�����Լ�����  
	printf("[%d, %d] \n", result.xpos, result.ypos);	//���  
	printf("%lf \n", Distance);							//���  
	system("PAUSE");	//�Ͻ�����  
	return 0;	//�����Լ� ����
}
