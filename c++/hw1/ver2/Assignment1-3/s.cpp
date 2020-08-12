#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>

using namespace std;

//Function to get decimal value
unsigned int End(char middle[1000], int Length) {
	unsigned int decimal = 0;
	unsigned int binary = 1;

	for (int i = Length; i >= 0; i--) {
		if (middle[i] == '1')
			decimal = decimal + binary;
		binary = binary * 2;
	}
	return decimal;
}

int main() {
	int count = 0;
	int result = 0;
	int input;
	string str;

	char middle[1000];
	memset(middle, 2, sizeof(middle));
	char tmp[1000];
	memset(tmp, 2, sizeof(tmp));

	
	while (result == 0) {		//Receive the correct value, or exception if not
		count = 0;
		cout << "Input N : ";
		cin >> input;
		cout << "Input Bitstream : ";
		cin >> str;

		int Length = str.length();
		if (Length + input > 64) {
			cout << "overflow가 일어날 확률이 높습니다.";
			cout << endl;
			Sleep(1000);
		}
		for (int j = 0; j < Length; j++) {
			if (str[j] != '0' && str[j] != '1')
				count++;
		}

		if (count == 0 && input > 0)
			result = 1;
		
		else {
			if (count == 0) {
				cout << "error";
				cout << endl;
				cout << endl;
				return 0;
			}
			if (input > 0) {
				cout << "error";
				cout << endl;
				cout << endl;
				return 0;
			}
		}
	}

	int Length = str.length();

	for (int i = 0; i < Length; i++) {
		middle[i] = str[i];
	}
	count = 1;

	while (input > 0) {
		char save;
		int num = Length - 1;

		for (int i = 0; i < Length; i++)		//Above it is null
			tmp[i] = middle[i];

		
		for (int j = 0; j < Length; j++) {		//g() is reverse the bit stream
			save = tmp[j];
			tmp[j] = middle[num];
			middle[num] = save;
			num--;
		}

		
		for (int k = 0; k < Length; k++) {		//f() is the bitwise NOT operation
			if (middle[k] == '0')
				middle[k] = '1';
			else if (middle[k] == '1')
				middle[k] = '0';
		}

		
		if (count % 2 == 1)						//The process of adding num bit
			middle[Length] = '1';
		else if (count % 2 == 0)
			middle[Length] = '0';

		unsigned int res = End(middle, Length);

		
		cout << count ;		//End output / exception handling when 32 bit or more
		cout << ": ";

		for (int x = 0; x < Length + 1; x++)
			cout << middle[x];

		cout << endl; 
		cout << res;
		if (res > 4294967294) {
			printf("(overflow!!!)");
		}
		cout << endl;

		Length++;
		input--;
		count++;
	}
}