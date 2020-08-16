/*
포인터는 잘못 사용할 확률이 높고, 참조자의 활용이 상대적으로 포인터의 활용보다 쉽기 때문에,
참조자 기반의 함수정의가 더 좋은 선택이라고 생각할 수 있으나, 함수의 호출문장만 보고도 함수의 특성을 판단할 수 있는 능력이 흐려진다.
=> HappFunc(num);으로 함수를 호출했을 때 그 함수가 참조자인지 변수인지 알 수 없다.
*/

#include <iostream> 
using namespace std;

int& RefRetFuncOne(int &ref)
{
	ref++;
	return ref;;
}

int main()
{
	int num1=1;
	int &num2=RefRetFuncOne(num1);
	
	num1++;
	num2++;
	cout<<"num1: "<<num1<<endl;
	cout<<"num2: "<<num2<<endl;
	return 0;
}
