/*
using을 이용한 이름공간의 명시
using을 쓰면 선언된 지역으로 한정시키고 그 안에서 컨텐츠를 찾아라!의 문법
=> 이름공간을 일일이 길게 쓰지 않아도 괜찮음 
*/
 
 #include <iostream>
 
 namespace Hybrid
 {
 	void HybFunc()
 	{
 		std::cout<<"So simmple function!"<<std::endl;
 		std::cout<<"In namespace Hybrid!"<<std::endl;
	 }
  } 
  
  int main()
  {
  	using Hybrid::HybFunc;
  	HybFunc();
  	return 0;
  }
