#include <stdio.h>	//ǥ�������������� ����

int main()	//main�Լ� ����  
{
	int num, n1, n2, n3, n4, n5;	//�Է¹��� num�� n1~n5 ���� 

back:
	printf("0~50000�� ���ڸ� �Է��Ͻÿ�. ");
	scanf_s("%d", &num);	//���� �Է� ����  

	if (num < 0 || num>50000) {		//����ó��  
		printf("�߸��� ���� �Է��ϼ̽��ϴ�.\n");
		goto back;
	}

	n1 = num / 10000;	//10000�� �ڸ� ���  
	n2 = (num - (n1 * 10000)) / 1000;	//1000�� �ڸ� ���  
	n3 = (num - (n1 * 10000) - (n2 * 1000)) / 100;	//100�� �ڸ� ���  
	n4 = (num - (n1 * 10000) - (n2 * 1000) - (n3 * 100)) / 10;	//10�� �ڸ� ���  
	n5 = num % 10;	//1�� �ڸ� ���  

	printf("%d	%d	%d	%d	%d \n", n1, n2, n3, n4, n5);	//���� ���  
	printf("%d	%d	%d	%d	\n", n2, n3, n4, n5);
	printf("%d	%d	%d	\n", n3, n4, n5);
	printf("%d	%d	\n", n4, n5);
	printf("%d	\n", n5);

	return 0;	//main�Լ�����  
}