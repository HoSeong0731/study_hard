#include<stdio.h>	//ǥ��������������
#include<stdlib.h>	//ǥ�ض��̺귯���������  

int main()	//main�Լ� 
{
	char str[20];	//ũ�Ⱑ 20�� 1���� �迭�� ����  
	
	printf("���� �Է�: ");
	scanf("%s", str);		//�Է¹���  
	printf("%d \n", atoi(str));	//int������ ��ȯ  
	
	printf("�Ǽ� �Է�: ");
	scanf("%s", str);	//�Է¹��� 
	printf("%g \n", atof(str));	//double������ ��ȯ  
	
	return 0;	//�����Լ�����  
}
