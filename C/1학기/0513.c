#include <stdio.h>
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����

int main()
{
	int size = 0;
	int max = 0, min = 0, sum = 0, i = 0;		//�����Ⱚ ���� �� �����ϱ� ���� 0���� �ʱ�ȭ 
	int num = 0;
	printf("�迭�� ũ�⸦ �Է��ϼ���:");
	scanf("%d", &size);							//size = �Է¹��� ����ŭ 

	int *numPtr = malloc(sizeof(int) * size);    // {int ũ��(4byte) * �Է¹��� ũ��}��ŭ ���� �޸� �Ҵ�

	for (i = 0; i < size; i++)    // �Է¹��� ũ�⸸ŭ �ݺ�
	{
		printf("%d��° ������ �� �Է�", i);//numPtr[0]���� ������� �Է� 
		scanf("%d", &num);				// �迭 1��°���� ������� �� ����. 
		numPtr[i] = num;                // �ݺ����� ���� [i]�� ���� num�� ����. 
	}

	max = min = sum = numPtr[0];	//max, min, sum �� 1��° ������ ���� �� ���ϸ鼭 ���� ��. 
	for(i = 1; i < num; i++)		//2��° �迭���� �ݺ��� ���� 
	{		
		sum += numPtr[i];			//sum ���� 
		if(max<numPtr[i])			//max ���� 
		 max=numPtr[i];				//���� ��ġ�� max�� ���� 
		if(min>numPtr[i])			//min ���� 
		 min=numPtr[i];				//���� ��ġ�� min�� ���� 
	}
	printf("max: %d \n", max);	//max��� 
	printf("min: %d \n", min);	//min��� 
	printf("sum: %d \n", sum);	//sum��� 
	return 0;
}
