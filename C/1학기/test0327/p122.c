#include <stdio.h>
int main()
{
	printf("literal int size: %d \n", sizeof(7));			
	// int�� ������ũ�⸦ ���� ���̴�. int�� �����ȿ� �ִ� � ���ڸ� �Է��ϵ� 4�� ��µȴ�.
	printf("literal double size: %d \n", sizeof(7.14));
	// double�� ������ũ�⸦ ���� ���̴�. double�� �����ȿ� �ִ� � ���ڸ� �Է��ϵ� 8�� ��µȴ�.
	printf("literal char size: %d \n", sizeof('A'));
	// char�� ������ũ�⸦ ���� ���̴�. char�� �����ȿ� �ִ� � ���ڸ� �Է��ϵ� 4�� ��µȴ�.
	printf("literal float size %d ", sizeof(float));
	// float�� ������ũ�⸦ ���� ���̴�. floatdl��� �ڷ����� �Է��ص� ����Ʈ ���� ǥ���ȴٴ� ���� �����ֱ� ���� float�� ����ߴ�.
	return 0;

}