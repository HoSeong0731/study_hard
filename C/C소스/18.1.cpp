#include <stdio.h>		//����� ������� ���� 
int main()				//main�Լ� ���� 
{
	int arr2d[3][3];	//int�� 2���� �迭 ���� 
	printf("%d \n", arr2d);				//arr2d(0,0) �ּ� �� ��� (���� x,y) 
	printf("%d \n", arr2d[0]);			//arr2d(0,0) �ּ� �� ��� 	
	printf("%d \n\n", &arr2d[0][0]);	//arr2d(0,0) �ּҰ� ��� 


	printf("%d \n", arr2d[1]);			//arr2d(0,1) �ּҰ� ���  
	printf("%d \n\n", &arr2d[1][0]);	//arr2d(0,1) �ּҰ� ���  

	printf("%d \n", arr2d[2]);			//arr2d(0,2) �ּҰ� ���  
	printf("%d \n\n", &arr2d[2][0]);	//arr2d(0,2) �ּҰ� ���  

	printf("sizeof(arr2d): %d \n", sizeof(arr2d));	//size = 4*3*3
	printf("sizeof(arr2d[0]): %d \n", sizeof(arr2d[0]));	//size = 4*3
	printf("sizeof(arr2d[1]): %d \n", sizeof(arr2d[1]));	//size = 4*3
	printf("sizeof(arr2d[2]): %d \n", sizeof(arr2d[2]));	//size = 4*3
	return 0;	//main�Լ� ����  
}

