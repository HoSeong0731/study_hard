/*
참조자의 이해
변수 = 할당된 메모리 공간에 붙여진 이름이다.(그 이름을 둘 이상으로 부여할 수 있게 하는 게 참조자이다.)
*/

#include <iostream>
using namespace std;

int main()
{
	int num1=1020;
	int &num2=num1;
	
	cout<<"VAL: "<<num1<<endl;
	cout<<"REF: "<<num2<<endl;
	
	cout<<"VAL: "<<&num1<<endl;
	cout<<"REF: "<<&num2<<endl;
	return 0;
 } 
