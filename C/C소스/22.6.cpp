#include <stdio.h>	//����� �������
#include <math.h>	//���а��� �������

struct point	//point ����ü ����
{
	int xpos;
	int ypos;
};

int main()	//main�Լ�  
{
	struct point pos1 ={1,2};	//�Է�(����ü point) 
	struct point pos2 ={100,200};	//�Է�(����ü point) 
	struct point * pptr = &pos1;	//�Է�(����ü ������) 
	
	(*pptr).xpos += 4;	//���� 
	(*pptr).ypos += 5;	//����  
	
	pptr = &pos2;	//pos1���� pos2�� ���� 
	pptr ->xpos += 1;	//���� 
	pptr ->ypos += 2;	//����  
		
	double distance=sqrt((double)((pos1.xpos-pos2.xpos)*(pos1.xpos-pos2.xpos)+(pos1.ypos-pos2.ypos)*(pos1.ypos-pos2.ypos)));
	//�Ÿ� ����  
	printf("%g",distance);	//��� 
	return 0; //�����Լ� ����  
 } 
