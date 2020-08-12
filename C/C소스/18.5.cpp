#include <stdio.h>	//����� ������� ����
void ShowArr2Dstyle(int(*arr)[4], int column)	//�迭��� ��ü��� �Լ�  
{
	int i, j;	// �ݺ����� ���� i,j ���� ����  
	for (i = 0; i < column; i++) //���� �ݺ����� 
	{
		for (j = 0; j < 4; j++)	//���� �ݺ����� 
		{
			printf("%d", arr[i][j]);	//������ �迭 ���  
		}printf("\n");	//�ٹٲ�  
	}
}

int Sum2Darr(int arr[][4], int column)	//�迭����� �� ��ȯ �Լ�  
{
	int i, j, sum= 0;	//�ݺ����� ���� i,j�� ��ҵ� �� ���� sum���� ����  
	for (i = 0; i < column; i++)//���� �ݺ�����  
	{
		for (j = 0; j < 4; j++)	//���� �ݺ�����  
		{
			sum += arr[i][j];	//������ �迭 ���ϱ�  
			
		}
	}
	return sum;	//sum�� ��ȯ  
}

int main()	//main�Լ� ���� 
{
	int arr1[2][4] = { 1,2,3,4,5,6,7,8 };		//����4 ����2 2�����迭 ���� 
	int arr2[3][4] = { 1,1,1,1,3,3,3,3,5,5,5,5 };	//����4 ����3 2�����迭 ���� 

	ShowArr2Dstyle(arr1, sizeof(arr1) / sizeof(arr1[0]));	//�迭��� ��ü��� �Լ� ����  
	ShowArr2Dstyle(arr2, sizeof(arr2) / sizeof(arr2[0]));	//�迭��� ��ü��� �Լ� ����
	printf("arr1�� ��: %d \n", Sum2Darr(arr1, sizeof(arr1) / sizeof(arr1[0])));	//�迭����� �� ��ȯ �Լ� ����  
	printf("arr2�� ��: %d \n", Sum2Darr(arr2, sizeof(arr2) / sizeof(arr2[0])));	//�迭����� �� ��ȯ �Լ� ����  
	return 0;	//�����Լ����� 
}
