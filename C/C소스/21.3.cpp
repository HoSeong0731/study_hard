#include<stdio.h>	//ǥ�������������� 
int main()	//main�Լ� 
{
	char * str="Simple String";	//str�����ͺ����� ���ڿ� ����  
	
	printf("1. puts test ------ \n");	
	puts(str);	//���ڿ� ��� �Լ�(���� ����ͷθ� ����Ѵ�.) 
	puts("so simple string");
	
	printf("2. fputs test ----- \n");
	fputs(str, stdout); printf("\n");	//���ڿ� ��� �Լ�(stdout�� ���� ����ͷ� ��µȴ�.(���� ����)) 
	fputs("So Simple String", stdout); printf("\n");
	
	printf("3. end of main ----\n");
	return 0;	//main�Լ� ����  
 } 
