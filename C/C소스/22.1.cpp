#include <stdio.h>	//����� ������� 
#include <math.h>	//���а��� �������  
struct point	//point ����ü ����  
{
	int xpos;
	int ypos;
};

int main()	//main�Լ�  
{
	struct point pos1, pos2;	//����ü ���� pos1, pos2����  
	double distance;	//���� ���ϱ� ���� ���� ����  
	
	fputs("point1 pos: ", stdout);	 
	scanf("%d %d", &pos1.xpos, &pos1.ypos);	//pos1�� x,y ����  
	
	fputs("point2 pos: ", stdout);
	scanf("%d %d", &pos2.xpos, &pos2.ypos);	//pos2�� x,y ����  
	
	distance=sqrt((double)((pos1.xpos-pos2.xpos)*(pos1.xpos-pos2.xpos)+(pos1.ypos-pos2.ypos)*(pos1.ypos-pos2.ypos)));
	//sqrt = math������Ͽ� �ִ� �����Լ��� �������� ��ȯ�Ѵ�. 
	printf("�� ���� ������ %g�̸�, ���̴� %g�Դϴ�.",distance, (distance/2)*(distance/2)*3.14);
	return 0;
}
