#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

int main() {
	int row, column, mid, i, j, count = 0;
	while (1) {
		cout << "Enter the row: ";		//Received row value
		cin >> row;
		cout << "Enter the column: ";	//Received column value
		cin >> column;
		if (row >= 1 and row <= 100 and column >= 1 and column <= 100) {
			break;
		}
		else {
			cout << "잘못된 값을 입력했습니다. " << endl;
		}
	}
	mid = column * row;	// the number of random numbers
	int arr[10000];
	int arr2[100][100];

	srand((unsigned int)time(NULL));	//random function

	for (i = 0; i < mid; i++) {			//Algorithm to get it back if it overlaps with the value so far
		arr[i] = rand() % mid;
		for (j = 0; j < i; j++) {
			if (arr[j] == arr[i]) {
				arr[i] == rand() % mid;
				i--;
			}
		}
	}

	for (i = 0; i < column; i++) {		//Copy values to a two-dimensional array
		for (j = 0; j < row; j++) {
			arr2[i][j] = arr[count];
			count++;
		}
	}

	cout << "Origin Matrix>>>" << endl;	//Output original matrix
	for (i = 0; i < column; i++) {
		for (j = 0; j < row; j++) {
			printf("%-5d", arr2[i][j]);
		}
		cout << endl;
	}

	cout << "Transpose Matrix>>>" << endl;	//output transposition matrix
	for (i = 0; i < row; i++) {	
		for (j = 0; j < column; j++) {
			printf("%-5d", arr2[j][i]);
		}
		cout << endl;
	}
	Sleep(1000);
	return 0;

}
