#include <stdio.h>	//ǥ�ض��̺귯��
int main()			//�����Լ�
{
	long fpos;
	int i;
	/*���ϻ���*/
	FILE * fp = fopen("text.txt", "wt");	//���� ��Ʈ��
	fputs("0123456789-", fp);				//������ 1~9�Է�
	fclose(fp);	//��Ʈ���� ����
	/*���ϰ���*/
	fopen("text.txt", "rt");//�б� ��Ʈ��
	fseek(fp, 0, SEEK_SET);	//0
	putchar(fgetc(fp));		//fp���Ͽ� �ִ°� ���
	fseek(fp, 1, SEEK_SET);	//1
	putchar(fgetc(fp));		//fp���Ͽ� �ִ°� ���
	fseek(fp, 0, SEEK_SET);	//0
	putchar(fgetc(fp));		//fp���Ͽ� �ִ°� ���
	fseek(fp, -1, SEEK_END);//-
	putchar(fgetc(fp));		//fp���Ͽ� �ִ°� ���
	fseek(fp, 2, SEEK_SET);	//2
	putchar(fgetc(fp));		//fp���Ͽ� �ִ°� ���
	fseek(fp, 5, SEEK_SET);	//5
	putchar(fgetc(fp));		//fp���Ͽ� �ִ°� ���
	fseek(fp, 7, SEEK_SET);	//7
	putchar(fgetc(fp));		//fp���Ͽ� �ִ°� ���
	fseek(fp, 0, SEEK_SET);	//0
	putchar(fgetc(fp));		//fp���Ͽ� �ִ°� ���
	fpos = ftell(fp);		//������ġ ����
	fseek(fp, -1, SEEK_END);//-
	putchar(fgetc(fp));		//fp���Ͽ� �ִ°� ���
	fseek(fp, 8, SEEK_SET);	//8
	putchar(fgetc(fp));		//fp���Ͽ� �ִ°� ���
	fseek(fp, 4, SEEK_SET);	//4
	putchar(fgetc(fp));		//fp���Ͽ� �ִ°� ���
	fseek(fp, 7, SEEK_SET);	//7
	putchar(fgetc(fp));		//fp���Ͽ� �ִ°� ���
	fseek(fp, 8, SEEK_SET);	//8
	putchar(fgetc(fp));		//fp���Ͽ� �ִ°� ���

	fclose(fp);	//��Ʈ���� ����
	return 0;	//0�� ��ȯ �� ����
}

