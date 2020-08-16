#include <iostream>

int CalSalary(int sales)
{
	return(int)(50+sales*0.12);
}
int main()
{
	int sales;
	while(1){
		std::cout<<"판매 금액을 만원 단위로 입력(-1 to end): ";
		std::cin>>sales;
		if(sales==-1){
			break;
		}
		
		std::cout<<"이번 달 급여: ";
		std::cout<<CalSalary(sales)<<"만원"<<std::endl;
	}
	return 0;
}
