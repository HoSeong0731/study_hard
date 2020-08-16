/*
이름공간의 등장배경
같은 이름을 가지는 컨텐츠를 구분하기 위해
*/

#include <iostream>

namespace BestComImpl
{
	void SimpleFunc()
	{
		std::cout<<"BestCom이 정의한 함수"<<std::endl; 
	}
 } 
 
namespace ProgComImpl
{
	void SimpleFunc()
	{
		std::cout<<"ProgCom이 정의한 함수"<<std::endl; 
	}
}

int main()
{
	BestComImpl::SimpleFunc();
	ProgComImpl::SimpleFunc();
	return 0;
}
