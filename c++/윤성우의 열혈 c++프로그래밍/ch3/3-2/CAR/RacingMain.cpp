#include "Car.h"

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
