/*
범위지정 연산자(Scope Resolution Operator)의 또다른 기능
지역변수의 이름이 전역변수의 이름과 같을 경우, 전역변수는 지역변수에 의해 가려진다는 특징이 있다.
전역변수를 부르고 싶다면 ::변수명 으로 불러주면 된다.
*/
#include <iostream>
using namespace std;

int val=100;

int SimpleFunc()
{
	int val=20;
	cout<<"바귀기 전:"<<val<<","<<::val<<endl;
	val+=3;
 	::val+=7;
 	cout<<"바뀐 값:"<<val<<","<<::val<<endl; 
 } 
 
 int main()
 {
 	SimpleFunc();
 }
 
