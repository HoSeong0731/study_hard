#include <stdio.h>
int main()
{
	int num = 1;		//num�� 1�� ������ �ݺ����� �ٷ� ����Ǵ� �� ����.
	int result = 0;
	
	
	while (num!=0)
	{
		printf("\n������ �Է��ϼ���(0�̸� ���� �˴ϴ�.):");
		scanf("%d", &num);			//num�� 0�� ���� ������ �ݺ��� ����
		result = result + num;
		
	}
	printf("�Էµ� ������ �� ��: %d \n", result);		//�������
	return 0;
}