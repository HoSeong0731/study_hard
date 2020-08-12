#include <iostream>
#include <windows.h>

using namespace std;

int main() {
	char arr1[1000];		//Array required for input  
	char arr2[1500];		//Array Required for Conversion  
	int i, count, j = 0; 	//Variables Required for Repetition  

	cout << "Enter the string(range < 1000) : ";
	for (i = 0; i < 1000; i++) {						//Clear all null values.
		arr1[i] = '-';
	}
	cin.getline(arr1, 1000, '\n');




	for (i = 0; i < 1000; i++) {						//Conversion Repetition  
		if (arr1[i] >= 'A' and arr1[i] <= 'Z') {
			arr1[i] = arr1[i] + 32;
		}
		else if (arr1[i] >= 'a' and arr1[i] <= 'z') {
			arr1[i] = arr1[i] - 32;
		}
		else if (arr1[i] == ' ') {
			arr1[i] = arr1[i];
		}
		else if (arr1[i] == '-') {
			break;
		}
	}
	count = i;						//Uninitialized i value = number of times if returned = length  
	for (j = 0; j <= count; j++) {	//string reverse repeating statement  
		arr2[count - j] = arr1[j];
	}
	cout << "Result : ";
	for (j = 1; j <= count; j++) {	//Output starting with 1 to take out the first entry.  
		if (arr2[j] == '-') {
			continue;
		}
		cout << arr2[j];
		if (j == 1500) {
			return 0;
		}
	}
	Sleep(1000); 	//Stop the program for 1 second. 
	return 0;
}
