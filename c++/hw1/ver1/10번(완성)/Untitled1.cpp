#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <time.h>

using namespace std;

void ComSel(int *arr); // ��ǻ�Ͱ� 4���� ���ڸ� ����
int IsValid(int *arr); // ����� �Է� ��ȿ�� �˻�. ��ȿ�ϸ� 1 ����
void UsrSel(int *arr); // ����� 4���� ���ڸ� �Է�.
int Compare(int *arr1, int *arr2); // ���� ��� ��.

int main(void)
{
	int comArr[4];		// ��ǻ���� �ڵ� ����
	int usrArr[4];		// ����ڿ� ���� ����
	int result=0;		// �ݺ��� ����  

	printf("Start Game! \n");
	ComSel(comArr);	//��ǻ���� ���� ���� �Լ�  
	cout << comArr[0] <<endl;
	cout << comArr[1] <<endl;
	cout << comArr[2] <<endl;
	cout << comArr[3] <<endl;
	while(result!=1)	//result�� 1�϶� ���� �ݺ�  
	{
		UsrSel(usrArr);	//������ ���� ���� �Լ�  
		result=Compare(comArr, usrArr);	//����� �Լ� 
		printf("\n");
	}
	printf("Game End! \n");
	return 0;
}

void ComSel(int *arr)	// ��ǻ�Ͱ� 4���� ���ڸ� ����
{
	srand((int)time(NULL));	//�������� 
	arr[0]=rand()%9+1;		//���� �ڸ� ���� ����(���� ���ڰ� 1�̻��̾�� ��.) 
	do{					
		arr[1]=rand()%9;	//���� �ڸ� ���� ����(���� �ڸ��� ��ġ�� ���� �� ����) 
	}while(arr[0]==arr[1]);
	do{					
		arr[2]=rand()%9;	//���� �ڸ� ���� ����(���� �ڸ��� ���� �ڸ� ���ڰ� ��ġ�� ���� �� ����) 
	}while((arr[0]==arr[2])or(arr[1]==arr[2])); 
	do{					
		arr[3]=rand()%9;	//���� �ڸ� ���� ����(���� �ڸ��� ���� �ڸ� ���ڰ� ��ġ�� ���� �� ����) 
	}while((arr[0]==arr[3])or(arr[1]==arr[3])or(arr[2]==arr[3]));
}

int IsValid(int *arr) 	//user�� �ùٸ� �����Է��ߴ��� �˻�  
{
	if(arr[0]==arr[1] or arr[0]==arr[2] or arr[0]==arr[3] or arr[1]==arr[2] or arr[1]==arr[3] or arr[2]==arr[3] )	
	//������ ������ ���� 4���� ��ģ�ٸ�  
		return 0;	//0���� ��ȯ 
	else	//��ġ�� �ʴ� �ٸ�  
		return 1;	//1���� ��ȯ  
}

void UsrSel(int *arr)	//������ �Է��� ���� �޴� �Լ�  
{
	int valid;
	printf("4���� ���� ���� : ");

	while(1)
	{
		scanf("%1d %1d %1d %1d", &arr[0], &arr[1], &arr[2], &arr[3]);	//�ϳ����� �Է¹ް� �ϱ� ���� %1d�� ��. 
		fflush(stdin);		//�Է¹��� ����� 
		valid=IsValid(arr);	//valid���� isvalid������ ����, �ùٸ� ���� �Է��ߴ��� �Լ� ����   

		if(valid==1)	//��ġ�� ������  
			break;		//�ݺ��� Ż��  
		else			//��ġ��  
			printf("�߸��� �Է�, �� �Է� : ");
	}
}

int Compare(int *arr1, int *arr2)	//�� �Լ� 
{
	static int count=0;	//�Ŀ� �� ���� �õ����� ����°�  
	int strike=0, ball=0;
	int i, j;

	for(i=0; i<4; i++)	//4�� �ݺ�  
	{
		for(j=0; j<4; j++)	//4�� �ݺ�  
		{
			if(arr1[i]==arr2[j])	//���� �� ���� ���� ���� ��  
			{
				i==j? strike++:ball++;	//i�� j�� ���� ������ strike���� �ƴϸ� ball����  
				break;
			}
		}
	}
	count++;		//�Լ� �����Ҷ� ���� ����(0�� ��ȯ�ȴٸ� �Լ��������� static������� 0���� ������ ����) 
	printf("%d��° ���� ��� : %dstrike, %dball!!\n", count, strike, ball);

	if(strike==4)	//3�� �� �������� ���߾��� ���  
		return 1;	//1�� ��ȯ  
	else
		return 0;	//0�� ��ȯ  
}
