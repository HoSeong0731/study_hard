#include <stdio.h>	//ǥ�������������� ����
#include <stdlib.h>	//ǥ�ض��̺귯��������� ����  


int main()	//main�Լ�  
{
	// 1~30�� ���ڸ� �����ϰ� ������ 2���� �迭
	int data[4][4]
		= { rand() % 31 , rand() % 31 ,rand() % 31 ,rand() % 31 ,
		 rand() % 31 , rand() % 31 , rand() % 30, rand() % 31 ,
		 rand() % 31 , rand() % 31 , rand() % 31, rand() % 31 ,
		 rand() % 31 , rand() % 31 , rand() % 31, rand() % 31 };

	int leftdata[3];	//left������ �� ���� �迭  
	int updata[3];	//up������ �� ���� �迭
	int leftdiadata[3];	//leftdia������ �� ���� �迭
	int rightdiadata[3];	//rightdia	������ �� ���� �迭

	int i, j, result = 1, middle = 0;	//�ݺ����� ���ǹ����� ���� ���� ����  
	int left = data[0][0] * data[0][1];	//ó�� left��  
	int up = data[0][0] * data[1][0];	//ó�� right��
	int leftdia = data[0][1] * data[1][0];	//ó�� leftdia��
	int rightdia = data[0][3] * data[1][2];	//ó�� rightdia��

	printf("�����ϰ� �����ִ� ������ ��\n");	//������ �����ִ� �� ���  
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%3d ", data[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < 4; i++)	//�翷�� ���� �� �ִ� �� ����. 
	{
		for (j = 0; j < 3; j++)
		{
			if (left < data[i][j] * data[i][j + 1])
			{
				left = data[i][j] * data[i][j + 1];
				leftdata[0] = data[i][j];	//�� ����  
				leftdata[1] = data[i][j + 1];	//�� ����  
				leftdata[2] = data[i][j] * data[i][j + 1];	//�� ����(���� ��) 
			}
		}
	}

	for (i = 0; i < 3; i++)	//�� �Ʒ��� ���� �� �ִ� �� ����. 
	{
		for (j = 0; j < 4; j++)
		{
			if (up < data[i][j] * data[i + 1][j])
			{
				up = data[i][j] * data[i + 1][j];	//�Ŀ� �񱳸� ���� ����  
				updata[0] = data[i][j];	//�� ����  
				updata[1] = data[i + 1][j];	//�� ����  
				updata[2] = data[i][j] * data[i + 1][j];	//�� ����  (��� ��) 
			}
		}
	}

	for (i = 0; i < 3; i++)	//���� �밢��  �ִ� �� ����. 
	{
		for (j = 0; j < 3; j++)
		{
			if (leftdia < data[i][j + 1] * data[i + 1][j])
			{
				leftdia = data[i][j + 1] * data[i + 1][j];	//�Ŀ� �񱳸� ���� ����  
				leftdiadata[0] = data[i][j + 1];	//�� ����  
				leftdiadata[1] = data[i + 1][j];	//�� ����  
				leftdiadata[2] = data[i][j + 1] * data[i + 1][j];	//�� ����  (��� ��) 
			}
		}
	}

	for (i = 0; i < 3; i++)	//������ �밢�� �ִ� �� ����  
	{
		for (j = 0; j < 3; j++)
		{
			if (rightdia < data[i][j] * data[i + 1][j + 1])
			{
				rightdia = data[i][j] * data[i + 1][j + 1]; //�Ŀ� �񱳸� ���� ���� 
				rightdiadata[0] = data[i][j];		//�� ���� 
				rightdiadata[1] = data[i + 1][j + 1];	//�� ���� 
				rightdiadata[2] = data[i][j] * data[i + 1][j + 1];	//�� ���� (��� ��)  

			}
		}
	}


	if (result < leftdata[2])		//��� �� ���ϱ� (switch�� ����� ����) 
	{
		result = 1;
		middle = leftdata[2];
	}
	if (middle < updata[2])
	{
		result = 2;
		middle = updata[2];
	}
	if (middle < leftdiadata[2])
	{
		result = 3;
		middle = leftdiadata[2];
	}
	if (middle < rightdiadata[2])
	{
		result = 4;
		middle = rightdiadata[2];
	}

	switch (result) {	//switch���� �̿��� ��� ���  
	case 1:
		printf("Biggest product1: = %d X %d = %d", leftdata[0], leftdata[1], leftdata[2]);
		break;

	case 2:
		printf("Biggest product2: = %d X %d = %d", updata[0], updata[1], updata[2]);
		break;

	case 3:
		printf("Biggest product3: = %d X %d = %d", leftdiadata[0], leftdiadata[1], leftdiadata[2]);
		break;

	case 4:
		printf("Biggest product4: = %d X %d = %d", rightdiadata[0], rightdiadata[1], rightdiadata[2]);
		break;
	}

	return 0;	//main�Լ� ����  
}