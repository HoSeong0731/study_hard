/*
�Լ� �����ε�: ���� �ٸ� �Լ��� �̸��� ���� �� �ִ�.(�Ű������Ǽ������¸� �ٸ��� �ؼ�)
ex) MyFunc(20); != MyFunc(30, 40)
ex2) �Ű� ������ �� �� �ϳ����� int���� char���� ����
*/
#include <iostream>

void MyFunc()
{
	std::cout<<"MyFunc() called"<<std::endl;
 } 
 
void MyFunc(char c)
{
	std::cout<<"MyFunc(char c) called"<<std::endl;
}

void MyFunc(int a, int b)
{
	std::cout<<"MyFunc(int a, int b) called"<<std::endl;
}

int main()
{
	MyFunc();
	MyFunc('A');
	MyFunc(12,13);
	return 0;
}
