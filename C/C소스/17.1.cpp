#include <stdio.h>	//ǥ������� ������� ����
int main()	//main�Լ�
{
	double num = 3.14; //double�� ���� ���� 
	double *ptr = &num;	//num�� ����Ű�� ptr���� 
	double**dptr = &ptr;//ptr�� ����Ű�� dptr����(����������) 
	double *ptr2;	//�����ͺ��� ptr2���� 
	
	printf("%9p %9p \n", ptr, *dptr); //ptr�� �ּ�, dptr�� ����Ű�� ���� �ּ���� 
	printf("%9g %9g \n", num, **dptr);//num�� ���尪, dptr�� ����Ű�� �ּҰ� ����Ű�� ���� ���尪 ��� 
	ptr2 = *dptr;	//ptr2�� dptr�� ����Ŵ 
	*ptr2 = 10.99;	//ptr2�� 10.99�� �ٲ�� num�� �ٲ� 
	printf("%9g %9g \n", num, **dptr); //num���� �ٲ�� ptr���� �ٲ��, ptr���� �ٲ�� dptr���� �ٲ� 
	return 0;	//�����Լ�����
}
