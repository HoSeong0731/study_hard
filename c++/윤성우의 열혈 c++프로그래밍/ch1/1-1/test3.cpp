#include <iostream>

int main()
{
	int num;
	std::cout<<"구구단 정보 입력: ";
	std::cin>>num;
	
	for(int i = 1; i<10; i++){
		std::cout<<num<<"*"<<i<<"="<<num*i<<std::endl;
	}
	return 0;
}
