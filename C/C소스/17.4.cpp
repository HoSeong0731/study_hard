#include <stdio.h>	//ǥ������� ������� ����
int main ()	//main�Լ�
{
	int num1 = 10, num2 =20, num3 = 30;	//���� ����  
	int *ptr1 = &num1;	//�����Ϳ��� 
	int *ptr2 = &num2;	//�����Ϳ��� 
	int *ptr3 = &num3;	//�����Ϳ��� 
	
	int *ptrArr[]={ptr1, ptr2, ptr3};	//�����͹迭���ڰ����� �����͸� ����  
	int **dptr = ptrArr;		//���������͸� �����͹迭�� ����  
	
	printf(" %d %d %d \n",*(ptrArr[0]), *(ptrArr[1]), *(ptrArr[2]));	//�����͹迭���  
	printf(" %d %d %d \n",*(dptr[0]), *(dptr[1]), *(dptr[2])); 	//���������� ���  
	return 0; //�����Լ� ���� 
}

