#include <stdio.h>

int main()
{

	double arr1[3][3];	//ù ��° �迭�� �� ��  
	
	/*
	arr1[0][0] arr1[0][1] arr1[0][2]
	arr1[1][0] arr1[1][1] arr1[1][2]
	arr1[2][0] arr1[2][1] arr1[2][2]
	��Ľ� arr1[0][0] = arr1[1][1]*arr1[2][2] - arr1[1][2]*arr1[2][1]...
	����� ���� = arr1[0][0]*(arr1[1][1]*arr1[2][2] - arr1[1][2]*arr1[2][1])
				- arr1[0][1]*(arr1[1][0]*arr1[2][2] - arr1[1][2]*arr1[2][0])
				+ arr1[0][2]*(arr1[1][0]*arr1[2][1] - arr1[1][1]*arr1[2][0])
	*/
	
	double arr2[3][3];	//�� ��° �迭�� �� ��  
	double arr3[3][3];	//�� �迭�� �տ� �̿�
	double arr4[3][3];	//�� �迭�� ���� �̿�
	double arr5[3][3];	//�� �迭�� ���� �̿�

	
	printf("arr1�� ������ ���� �����մϴ�.(�������� �����մϴ�.)");	
	for(int i = 0; i < 3; i++)	//ù ��° �迭�� �� �Է�  
	{
		for(int j = 0; j < 3; j++)
		{
			scanf_s("%lf", &arr1[i][j]);
		}
	}

	printf("arr2�� ������ ���� �����մϴ�.(�������� �����մϴ�.)");		
		for(int i = 0; i < 3; i++)	//�� ��° �迭�� �� �Է�
	{
		for(int j = 0; j < 3; j++)
		{
			scanf_s("%lf", &arr2[i][j]);
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
			printf("%13g", arr1[i][j]);
		}
		printf("\n");
	}
	
	printf("arr2�� ����մϴ�. \n"); //�� ��° �迭 ���  
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			printf("%13g", arr2[i][j]);
		}
		printf("\n");
	}
	
	printf("�� �迭�� ���� ����մϴ�. \n"); //�迭�� �� ���   
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			printf("%13g", arr3[i][j]);
		}
		printf("\n");
	}
	
	printf("�� �迭�� ���� ����մϴ�. \n"); //�迭�� �� ���   
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			printf("%13g", arr4[i][j]);
		}
		printf("\n");
	}
	
	printf("�� �迭�� ���� ����մϴ�. \n"); //�迭�� �� ���   
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			printf("%13g", arr5[i][j]);
		}
		printf("\n");
	}

		// deteriment ���ϱ�( det�� 0�̸� ������� �������� ����.) 
	double det1 = arr1[0][0]*(arr1[1][1]*arr1[2][2] - arr1[1][2]*arr1[2][1]);
	double det2 = -arr1[0][1]*(arr1[1][0]*arr1[2][2] - arr1[1][2]*arr1[2][0]);
	double det3 = arr1[0][2]*(arr1[1][0]*arr1[2][1] - arr1[1][1]*arr1[2][0]);
	double det  = det1 + det2 + det3;
	
	//��ġ��� ���ϱ� 
	double arr11[3][3] = {
	arr1[1][1]*arr1[2][2] - arr1[1][2]*arr1[2][1], arr1[0][1]*arr1[2][2]-arr1[0][2]*arr1[2][1], arr1[0][1]*arr1[1][2]-arr1[0][2]*arr1[2][1],
	arr1[1][0]*arr1[2][2] - arr1[1][2]*arr1[2][0], arr1[0][0]*arr1[2][2]-arr1[0][2]*arr1[2][0], arr1[0][0]*arr1[1][2]-arr1[0][2]*arr1[1][0],
	arr1[1][0]*arr1[2][1] - arr1[1][1]*arr1[2][0], arr1[0][0]*arr1[2][1]-arr1[0][1]*arr1[2][0] ,arr1[0][0]*arr1[1][1]-arr1[0][1]*arr1[1][0]
	};
	
	//��ġ��� * det�� �� 1 ���� �迭  = �����  
	double arr111[3][3] = {
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
						printf("%13g", arr111[i][j]);
					}
				printf("\n");
				
			}
		}
	return 0;	
}
