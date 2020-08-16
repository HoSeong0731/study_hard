/*
매개변수에 설정하는 '디폴트 값'의 의미
=>함수호출 시 인자를 전달하지 않으면 7이 전달된 것으로 간주하겠다.
*/

#include <iostream>

int Adder(int num1=1, int num2=2)
{
	return num1+num2;	
}

int main()
{
	std::cout<<Adder()<<std::endl;
	std::cout<<Adder(5)<<std::endl;
	std::cout<<Adder(5, 3)<<std::endl;
	return 0;
}
