/*
�������� ����
���� = �Ҵ�� �޸� ������ �ٿ��� �̸��̴�.(�� �̸��� �� �̻����� �ο��� �� �ְ� �ϴ� �� �������̴�.)
*/

#include <iostream>
using namespace std;

int main()
{
	int num1=1020;
	int &num2=num1;
	
	cout<<"VAL: "<<num1<<endl;
	cout<<"REF: "<<num2<<endl;
	
	cout<<"VAL: "<<&num1<<endl;
	cout<<"REF: "<<&num2<<endl;
	return 0;
 } 
