/*
구조체 안에서 enum상수의 선언  
*/
#include <iostream>
using namespace std;



struct Car
{
	enum{
		ID_LEN 		=20,
		MAX_SPD		=200,
		FUEL_STEP	=2,
		ACC_STEP	=10,
		BRK_STEP	=10
	}; 
	char gamerID[ID_LEN];	//소유자 ID
	int fuelGauge;			//연료량
	int curSpeed;			//현재속도
	 


	void ShowCarState(){
		cout<<"소유자ID: "<<gamerID<<endl;
		cout<<"연료량: "<<fuelGauge<<"%"<<endl;
		cout<<"현재속도: "<<curSpeed<<"km/s"<<endl<<endl; 
	}	
	
	void Accel(){
		if(fuelGauge<=0){
			return;
		}else{
			fuelGauge-=FUEL_STEP;
		}
		
		if(curSpeed+ACC_STEP>=MAX_SPD){
			curSpeed=MAX_SPD;
			return;
		}
		curSpeed+=ACC_STEP;
	}
	
	void Break(){
		if(curSpeed<BRK_STEP){
			curSpeed = 0;
			return ;
		}
		curSpeed -= BRK_STEP;
	}
};

int main()
{
	Car run99={"run99", 100, 0};
	run99.Accel();
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();
	
	Car sped77={"sped77", 100, 0};
	sped77.Accel();
	sped77.Break();
	sped77.ShowCarState();
	return 0;
}
