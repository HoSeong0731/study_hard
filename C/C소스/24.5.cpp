#include <stdio.h>	//ǥ�ض��̺귯��
int main()			//�����Լ�
{
	FILE * src = fopen("data24.4.txt", "rt");	//�б� ��Ʈ����
	FILE * des = fopen("data24.44.txt", "wt");	//���� ��Ʈ����
	char str[20];								//���ڿ��� �����ϱ� ���� �迭

	if (src == NULL || des == NULL) {	//�ΰ��� �ϳ��� �������� ���� �� �������� ����
		puts("���� ���� ����!");
		return -1;						//���������� ���Ḧ ���� -1 ���� ��ȯ
	}
	while (fgets(str, sizeof(str), src) != NULL)//������ ���� Ȯ���ϱ� ���� �Է��Լ��� ������ �߻��Ͽ��� OEF�� ��ȯ
		fputs(str, des);						//str�� �ִ� ���� �����ص״� �� des�� ����
	if (feof(src) != 0)							//EOF��ȯ������ �����ϱ� ����
		puts("���Ϻ��� �Ϸ�!");
	else
		puts("���Ϻ��� ����!");
	fclose(src);	//��Ʈ���� ����
	fclose(des);	//��Ʈ���� ����
	
	FILE * fp = fopen("data.txt", "rt");		//�б⽺Ʈ��  
	FILE * des2 = fopen("data24.44.txt", "wt");	//���� ��Ʈ��  
	char tstr[20];	//�迭

	if (fp == NULL || des2 == NULL) {		//�����ϳ��� �������� ���� ��� �������� ����
		puts("���� ���� ����!");
		return -1;								//���������� ���Ḧ ���� -1 ���� ��ȯ
	}
	while (fgets(tstr, sizeof(fp), fp) != NULL)	//������ ���� Ȯ���ϱ� ���� �Է��Լ��� ������ �߻��Ͽ��� OEF�� ��ȯ
		fputs(tstr, des2);						//strs�� �ִ� ���� �����ص״� ���� dst�� ����
	if (feof(fp) != 0)							//EOF��ȯ������ �����ϱ� ����
		puts("���Ϻ��� �Ϸ�!");
	else
		puts("���Ϻ��� ����!");
	fclose(fp);		//��Ʈ���� ����
	fclose(des2);	//��Ʈ���� ����
	return 0;		//0�� ��ȯ �� ����
}
