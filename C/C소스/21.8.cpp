#include<stdio.h>	//ǥ��������������
#include<string.h>	//C ���� ���ڿ� (�� ���� ���ڿ�) �� �ٷ� �� �ִ� �Լ����� ����

int main()	//main�Լ� 
{
	char str1[20]="1234567890";	//���� �� �ִ� ũ�Ⱑ 20�� 1���� �迭 ���� 
	char str2[20];	//ũ�Ⱑ 20�� 1���� �迭 ���� 
	char str3[5];	//ũ��� 5�� 1���� �迭 ���� 
	
	/****case 1****/
	strcpy(str2, str1);	//str2�� str1�� �� ����  
	puts(str2);	//str2 ���  
	
	/****case 2****/
	strncpy(str3, str1, sizeof(str3));	//str3�� str1�� ����(ũ��� 5��ŭ)  
	puts(str3);	//str3 ���  
	
	/****case 3****/
	strncpy(str3, str1, sizeof(str3)-1);	//case2�� ����  
	str3[sizeof(str3-1)]=0;	//case2�� ���������� �ΰ��� ����  
	puts(str3);	//str3 ���  
	return 0;	//main�Լ� ����
}
