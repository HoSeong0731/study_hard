//부분적 디폴트 값 설정 

#include <iostream>
int Adder(int num1, int num2=1, int num3=1);

int main()
{
	std::cout<<"[3, 3, 3]"<<Adder(3, 3, 3)<<std::endl;
	std::cout<<"[5, 5, D]"<<Adder(5, 5)<<std::endl;
	std::cout<<"[7, D, D]"<<Adder(7)<<std::endl;
	return 0;
}

int Adder(int num1, int num2, int num3)
{
	return num1+num2+num3;
}
