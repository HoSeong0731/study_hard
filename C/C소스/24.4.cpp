#include <stdio.h>	//ǥ�ض��̺귯��
int main()			//�����Լ�
{
	FILE * src = fopen("data24.4.txt", "rt");	//�б� ��Ʈ����
	FILE * des = fopen("data24.44.txt", "wt");	//���� ��Ʈ����
	FILE * abc = fopen("data.txt", "rt");		//�б� ��Ʈ����
	int ch;//���� ����
	if (src == NULL || des == NULL||abc==NULL)//3�Լ��� �ϳ��� null�̶�� �������� ����
	{
		puts("���Ͽ��� ����!");
		return -1;				//���������� ���Ḧ ���� -1 ���� ��ȯ
	}
	while ((ch = fgetc(abc)) != EOF)	//������ ���� Ȯ���ϱ� ���� �Է��Լ��� ������ �߻��Ͽ��� OEF�� ��ȯ
		fputc(ch, des);					//data�� �ִ� ���� �����ص״� ������ dst�� ����
	if (feof(abc) != 0)					//EOF��ȯ������ �����ϱ� ����
		puts("���� ���� �Ϸ�!");
	else
		puts("���� ���� ����!");
	fclose(abc);	//��Ʈ���� ����
	fclose(src);	//��Ʈ���� ����
	fclose(des);	//��Ʈ���� ����
	return 0;		//0�� ��ȯ �� ����
}

