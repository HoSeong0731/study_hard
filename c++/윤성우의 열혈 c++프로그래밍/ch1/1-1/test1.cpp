#include <iostream>

int main(){
	int num=0;
	int input;
	
	for(int i=0; i<5; i++){
		std::cout<<i+1<<"��° ���� �Է�";
		std::cin>>input;
		num = num + input; 
	}
	std::cout<<"�Էµ� ���� ���� "<<num<<"�Դϴ�."<<std::endl;
	return 0; 
} 
