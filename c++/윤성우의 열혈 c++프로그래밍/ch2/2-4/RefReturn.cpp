/*
�����ʹ� �߸� ����� Ȯ���� ����, �������� Ȱ���� ��������� �������� Ȱ�뺸�� ���� ������,
������ ����� �Լ����ǰ� �� ���� �����̶�� ������ �� ������, �Լ��� ȣ�⹮�常 ���� �Լ��� Ư���� �Ǵ��� �� �ִ� �ɷ��� �������.
=> HappFunc(num);���� �Լ��� ȣ������ �� �� �Լ��� ���������� �������� �� �� ����.
*/

#include <iostream> 
using namespace std;

int& RefRetFuncOne(int &ref)
{
	ref++;
	return ref;;
}

int main()
{
	int num1=1;
	int &num2=RefRetFuncOne(num1);
	
	num1++;
	num2++;
	cout<<"num1: "<<num1<<endl;
	cout<<"num2: "<<num2<<endl;
	return 0;
}
