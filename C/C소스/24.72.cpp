#include <stdio.h>	//ǥ�ض��̺귯��
int main()			//�����Լ�
{
	char name[20];	//���ڿ� ����
	char sex;		//���� ���� ����
	int age;		//���� ����
	FILE * fp = fopen("data24.7.txt", "rt");	//�б� ��Ʈ��
	int i;			//�ݺ����� ���� ���� ����

	int ret;	//���� ����
	while (1)	//���ѹݺ�
	{
		ret = fscanf(fp, "%s %c %d", name, &sex, &age);
		//fp���� name,sex,age���� �о� �´�
		if (ret == EOF)	//ret���� EOF�϶� �����Ѵ�
			break;		//�ݺ����� Ż���Ѵ�.
		printf("%s %c %d \n", name, sex, age);
	}
	fclose(fp);	//��Ʈ���� ����
	return 0;	//0�� ��ȯ �� ����
}

