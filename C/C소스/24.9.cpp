#include <stdio.h>	//ǥ�ض��̺귯��
int main()			//�����Լ�
{
	/*���ϻ���*/
	FILE *fp = fopen("text.txt", "wt");	//���� ��Ʈ��
	fputs("ABCDEFGHIJKLM", fp);			//���Ͽ� A~M���� �Է��Ѵ�
	fclose(fp);		//��Ʈ���� ����
	/*���ϰ���*/
	fopen("text.txt", "rt");	//�б� ��Ʈ��
	/*SEEK_END test*/
	fseek(fp, -2, SEEK_END);	//������ �ι� ������ ����
	putchar(fgetc(fp));
	/*SEEK_SET test*/
	fseek(fp, 2, SEEK_SET);		//ó����ġ���� �ڷ� �ι� ����
	putchar(fgetc(fp));
	/*SEEK_CUR test*/
	fseek(fp, 2, SEEK_CUR);		//����ġ���� �ι� �ڷ� ����
	putchar(fgetc(fp));
	fclose(fp);					//��Ʈ���� ����
	return 0;					//0�� ��ȯ �� ����
}

