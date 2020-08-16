/*
참조자와 함수
이번에는 참조자의 활용과 관련해서 이야기하고자 한다.
참조자의 활용에는 함수가 큰 위치를 차지한다.
call-by-reference => 주소 값을 전달받아서, 함수 외부에 선언된 변수에 접근하는 형태의 함수 호출
*/

#include <iostream> 
using namespace std;

void SwapByRef2(int &ref1, int &ref2)
{
	int temp=ref1;
	ref1 = ref2;
	ref2 = temp;
}

int main()
{
	int val1=10;
	int val2=20;
	cout<<"변환 전"<<endl;
	cout<<"val1: "<<val1<<endl;
	cout<<"val2: "<<val2<<endl;
	
	SwapByRef2(val1, val2);
	cout<<"변환 후"<<endl;
	cout<<"val1: "<<val1<<endl;
	cout<<"val2: "<<val2<<endl;
}
