#include<stdio.h>	//ǥ��������������
#include<string.h>	//C ���� ���ڿ� (�� ���� ���ڿ�) �� �ٷ� �� �ִ� �Լ����� ����

void RemoveBSN(char str[])	//�ΰ����� ���� ���Ǵ� �ſ��� -1���ִ� �Լ�  
{
	int len = strlen(str);	//���ڰ��� �Է¹��� ���� ������ ũ��� len�� ����  
	str[len-1]=0;	//len - 1�� ���� �Է¹��� ���� �ΰ��� ���� �� 
}

int main()
{
	char str[100];	//ũ�Ⱑ 100�� 1���� �迭 ���� 
	printf("���ڿ� �Է�: ");
	fgets(str, sizeof(str), stdin);	//�Է¹���  
	printf("����: %d, ����: %s \n", strlen(str), str);	//������ �ΰ����� ���� ����. 
	
	RemoveBSN(str);	//�Լ�����  
	printf("����: %d, ����: %s \n", strlen(str), str);	//����� �� ��� 
	return 0;	//main�Լ����� 
}
