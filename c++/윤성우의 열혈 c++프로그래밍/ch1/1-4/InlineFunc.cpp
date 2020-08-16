/*
인라인 함수
매크로 함수의 장점: 일반적인 함수에 비해서 실행속도의 이점이 있다.
매크로 함수의 단점: 정의하기가 어렵다. 복잡한 함수를 매크로의 형태로 정의하는데 한계가 있다.
 
inline함수 => 프로그램 코드라인 안으로 들어가 버린 함수 

매크로 함수에는 있지만, 인라인 함수에는 없는 장점
매크로 함수의 경우 자료형에 의존적이지 않지만, 인라인 함수는 자료형에 의존적이다. 
*/

#include <iostream>

inline int SQUARE(int x)
{
	return x*x;
}

int main()
{
	std::cout<<SQUARE(5)<<std::endl;
	std::cout<<SQUARE(12)<<std::endl;
	return 0;
}
