#include <stdio.h>

int main()
{

	int arr1[3][3]={};	//ù ��° �迭�� �� ��  
	
	/*
	arr1[0][0] arr1[0][1] arr1[0][2]
	arr1[1][0] arr1[1][1] arr1[1][2]
	arr1[2][0] arr1[2][1] arr1[2][2]
	��Ľ� arr1[0][0] = arr1[1][1]*arr1[2][2] - arr1[1][2]*arr1[2][1]...
	����� ���� = arr1[0][0]*(arr1[1][1]*arr1[2][2] - arr1[1][2]*arr1[2][1])
				- arr1[0][1]*(arr1[1][0]*arr1[2][2] - arr1[1][2]*arr1[2][0])
				+ arr1[0][2]*(arr1[1][0]*arr1[2][1] - arr1[1][1]*arr1[2][0])
	*/
	
	int arr2[3][3]={};	//�� ��° �迭�� �� ��  
	int arr3[3][3]={};	//�� �迭�� �տ� �̿�
	int arr4[3][3]={};	//�� �迭�� ���� �̿�
	int arr5[3][3]={};	//�� �迭�� ���� �̿�

	
	printf("arr1�� ������ ���� �����մϴ�.(�������� �����մϴ�.)");	
	for(int i = 0; i < 3; i++)	//ù ��° �迭�� �� �Է�  
	{
		for(int j = 0; j < 3; j++)
		{
			scanf("%d", &arr1[i][j]);
		}
	}
	
	// deteriment ���ϱ�( det�� 0�̸� ������� �������� ����.) 
	int det1 = arr1[0][0]*(arr1[1][1]*arr1[2][2] - arr1[1][2]*arr1[2][1]);
	int det2 = -arr1[0][1]*(arr1[1][0]*arr1[2][2] - arr1[1][2]*arr1[2][0]);
	int det3 = arr1[0][2]*(arr1[1][0]*arr1[2][1] - arr1[1][1]*arr1[2][0]);
	int det  = det1 + det2 + det3;
	printf("det1: %d\n",det1);
	printf("det2: %d\n",det2);
	printf("det3: %d\n",det3);
	
	
	
	
	//��ġ��� ���ϱ� 
	int arr11[3][3] = {
	arr1[1][1]*arr1[2][2] - arr1[1][2]*arr1[2][1], arr1[0][1]*arr1[2][2]-arr1[0][2]*arr1[2][1], arr1[0][1]*arr1[1][2]-arr1[0][2]*arr1[2][1],
	arr1[1][0]*arr1[2][2] - arr1[1][2]*arr1[2][0], arr1[0][0]*arr1[2][2]-arr1[0][2]*arr1[2][0], arr1[0][0]*arr1[1][2]-arr1[0][2]*arr1[1][0],
	arr1[1][0]*arr1[2][1] - arr1[1][1]*arr1[2][0], arr1[0][0]*arr1[2][1]-arr1[0][1]*arr1[2][0] ,arr1[0][0]*arr1[1][1]-arr1[0][1]*arr1[1][0]
	};
	
	//��ġ��� * det�� �� 1 ���� �迭  = �����  
	int arr111[3][3] = {
	 arr11[0][0]*det, arr11[0][1]*det, arr11[0][2]*det,
	 arr11[1][0]*det, arr11[1][1]*det, arr11[1][2]*det,
	 arr11[2][0]*det, arr11[2][1]*det, arr11[2][2]*det
	};
	
	//����� ���ϱ�
	
	if(det == 0) 
	{
	 	printf("������� �������� �ʽ��ϴ�.");
	}
	else{
	printf("������� ����մϴ�. \n");	//����� ���  
		for(int i = 0; i < 3; i++)
			{
				for(int j = 0; j < 3; j++)
					{
						printf("%3d", arr111[i][j]);
					}
				printf("\n");
				
			}
		}
	
	


	printf("arr2�� ������ ���� �����մϴ�.(�������� �����մϴ�.)");		
		for(int i = 0; i < 3; i++)	//�� ��° �迭�� �� �Է�
	{
		for(int j = 0; j < 3; j++)
		{
			scanf("%d", &arr2[i][j]);
		}
	} 
	
		for(int i = 0; i < 3; i++)	//�迭�� ���� �ݺ�  
	{
		for(int j = 0; j < 3; j++)
		{
			arr3[i][j]=arr1[i][j]+arr2[i][j];
		}
	}
	
	for(int i = 0; i < 3; i++)		//�迭�� ���� �ݺ�  
	{
		for(int j = 0; j < 3; j++)
		{
			arr4[i][j]=arr1[i][j]-arr2[i][j];
		}
	}
	
	for(int i = 0; i < 3; i++)		//�迭�� ���� �ݺ�  
	{
		for(int j = 0; j < 3; j++)
		{
			arr5[i][j]=arr1[i][j]*arr2[i][j];
		}
	}
	
	printf("arr1�� ����մϴ�. \n");	//ù ��° �迭 ���  
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			printf("%3d", arr1[i][j]);
		}
		printf("\n");
	}
	
	printf("arr2�� ����մϴ�. \n"); //�� ��° �迭 ���  
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			printf("%3d", arr2[i][j]);
		}
		printf("\n");
	}
	
	printf("�� �迭�� ���� ����մϴ�. \n"); //�迭�� �� ���   
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			printf("%3d", arr3[i][j]);
		}
		printf("\n");
	}
	
	printf("�� �迭�� ���� ����մϴ�. \n"); //�迭�� �� ���   
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			printf("%3d", arr4[i][j]);
		}
		printf("\n");
	}
	
	printf("�� �迭�� ���� ����մϴ�. \n"); //�迭�� �� ���   
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			printf("%3d", arr5[i][j]);
		}
		printf("\n");
	}

	
	
}
