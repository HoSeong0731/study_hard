/*
함수 오버로딩: 서로 다른 함수의 이름이 같을 수 있다.(매개변수의선언형태를 다르게 해서)
ex) MyFunc(20); != MyFunc(30, 40)
ex2) 매개 변수가 둘 다 하나더라도 int형과 char형의 차이
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
