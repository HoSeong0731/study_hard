#include <stdio.h>
int main()
{
	char ch = 9;
	int inum = 1052;
	double dnum = 3.1415;		//������ ũ�⸦ ���� �����Ƿ� double���� ������ ���� ���´�.
	char num1 = 1, num2 = 2, result1 = 0;		//��Ȯ�� �����ϸ� result1�� char��, result2�� short������ ���� ǥ�������� �ٸ���.
	short num3 = 300, num4 = 400, result2 = 0;

	printf("���� ch�� ũ��: %d \n", sizeof(ch));		//�ۼ��ڰ� ������ ������ �ڷ����� ����� ����Ѵ�.
	printf("���� inum�� ũ��: %d \n", sizeof(inum));
	printf("���� dnum�� ũ��: %d \n\n", sizeof(dnum));

	printf("char�� ũ��: %d \n", sizeof(char));			//c���� ������ �ڷ������̴�.
	printf("int�� ũ��: %d \n", sizeof(int));
	printf("long�� ũ��: %d \n", sizeof(long));
	printf("char�� ũ��: %d \n", sizeof(long long));
	printf("char�� ũ��: %d \n", sizeof(float));
	printf("char�� ũ��: %d \n\n", sizeof(double));


	printf("size of num1 & num2: %d, %d \n", sizeof(num1), sizeof(num2));
	printf("size of num3 & num4: %d, %d \n", sizeof(num3), sizeof(num4));
	printf("size of char add: %d \n", sizeof(num1 + num2));			//num1�� num2�� ����Ʈũ�� ����
	printf("size of char add: %d \n", sizeof(num3 + num4));			//num3�� num4�� ����Ʈũ�� ����

	result1 = num1 + num2;		//������ ������ִ� ���� ���� num1 + num2�̹Ƿ� �������� 3�̴�.
	result2 = num3 + num4;
	printf("size of result1 & result2: %d, %d", sizeof(result1), sizeof(result2));
	return 0;
}