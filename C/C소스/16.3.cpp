#include <stdio.h>	//ǥ������� ������� ���� 
int main()	//main�Լ�
{
	int arr[3][2];	//int�� arr�迭 ����
	int i, j;		//int�� i, j�迭 ����  
	for(i=0; i<3; i++)	//�ݺ��� ��ø(����) 
		for(j=0; j<2; j++)	//�ݺ��� ��ø(����) 
			printf("%p \n", &arr[i][j]);	//��� 
	return 0;	//�����Լ�����  
}
