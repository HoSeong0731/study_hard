#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	int x1, x2, x3, y1, y2, y3, mid1, mid2 = 0;	
	cout << "P1: "; //input value
	cin >> x1;
	cin >> y1;
	cout << "p2: ";	//input value
	cin >> x2;
	cin >> y2;
	cout << "p3: ";	//input value
	cin >> x3;
	cin >> y3;

	mid1 = x1 * y2 - x2 * y1;	//Obtain the legal vector of P1 and P2
	mid2 = x2 * y3 - x3 * y2;	//Obtain the legal vector of P2 and P3

	if (mid1 == mid2) {			//condition of judgment
		cout << "straight";
	}
	else if (mid1 <= mid2) {
		cout << "counter-Clockwise";
	}
	else {
		cout << "clockwise";
	}
	return 0;
}
