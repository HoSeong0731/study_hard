#include <stdio.h> 	//����� ������� ����

int main(int argc, char *argv[])	//���� �� argc������, argv������  
{
	int i=0;
	printf("���޵� ���ڿ��� ��: %d \n", argc);	//argc�� ���ڿ� �� ���  
	
	while(argv[i]!=NULL)	//null���� ���� ������ �ݺ�  
	{
		printf("%d��° ���ڿ�: %s \n", i+1, argv[i]);	//�ܾ� ������ ���  
		i++; //�ݺ��� �����Ű�� ����  
	}
	return 0;	//main�Լ�����  
 } 
