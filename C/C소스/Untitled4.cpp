#include<stdio.h>
int main()
{
	int cur, is;
	for (cur = 2; cur < 10; cur++)			// cur = ���� ���� ���� �� 2�ܺ��� �����ϸ� 9�ܱ����� �ϰ� ��.
	{
		for (is = 1; is < 10; is++)			// is = ���� ���� ���� �� 1���� ������ 9������ ���
		{
			printf("%d X %d = %-3d \n", cur, is, cur*is);		//%-3d�� ����Ȯ��

		}
	}
	return 0;
}
