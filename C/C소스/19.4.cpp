#include <stdio.h>	//����� ������� ����

int main(int argc, char *argv[])	//exe���Ͻ�����Ѽ� ���� �Է��� ��  
{
	int i=0;
	printf("���޵� ���ڿ��� ��: %d \n", argc);	//argc�� ���ڿ� �� ���  
	
	for(i=0; i<argc; i++)
		printf("%d��° ���ڿ�: %s \n", i+1, argv[i]);	//�ܾ� ������ ���  
	return 0;	//main�Լ�����  
	}


