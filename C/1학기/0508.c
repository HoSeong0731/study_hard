#include <stdio.h>
int sumFunc(int count)	// num���� 1���� ���ϴ� �Լ� ����
{
	if (count == 0)		//count�� 0�϶� sumFunc�Լ� ���� 
		return 0;
	else
		return count + sumFunc(count - 1);	//�� ������ �ݺ�
}
int main()
{
	int num;
	printf("�հ踦 ���ϴ� ������ �Է��ϼ���:");
	scanf("%d", &num);
	printf("1���� %d������ ��: %d", num, sumFunc(num));	//�Լ� �����ؼ� �հ�� 
	return 0;
}
/*
�ɸ��ð� 5�� 
*/