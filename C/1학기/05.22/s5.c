#include <stdio.h>		// �ɸ��ð� 15�� 
int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };	//arr�迭�� 1,2,3,4,5������
	int *(ptr) = &arr[4];				//ptr = arr[4]
	int num = 5;
	int sum = 0;
	while (num > 0)					//�ݺ��ؼ� ptrù��°���� 5��°���� 2�� ������Ű�� �ݺ���(ptr=arr�� ������ �ּ� �����)
	{
		sum += *(ptr--);			//1. sum += 5, 2. sum += 9.... 
		num--;						//�ݺ��� ���� ����
		 
	}
	printf("�հ�: %d", sum);	//�ùٸ��� �Ǿ��°� Ȯ���ϱ� ���� ���
	return 0;
}
