#include<stdio.h>	//ǥ��������������
#include<string.h>	//C ���� ���ڿ� (�� ���� ���ڿ�) �� �ٷ� �� �ִ� �Լ����� ����

int main()	//main�Լ� 
{
	char str1[20]="First~";			//ũ�Ⱑ 20�� 1���� �迭 ���  
	char str2[20]="Second";			//ũ�Ⱑ 20�� 1���� �迭 ���  
	char str3[20]="Simple num: ";	//ũ�Ⱑ 20�� 1���� �迭 ���   
	char str4[20]="1234567890";		//ũ�Ⱑ 20�� 1���� �迭 ���  
	
	/****case 1****/
	strcat(str1, str2);	//str1�� str2�� ����  
	puts(str1);	//str1���  
	
	/****case 2****/
	strncat(str3, str4, 7);	//str3�� str4�� 7��°������ ����(�ΰ����Խ� 8) 
	puts(str3);	//str3 ���  
	return 0;	//main�Լ�����  
}
	

