#include <stdio.h>
int main()
{
	int arr[3] = { 0,1,2 };
	printf("�迭�� �̸�: %p \n", arr);
	printf("ù ��° ���: %p \n", &arr[0]);
	printf("ù ��° ���: %d \n", &arr[0]);	//10������ �ּ� �� ���
	printf("ù ��° ���: %x \n", &arr[0]);	//16������ �ּ� �� ���(����Ʈ ���� �����Ƿ� 8�ڸ� ä������ ����.
	printf("�� ��° ���: %p \n", &arr[1]);
	printf("�� ��° ���: %p \n", &arr[0]);	
	printf("ù ��° ���: %p \n", *arr);

	return 0;
}