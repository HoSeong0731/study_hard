#include <iostream>

int main(){
	int num=0;
	int input;
	
	for(int i=0; i<5; i++){
		std::cout<<i+1<<"번째 정수 입력";
		std::cin>>input;
		num = num + input; 
	}
	std::cout<<"입력된 값의 합은 "<<num<<"입니다."<<std::endl;
	return 0; 
} 
