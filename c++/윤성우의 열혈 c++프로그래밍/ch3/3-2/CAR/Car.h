/*
car.h->   클래스의 선언을 담는다. [메인함수가 들어가지 않는다.] 
car.cpp-> 클래스의 정의(멤버함수의 정의)를 담는다. [메인함수가 들어가지 않는다.] 
RacingMain.cpp -> 사용자가 정의한 헤더파일을 빼서 사용한다.[메인함수가 들어간다.]  
*/

#ifndef __CAR_H__
#define __CAR_H__

namespace CAR_CONST		//프로그래머가 만든 namespace(개체를 구분할 수 있는 범위) 
{
	enum{
		ID_LEN 		=20,
		MAX_SPD		=200,
		FUEL_STEP	=2,
		ACC_STEP	=10,
		BRK_STEP	=10
	}; 
}

class Car
{
private:
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;
public:
	void InitMembers(char * ID, int fuel);
	void ShowCarState();
	void Accel();
	void Break();
};
#endif
