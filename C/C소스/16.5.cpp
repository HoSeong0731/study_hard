#include <stdio.h>	//ǥ������� ������� ���� 
int main()	//main�Լ�
{
	int mean=0, i, j;		//int �� mean, i, j���� ����  
	int record [3][3][2]={ 	//����, ����, ����  int�� 3���� �迭  
	{
	{70,80}, 
	{94,90},
	{70,85}
	},
	{
	{83,90},
	{95,60},
	{90,82}
	},
	{
	{98,89},
	{99,94},
	{91,87}
	}
};

for(i=0; i<3; i++)	//���� �ݺ���	(�� ����(������ �κ�) ��� ���ϴ� ���� 3������ �������� �־� ��ø�� ������ ����. 
	for(j=0; j<2; j++)	//���� �ݺ���  
		mean+= record[0][i][j];	//���� ����  
printf("A�б� ��ü ���: %g \n", (double)mean/6);	//�л� �� ��ŭ ����  
mean=0;	//mean�� �ʱ�ȭ  

for(i=0; i<3; i++)
	for(j=0; j<2; j++)
		mean+= record[1][i][j];
printf("B�б� ��ü ���: %g \n", (double)mean/6);
mean=0;

for(i=0; i<3; i++)
	for(j=0; j<2; j++)
		mean+= record[2][i][j];
printf("C�б� ��ü ���: %g \n", (double)mean/6);
mean=0;
return 0;	//�����Լ�����  
}

