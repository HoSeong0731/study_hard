#include <stdio.h>
void count(void);
int main(void)
{
	int i;
	for (i = 1; i <= 3; i++)//�ݺ������� count�Լ� 3�� ����
		count();			//count�Լ�����
	return 0;
}
void count(void)
{
	int acnt = 0;			//�Լ��� ��� �� ���� 0���� �ʱ�ȭ
	static int stcnt = 0;	//static�� ���̸� ���� ������ �ǹǷ� �Լ��� ������� ������ ����Ǿ��� ���� ������� ����
	acnt += 1;
	stcnt += 1;
	printf("auto count=%d, static count= %d\n", acnt, stcnt);	//ó�� 1 1, ���� 1 2, ���� 1 3(for������ 3�� �ݺ��ϰԲ� ������)
}
//�ɸ� �ð�: 7��