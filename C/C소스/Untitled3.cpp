#include <stdio.h>
int main()
{
	int cur = 2;			//2�ܺ��ͽ���
	int is = 1;				//is ���� ����

	while (is < 10)
	{
		cur = 1;		//��ø�ݺ��������� ���� 1�� ��� �ʱ�ȭ
		while (cur < 9)
		{
			cur++;		//���������� �������� ���� �� ����
			printf("%d X %d = %-3d ", cur, is, cur*is);					//%-3d�� ����Ȯ��
		}
		printf("\n");	//�� ���� �����ϰ� �ٹٲ�
		is++;	//�� �ѱ�
	}
	return 0;
}
