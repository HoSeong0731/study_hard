#include <stdio.h>	//ǥ�� ����� �������
#include <stdlib.h>	//ǥ�� �޸𸮶��̺귯��  

char * ReadUserName()	//�Է¹޴� �Լ� 	
{
	char * name = (char *)calloc(30, sizeof(char));
	printf("What's your name? ");
	gets(name);
	return name;
}

int main(void)
{
	char * name1;
	char * name2;
	name1=ReadUserName();
	printf("name1: %s \n", name1);
	name2=ReadUserName();
	printf("name2: %s \n", name2);

	printf("again name1: %s \n", name1);
	printf("again name2: %s \n", name2);
	free(name1);	//�޸� �����Ҵ� �� ���� �Ҹ��Ŵ 
	free(name2);	//�޸� �����Ҵ� �� ���� �Ҹ��Ŵ 
	return 0;		//main�Լ� ����  
}
