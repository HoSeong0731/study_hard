#include <stdio.h>

void bubble(int *);

void print(int *);



void main() {


	int* a[9];
	int* p = a;
	for (int i = 0; i < 9; i++)		//�Է� �ޱ�
	{
		printf("0~9������ ���� �ѹ��� �Է� %d��°", i + 1);
		scanf("%d", p++);		//���� ������ ������ 1~9���� �Է¹ް� ��.
	}
	bubble(a);
	return 0;
}

void bubble(int *a) {

	int temp;
	printf("���� �� �迭 a");
	print(a);			//�ʱ⿡ ���� �� ���

	for (int i = 0; i < 8; i++) {			//8�� �� �� �ٽ� (1,2)�� �񱳷� ���ƿ�

		for (int j = 0; j < 8; j++) {		//1.(1,2)�� ��, 2. (2,3)�� ��....

			if (*(a + j) > *(a + j + 1)) {

				temp = *(a + j + 1);			//(a+j+1)��° ���� temp�� ����

				*(a + j + 1) = *(a + j);		//(a+j+1)��° ���� (a=j)���� ���� �ؼ� (a+j)������ (a+j+1)�� ����

				*(a + j) = temp;				//(a=j)���� temp�� ���� �ؼ� (a+j+1)��° ������ (a+j)�� ����

			}
			

		}
		

	}
		printf("���� �� �迭 a");
		print(a);		//���氪���
		printf("\n");

}

void print(int *a) {

	for (int i = 0; i < 9; i++)

		printf("%3d", *(a + i));		//3ĭȮ���� a+i�� ���

	printf("\n");		//9�� ����� �ٹٲ�

}

