#include <stdio.h>

int n=1;
int number=0;

int sumFunc(int count)
{
	if(count == 0)
	return 0;
	else
	number+=1;
	return count+sumFunc(count-1);
	
}

int main(void)
{
	while(n != 0)
	{
		printf("�հ踦 ���ϴ� �������Է��ϼ���(����� 0�Է�): ");
		scanf("%d", &n);
		printf("1���� &d������ ��: &d\n", n, sumFunc(n));
	}
	printf("�հ� ���α׷��� �����մϴ�. sumFunc�Լ��� �� %d�� ȣ��Ǿ����ϴ�.\n", number);
	return 0;
}
