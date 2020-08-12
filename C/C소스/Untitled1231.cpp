#include <stdio.h>

int main(void)
{
	int i,j;
	
	int arr1[3][3]={
	{13,4,30},
	{34,2,5},
	{7,15,27}
	};
	int arr2[3][3]={0};
	
	printf("a배열 리스트\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%3d ", arr1[i][j]);
		}
		printf("\n");
	}
	printf("전치행렬 b 리스트\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			arr2[i][j]=arr1[j][i];
			printf("%3d ",arr2[i][j]);
		}
		printf("\n");
	}
	return 0;
}

