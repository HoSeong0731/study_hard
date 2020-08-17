/*
클래스와 구조체의 유일한 차이점
일단 선언방법이 다르다, 또 클래스 내에 선언된 변수는 클래스 내에 선언된 함수에서만 접근 가능하다.
public: 어디서든 접근 허용 
protected: 상속관계에 놓여있을 때, 유도 클래스에서의 접근 허용
private: 클래스 내(클래스 내에 정의된 함수)에서만 접근허용 

-접근제어 지시자 A가 선언되면, 그 이후에 등장하는 변수나 함수는 A에 해당하는 범위 내에서 접근이 가능하다.
-그러나 새로운 접근제어 지시자 B가 선언되면, 그 이후로 등장하는 변수나 함수는 B에 해당하는 범위 내에서 접근이 가능하다.
-키워드 struct를 이용해서 정의한 구조체(클래스)에 선언된 변수와 함수에 별도의 접근제어 지시자를 선언하지 않으면, 모든 변수와 함수는 public으로 선언된다.
-키워드 class를 이용해서 정의한 클래스에 선언된 변수와 함께 함수에 별도의 접근제어 지시자를 선언하지 않으며느 모든 변수와 함수는 private으로 선언된다. 
지시자 옆에는 콜론이 붙는다! 
*/ 

#include <iostream>
#include <cstring>
using namespace std;

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

void Car::InitMembers(char * ID, int fuel)
{
	strcpy(gamerID, ID);
	fuelGauge=fuel;
	curSpeed=0;
 } 
 
void Car::ShowCarState()
{
	cout<<"소유자ID: "<<gamerID<<endl;
	cout<<"연료량: "<<fuelGauge<<"%"<<endl;
	cout<<"현재속도: "<<curSpeed<<"km/s"<<endl<<endl;
}

void Car::Accel()
{
	if(fuelGauge<=0)
	{
		return;
	}
	else
	{
		fuelGauge -= CAR_CONST::FUEL_STEP;
	}
	
	if(curSpeed+CAR_CONST::ACC_STEP>=CAR_CONST::MAX_SPD){
		curSpeed=CAR_CONST::MAX_SPD;
		return;
	}
	curSpeed+=CAR_CONST::ACC_STEP;
}

void Car::Break(){
	if(curSpeed<CAR_CONST::BRK_STEP){
		curSpeed = 0;
		return ;
	}
	curSpeed -= CAR_CONST::BRK_STEP;
}

int main()
{
	Car run99;
	run99.InitMembers("run99", 100);
	run99.Accel();
	run99.Accel();
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();
	
	Car sped77;
	sped77.InitMembers("sped77", 100);
	sped77.Accel();
	sped77.Break();
	sped77.ShowCarState();
	return 0;
}
