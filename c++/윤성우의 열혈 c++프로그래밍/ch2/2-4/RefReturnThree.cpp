#include <iostream>
using namespace std;

int RefRetFuncTwo(int &ref)
{
	ref++;
	return ref;
}

int main()
{
	int num1=1;
	int num2=RefRetFuncTwo(num1);
	
	num1 += 1;
	num2 += 100;
	cout<<"num1: "<<num1<<endl;
	cout<<"num2: "<<num2<<endl;
	return 0;
}

//반환형이 기본자료형으로 선언된 RefRetFuncTwo함수의 반환 값은 반드시 변수에 저장해야 한다.
//반환 값은 상수나 다름없기 때문이다. 
