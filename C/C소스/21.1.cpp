#include <stdio.h>	//ǥ��������������
int main()	//main�Լ� 
{
	int ch1, ch2;	//�����Է¹��� ���� ���� 
	
	ch1 = getchar();	//�����Է� 
	ch2 = fgetc(stdin); //���� Ű �Է�  
	
	putchar(ch1); //������� 
	fputc(ch2, stdout);	//���� Ű ��� 
	return 0;	//main�Լ����� 
}
