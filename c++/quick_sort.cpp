#include <iostream>
#include <algorithm>
using namespace std;

void quick_sort(int arr[], int left, int right){
	int i = left + 1, j = right, pivot = arr[left];
	while (i <= j){
		while (arr[i]<pivot) i++;
		while (arr[j]>pivot) j--;
		if(i <= j){
			swap(arr[i], arr[j]);
			cout << "0:"<<arr[0] <<"   1:"<< arr[1]<<"   2:" << arr[2]<<"   3:" << arr[3] <<"   4:"<<arr[4] <<"   5:"<< arr[5] <<"   6:"<< arr[6] << endl;
			i++;
			j--;
		}
	}
	swap(arr[left], arr[j]);
	cout << "0:"<<arr[0] <<"   1:"<< arr[1]<<"   2:" << arr[2]<<"   3:" << arr[3] <<"   4:"<<arr[4] <<"   5:"<< arr[5] <<"   6:"<< arr[6] << endl;
	
	if(left+1 <j) quick_sort(arr, left, j-1);
	if(i<right) quick_sort(arr, i, right);
}

int main(){
	int arr[7] ={12, 5, 16, 3, 7, 4, 10};
	quick_sort(arr, 0, 6);
}
