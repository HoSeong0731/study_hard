#include <iostream>
#include <iomanip>

using namespace std;
class ThreeSixNine {
private:
public:
	int start(int max) {
		int digit[3];
		for (int i = 1; i <= max; i++) {
			
			digit[0] = i/100;		//Divide numbers by digits
			digit[1] = (i/10)%10;
			digit[2] = i % 10;
			if (digit[0] == 3 or digit[0] == 6 or digit[0] == 9) {		//3, 6, 9 in place of 100
				cout.setf(ios::right);
				cout << setw(5) << "!";
				if (digit[1] == 3 or digit[1] == 6 or digit[1] == 9) {
					cout << "!";
					if (digit[2] == 3 or digit[2] == 6 or digit[2] == 9) {
						cout << "!";
					}
				}
				
			}else if (digit[1] == 3 or digit[1] == 6 or digit[1] == 9) {	//3, 6, 9 in place of 10
				cout.setf(ios::right);
				cout << setw(5) << "!";
				if (digit[2] == 3 or digit[2] == 6 or digit[2] == 9) {
					cout << "!";
				}
				
			}else if (digit[2] == 3 or digit[2] == 6 or digit[2] == 9) {	////3, 6, 9 in place of 1
				cout.setf(ios::right);
				cout << setw(6) << "!";
				
			}
			else {			//If not applicable
				cout.setf(ios::right);
				cout << setw(5) << i;
			}
			

			if (i % 10 == 0) {
				cout << endl;
			}
		}
		return 0;
	}

};
int main() {
	int max = 0;
	ThreeSixNine game;
	
	cout << "input 369 number" << endl;
	cin >> max;					//Numeric Input Received
	if (max > 300 or max < 1) {	//exception processing
		cout << "error!";
		return 0;
	}
	
	game.start(max);
}