#include <stdio.h>	//ǥ�ض��̺귯�� �Լ�

int main()			//�����Լ�
{
	FILE * fp = fopen("data2.txt", "wt");	//���⽺Ʈ��
	if (fp == NULL) {						//fp�� NULL�� ��� ����
		printf("���� ���� ����!");
		return -1;							//���������� ���Ḧ �ǹ��ϱ� ���� -1�� ��ȯ
	}
	fputc('A', fp);			//���� A�� fp�� ����Ű�� ���Ͽ� ����
	fputc('B', fp);			//���� B�� fp�� ����Ű�� ���Ͽ� ����
	fputs("My name is Hong \n", fp);	//���� My name is Hong�� fp�� ����Ű�� ���Ͽ� ����
	fputs("Your name is Yoon \n", fp);	//���� Your name is Yoon�� fp�� ����Ű�� ���Ͽ� ����
	fputs("�ȳ��ϼ��� \n", fp);			//���� "�ȳ��ϼ���"�� fp�� ����Ű�� ���Ͽ� ����
	fputs("���� \n", fp);				//���� ���� fp�� ����Ű�� ���Ͽ� ����
	fputs("��ȣ���Դϴ�. \n",fp);		//���� ��ȣ���Դϴ�.�� fp�� ����Ű�� ���Ͽ� ����
	fclose(fp);		//��Ʈ���� ����
	printf("���� ���� ����!"); 
	return 0;		//0�� ��ȯ �� ����
}
