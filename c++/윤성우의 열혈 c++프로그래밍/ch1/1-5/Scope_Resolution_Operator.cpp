/*
�������� ������(Scope Resolution Operator)�� �Ǵٸ� ���
���������� �̸��� ���������� �̸��� ���� ���, ���������� ���������� ���� �������ٴ� Ư¡�� �ִ�.
���������� �θ��� �ʹٸ� ::������ ���� �ҷ��ָ� �ȴ�.
*/
#include <iostream>
using namespace std;

int val=100;

int SimpleFunc()
{
	int val=20;
	cout<<"�ٱͱ� ��:"<<val<<","<<::val<<endl;
	val+=3;
 	::val+=7;
 	cout<<"�ٲ� ��:"<<val<<","<<::val<<endl; 
 } 
 
 int main()
 {
 	SimpleFunc();
 }
 
