#include <Stdio.h>
int main()
{
	int num1 = 0xA7, num2 = 0x43, num3 = 032, num4 = 024;
	/*
	16������ �տ� 0x�� ���� 8������ 0���� ���� 10������ �ƹ��͵� ����
	%#d, %#x�� #�� ���� ���������� ǥ�����ش�.
	*/

	printf("num1(0xA7)�� 10���� ��: %d \n", num1);
	printf("num2(0x43)�� 10���� ��: %d \n", num2);
	printf("num3 (032)�� 10���� ��: %d \n", num3);
	printf("num4 (024)�� 10���� ��: %d \n \n", num4);

	printf("num1(0xA7)�� 16���� ��: %#x \n", num1);
	printf("num2(0x43)�� 16���� ��: %#x \n", num2);
	printf("num3 (032)�� 16���� ��: %#x \n", num3);
	printf("num4 (024)�� 16���� ��: %#x \n \n", num4);

	printf("num1(0xA7)�� 8���� ��: %#o \n", num1);
	printf("num2(0x43)�� 8���� ��: %#o \n", num2);
	printf("num3 (032)�� 8���� ��: %#o \n", num3);
	printf("num4 (024)�� 8���� ��: %#o \n \n", num4);

	printf(" %d - %d = %d", num1, num2, num1 - num2);
	printf(" %#x - %#x = %#x", num3, num4, num3 - num4);
	return 0;
}