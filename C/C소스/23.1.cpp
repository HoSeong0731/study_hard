#include <stdio.h>	//ǥ�� ����� ���̺귯��
#include <windows.h>//������ �������  

typedef	int INT;		//int�� ����ü  
typedef int *PTR_INT;	//int�� ������ ����ü 
typedef unsigned int UINT;		//unsigned int�� ����ü
typedef unsigned int *PTR_UINT;	//unsigned int�� ������ ����ü 
typedef unsigned char UCHAR;		//unsigned char�� ����ü
typedef unsigned char * PTR_UCHAR;	//unsigned char�� ������ ����ü

int main()	//�����Լ�  
{
	INT num1 = 120;
	PTR_INT pnum1 = &num1;	//num1�� pnum1�� ����  
 	UINT num2 = 190;
	PTR_UINT pnum2 = &num2;	//num2�� pnum2�� ����
	UCHAR ch = 'z';
	PTR_UCHAR pch = &ch;	//ch�� pch�� ����

	printf("%d, %u, %c \n", *pnum1, *pnum2, *pch);	//���
	system("PAUSE");	//�Ͻ�����  
	return 0;	//�����Լ� ����  
}
