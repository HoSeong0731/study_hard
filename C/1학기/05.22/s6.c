#include <stdio.h>	//���۽ð� 6�� 58��  
int main()			//�ɸ��ð� 15��  
{
	int arr[6] ={1, 2, 3, 4, 5, 6}; //arr�迭 ���� 
	int *(ptr1) = &arr[0];			//ptr1�� ���� arr[0]���� �ּҰ� = 0 
	int *(ptr2) = &arr[5];			//ptr2�� ���� arr[5]���� �ּҰ� = 6 
	int change = 0;
	int num = 0;
	
	for( num = 0; num < 6; num++ )
	{
		printf("����(%d��°)): %d\n", num+1, arr[num]);	//���� ��Ȳ ��� 
		
	}
	
	for(num = 0; num < 3; num++)	//6���� ���� �ѹ��� ���� ��Ȳ ���ݸ� 
	{
	change = *ptr1;					//change���� �̸� ptr1�� ���� 
	*ptr1 = *ptr2;					//�Ŀ� ptr1�� �ٲٱ� 
	*ptr2 = change;					//����� change�� ptr�� ���� 
	ptr1 += 1;						//ptr1 = 0 ���� 1�� ���� 
	ptr2 += -1;						//ptr2 = 6 ���� 5�� ���� 
	}
	//ptr 1�� arr[0]�� �����ϰ� �־���, �� ���� ���ٰ� �س��� ������ arr[0]�� arr[5]�� ����� 
	for(num = 0; num < 6; num++)
	{
		printf("���� ��(%d��°)): %d\n", num+1, arr[num]);//���氪 ��� 
	}
	return 0;
 } 
