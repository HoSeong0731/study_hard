#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	int input;		//Variables that receive the value you enter
	int p = 2; 		//Variables used in decimal finder (starting at 2)
	int count = 0; 	//Variables used to determine the number of decimal places  
	int i = 0;
	while (1) {
		cout << "enter the n: ";	//Get value from user 
		cin >> input;
		if (input <= 1) {
			cout << "잘못된 값을 입력했습니다.";
			cout << endl;
		}
		else {
			break;
		}

	}

	int *arr = (int*)malloc((input + 1000) * 4);	//create one-dimensional arrangement of an input size. 
	for (int i = 0; i < input - 1; i++) {			//Enter numbers from 2 to n. 
		arr[i] = i + 2;
	}
	while (p * p <= input) {						//Repeat only if sqrt(input) is less than  

		for (i = 0; i < input - 1; i++) {			//Enter numbers from 2 to n. 
			if (arr[i + p] % p == 0) {				//If have a number smaller than p, that's a small number. Calculate from i+p.  
				arr[i + p] = 0;						//When divided, the rest is zero. = Small factor
			}
		}
		p++;	//Whirle Moon Escape Condition
	}
	for (i = 0; i < input - 1; i++) {	//Remaining Decimal Output Repetition
		if (arr[i] != 0) {
			cout << arr[i];
			cout << " ";
			count++;
		}

	}
	cout << endl;
	cout << "The number of Prime numbers: " << count;	//Counted decimal numbers 
	Sleep(1000);
	return 0;
}
