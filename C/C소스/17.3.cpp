#include <stdio.h>	//ǥ������� ������� ����
void SwapIntPtr(int **dp1, int **dp2) //swap�Լ� (���������ͷ� ���� ����) 
{
	int * temp= *dp1;	
	*dp1=*dp2;	
	*dp2=temp;//p2�� p1�� ����Ű�� ������ �ٲ�(���� ���� �ٲ�)  
}

int main()	//main�Լ�
{
	int num1=10, num2=20;	//��������  
	int *ptr1, *ptr2;	//�����ͺ��� ����  
	ptr1=&num1, ptr2=&num2;	//������ ����  
	printf("*ptr1, *ptr2: %d %d \n", *ptr1, *ptr2);	//�Լ� ������  
	
	SwapIntPtr(&ptr1, &ptr2); //swap�Լ� ����(���ڰ��� ���޵Ǹ鼭 ptr�� �ּҿ� �����) 
	printf("*ptr1, *ptr2: %d %d \n", *ptr1, *ptr2); //�Լ� ������  
	return 0;	//�����Լ� ����  
}
