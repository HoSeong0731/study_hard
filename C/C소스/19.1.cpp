#include<stdio.h>	//����� ������� ����

void SimpleAdder(int n1, int n2)	//���ڰ��� �޾� ������ �����ϴ� �Լ�  
{
	printf(" %d + %d = %d \n", n1, n2, n1 + n2);

}

void ShowString(char *str)	//���ڰ��� �޾� ����ϴ� �Լ�  
{
	printf("%s \n", str);
}

int main()	//main�Լ�  
{
	char *str = "Function Pointer";	//������ �����ͺ��� ���� 
	int num1 = 10, num2 = 20;	//���� ����  

	void(*fptr1)(int, int) = SimpleAdder;	//SimpleAdder�� ������ ���� �����ͺ��� ����  
	void(*fptr2)(char *) = ShowString;		//ShowString�� ������ ���� �����ͺ��� ����  

	
	fptr1(num1, num2);	//�Լ� ������ ������ ���� ȣ��
	fptr2(str);	//�Լ� ������ ������ ���� ȣ��
	return 0;	//main�Լ� ����  

}

