#include <stdio.h>	//ǥ�ض��̺귯��
int main()			//�����Լ�
{
	char name[20];	//���ڿ� ����
	char sex;		//���� ���� ����
	int age;		//���� ����
	FILE * fp = fopen("data24.7.txt", "wt");	//���� ��Ʈ��
	int i;			//�ݺ����� ���� ���� ����

	for (i = 0; i < 3; i++)	//���� �ޱ� ���� �ݺ���
	{
		printf("�̸� ���� ���� �� �Է�:");
		scanf("%s %c %d", name, &sex, &age);
		fflush(stdin);			//���ۿ� �����ִ� \n�� �Ҹ��� ����
		fprintf(fp, "%s %c %d \n ",name, sex, age);	//���Ͼȿ� ���
	}
	fclose(fp);	//��Ʈ���� ����
	return 0;	//0�� ��ȯ �� ����
}

