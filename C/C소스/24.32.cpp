#include <stdio.h>	//ǥ�ض��̺귯��
int main()			//�����Լ�
{
	char str[30];	//�迭 ����
	int ch;			//���� ����
	FILE * fp = fopen("data2.txt", "rt");	//�б� ��Ʈ��
	if (fp == NULL)	//fp�� NULL�� ��� ����
	{	
		puts("���Ͽ��� ����!");
		return -1;	//���������� ���Ḧ ���� -1�� ��ȯ
	}

	ch = fgetc(fp);		//fp�� ���� �ϳ��� ���ڸ� �о ���� ch�� ����
	printf("%c \n", ch);//�޾ƿ� ������ ���
	ch = fgetc(fp);		//fp�� ���� �ϳ��� ���ڸ� �о ���� ch�� ����
	printf("%c \n", ch);//�޾ƿ� ������ ���
	fgets(str, sizeof(str), fp);//fp�� ���� ���ڿ��� �޾ƿ� str�� \n�� ���ö����� ����
	printf("%s", str);			//�޾ƿ� �迭�� ���
	fgets(str, sizeof(str), fp);//fp�� ���� ���ڿ��� �޾ƿ� str�� \n�� ���ö����� ����
	printf("%s", str);			//�޾ƿ� �迭�� ���
	fgets(str, sizeof(str), fp);//fp�� ���� ���ڿ��� �޾ƿ� str�� \n�� ���ö����� ����
	printf("%s", str);			//�޾ƿ� �迭�� ���
	fgets(str, sizeof(str), fp);//fp�� ���� ���ڿ��� �޾ƿ� str�� \n�� ���ö����� ����
	printf("%s", str);			//�޾ƿ� �迭�� ���
	fgets(str, sizeof(str), fp);//fp�� ���� ���ڿ��� �޾ƿ� str�� \n�� ���ö����� ����
	printf("%s", str);			//�޾ƿ� �迭�� ���

	fclose(fp);	//��Ʈ���� ����
	return 0;	//0�� ��ȯ �� ����
}

