#include <stdio.h>	//ǥ�� ����� �������
#include <stdlib.h>	//ǥ�� �޸𸮶��̺귯��  

int main(void)
{
	int * ptr1 = (int *)malloc(sizeof(int));	//int�� *1 = 4 
	int * ptr2 = (int *)malloc(sizeof(int)*7);	//int�� *7 = 28 
	int i;
	
	*ptr1 = 20;
	for(i=0; i<7; i++)
		ptr2[i]=i+1;
	
	printf("%d \n", *ptr1);
	for(i=0; i<7; i++)
		printf("%d ", ptr2[i]);
	
	free(ptr1);	//�޸� �����Ҵ� �� ���� �Ҹ��Ŵ 
	free(ptr2);
	return 0;	//main�Լ�����  
}
