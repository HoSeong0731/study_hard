#include <stdio.h>	//ǥ�������������� 
int main()	//main�Լ� 
{
	int ch;		//�����Է¹��� ���� ���� 
		
	while (1)	//���ѹݺ�  
	{
		ch = getchar();	//�����Է¹���  
		if (ch == EOF)	//ctrl + zŰ �Է¹����� ���ǿ� ������. 
		{
			break;		//���� ����� �ݺ��� Ż��  
			
		}
		putchar(ch);	//�Է¹��� ���� ���
	}
	return 0;	//main�Լ�����  
}
