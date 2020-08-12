#include <iostream>
#include <time.h>
#include <fstream>
#include <string>

using namespace std;

int main() {
	
	char str[100];	//String to be entered in file
	char str2[100];	//String to output to file
	float a = 0, b = 0, c = 0, count = 0;		//Accuracy, used to obtain speed
	time_t start, end;			//Use with respect to time
	ifstream fin("source.txt");	//Retrieve file
	ofstream fout("result.txt");//Retrieve file

	if (!fin.is_open()) {		//If the file fails to load
		cout << "No file!:" << endl;
		return 0;
	}

	fout << "Kw Typing Verification Program" << endl;	//input form
	fout << "정확도: " << a << "           ";
	fout << "속도(타자/s): " << b << endl;
	
	while (1) {
		fin.getline(str, 100);	//Importing a string from a file.
		if (!(fin)) {			//erminate repeating statements when all strings in the file have been retrieved.
			break;
		}
		

		start = time(NULL);		//Start Count
		cout << fixed;			//Pinpoint Output
		cout.precision(1);
		cout << "Kw Typing Verification Program" << endl;	//output
		cout << "정확도: " << a << "           ";
		cout << "속도(타자/s): " << b << endl;
		cout << "문장 : " << str << endl;
		cout << "입력 : ";
		gets_s(str2);		//Received string input from user
		end = time(NULL);	//End Count

		system("cls");		//Clear Screen
		count = 0;			//Initialize every iteration
		
		
		
		for (int i = 0; i < strlen(str); i++) {	//Increasing the count (increasing the accuracy) with each character being equal.
			if(str[i] == str2[i]){
				count++;
			}
		}
		c = strlen(str2);		//Obtain the length of str2
		b = c / (end - start);	//typing speed per second
		a = count*100 / strlen(str2);	//Obtaining Accuracy
		fout << str2 << endl;			//Output to entered string file
		fout << "정확도: " << a << "           ";
		fout << "속도(타자/s): " << b << endl;
	}
	fin.close();	//Release
	fout.close();	//Release
	return 0;		//Exit Main Function
}