/*
동일한 이름공간에 정의도니 함수를 호출할 때는 이름공간을 명시할 필요가 없다.
이를 확인하기 위한 예제를 만들어보자. 
*/ 
#include <iostream>

namespace BestComImpl
{
	void SimpleFunc();
 } 
 
 namespace BestComImpl
 {
 	void PrettyFunc();
 }
 
 namespace ProgComImpl
 {
 	void SimpleFunc();
 }
 
 int main()
 {
 	BestComImpl::SimpleFunc();
 	return 0;
  } 
  
  void BestComImpl::SimpleFunc()
  {
  	std::cout<<"BestCom이 정의한 함수"<<std::endl;
  	PrettyFunc(); 				//동일한 이름 공간
	ProgComImpl::SimpleFunc();	//다른 이름 공간 
  }
  
  void BestComImpl::PrettyFunc()
  {
  	std::cout<<"So Pretty!!"<<std::endl;
  }
  
  void ProgComImpl::SimpleFunc()
  {
  	std::cout<<"ProgCom이 정의한 함수"<<std::endl; 
   } 
