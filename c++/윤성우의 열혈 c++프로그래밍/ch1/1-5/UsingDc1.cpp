/*
using�� �̿��� �̸������� ���
using�� ���� ����� �������� ������Ű�� �� �ȿ��� �������� ã�ƶ�!�� ����
=> �̸������� ������ ��� ���� �ʾƵ� ������ 
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
