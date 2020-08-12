#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

int main() {
	ifstream rF;					//readfile
	string String;
	string password;
	int count = 0, j = 0, convert = 0, arr[1000];
	
	rF.open("ciphertext.txt");		//Load file
	while (!rF.eof()) {
		getline(rF, String);		//Repeat until end of file
	}

	cout << "ciphertext : "; 
	cout << String;

	stringstream Stringstream(String);			//Convert ASCII hexadecimal code to decimal.

	while (Stringstream >> password) {
		int tmp = stoi(password, NULL, 16);		//string to int
		arr[convert] = tmp;
		convert++;
	}

	
	for (count = 0; count < 128; count++) {
		cout << "key(";
		cout << count;
		cout << ") : ";
		for (j = 0; j < convert; j++) {		//Conditions to switch back to the original
			if (arr[j] + count > 255) {		
				cout << (char)(arr[j] + count - 256);
			}				
			if (arr[j] + count > 127) {
				cout << (char)(arr[j] + count - 128);
			}			
			else {
				cout << (char)(arr[j] + count);
			}
				
		}
		cout << endl;
	}

	
	rF.close();		//Close the file.
	return 0;
}
