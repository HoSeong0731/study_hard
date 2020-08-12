#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

int main(){
	int row, column, mid, i, j, count = 0;
	while(1){
		cout << "Enter the row: ";
		cin >> row;
		cout << "Enter the column: ";
		cin >> column;
		if(row >= 1 and row <= 100 and column >= 1 and column <= 100){
			break;
		}else{
			cout << "잘못된 값을 입력했습니다. " << endl;
		}
	} 	
	mid = column * row;
	int arr[mid];
	int arr2[column][row];
	
	srand((unsigned int)time(NULL));
	
	for(i = 0; i < mid; i++){
		arr[i] = rand() % mid;
		for(j = 0; j < i; j++){
			if (arr[j] == arr[i]){
				arr[i] == rand() % mid;
				i--;
			}
		}		
	}
	
	for(i = 0; i < column; i++){
		for(j = 0; j < row; j++){
			arr2[i][j] = arr[count];
			count++;
		}
	}
	
	cout << "Origin Matrix>>>" << endl;
	for(i = 0; i < column; i++){
		for(j = 0; j < row; j++){
			printf("%-5d", arr2[i][j]);
		}
		cout << endl;
	}
	
	cout << "Transpose Matrix>>>" << endl;
	for(i = 0; i < row; i++){
		for(j = 0; j < column; j++){
			printf("%-5d", arr2[j][i]);
		}
		cout << endl;
	}
	return 0;
	
}
