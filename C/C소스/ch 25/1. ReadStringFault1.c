#include <stdio.h>	//ǥ�� ����� �������  

char * ReadUserName(void)	//���ڿ� �Է¹޴� �Լ�  
{
	char name[30];
	printf("What's your name? ");
	gets(name);
	return name;	//���� �� ��ȯ  
}

int main(void)	//main�Լ�  
{
	char * name1;
	char * name2;
	name1=ReadUserName();
	printf("name1: %s \n", name1);
	name2=ReadUserName();	
	printf("name2: %s \n", name2);
	return 0;	//�����Լ� ����  
}
