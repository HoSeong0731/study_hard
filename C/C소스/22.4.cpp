#include <stdio.h>	//����� �������
#include <math.h>	//���а��� �������  

struct point	//point ����ü ����  
{
	int xpos;
	int ypos;
};

int main()	//main�Լ�  
{
	struct point arr[4];	//����ü point���� ����  
	int i;
	double arr2[3];	//�Ŀ� arr���� ���̸� ����  
	for(i=0; i<3; i++)	//arr�� ���� �Է� ����  
	{
		printf("���� ��ǥ �Է�: ");
		scanf("%d %d", &arr[i].xpos, &arr[i].ypos);
	}
	
	arr[3].xpos = arr[0].xpos;	//4��° ĭ�� 1��° ĭ�� ���� ���� 
	arr[3].ypos = arr[0].ypos;	//4���� ĭ�� 1��° ĭ�� ���� ����  
	
	for(i=0; i<3; i++)	//���  
	{
		arr2[i] = sqrt((double)((arr[i].xpos-arr[i+1].xpos)*(arr[i].xpos-arr[i+1].xpos)+(arr[i].ypos-arr[i+1].ypos)*(arr[i].ypos-arr[i+1].ypos)));
	}
	
	printf("%g %g %g", arr2[0], arr2[1], arr2[2]);	//��� 
	return 0;	//�����Լ� ����  
}
