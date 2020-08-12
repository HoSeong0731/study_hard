#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void ComSel(int* arr); // The computer is four the number of choices.
int IsValid(int* arr); // Validate user input. 1 return if valid
void UsrSel(int* arr); // Enter a number for four users.
int Compare(int* arr1, int* arr2); // Comparing selection results.

int main(void)
{
	int comArr[4];		// Automatic selection of computers
	int usrArr[4];		// selection by user
	int result = 0;		// repeating sentence condition  

	printf("Start Game! \nRandom numbers:\n");
	ComSel(comArr);		//Numeric function of a computer  
	while (result != 1)	//Repeat until result 1
	{
		UsrSel(usrArr);	//User's numeric selection function 
		result = Compare(comArr, usrArr);	//Comparative function 
	}
	printf("Game End! \n");
	return 0;
}

void ComSel(int* arr)	// Your computer selects four numbers
{
	srand((int)time(NULL));	//random water generation
	arr[0] = rand() % 9 + 1;	//Specify a digit of 1000 (the first number must be at least 1). 
	do {
		arr[1] = rand() % 9;	//Specify a digit of 100 (until it does not overlap a digit of 1000) 
	} while (arr[0] == arr[1]);
	do {
		arr[2] = rand() % 9;	//10 digit designation(until 1000 digits and 100 digits do not overlap)
	} while ((arr[0] == arr[2]) or (arr[1] == arr[2]));
	do {
		arr[3] = rand() % 9;	//Specify a digit of 1 (until there is no overlap between 1000 digits and 100 digits and 10 digits) 
	} while ((arr[0] == arr[3]) or (arr[1] == arr[3]) or (arr[2] == arr[3]));
}

int IsValid(int* arr) 	//Check that the user has entered the correct number  
{
	if (arr[0] == arr[1] or arr[0] == arr[2] or arr[0] == arr[3] or arr[1] == arr[2] or arr[1] == arr[3] or arr[2] == arr[3])
		//If four numbers chosen by the user overlap,  
		return 0;	//Returns a value of zero
	else	//non-overlapping facies  
		return 1;	//1Returns a value of one.  
}

void UsrSel(int* arr)	//User-Entered Numeric Receiving Function
{
	int valid;
	printf("Your number : ");

	while (1)
	{
		scanf_s("%1d %1d %1d %1d", &arr[0], &arr[1], &arr[2], &arr[3]);	//%1d to allow only one input. 
		cin.ignore(1000, '\n');		//Input Clear Buffer 
		valid = IsValid(arr);		//Specify value as isvalid value, execute function if correct number is entered  

		if (valid == 1)	//if not overlapped 
			break;		//Repeated Gate Escape
		else if (arr[4] != NULL) {
			printf("Incorrect input, Re-input : ");
			continue;
		}
		else {
			printf("Incorrect input, Re-input : ");
			continue;
		}
	}
}

int Compare(int* arr1, int* arr2)	//comparative function
{
	static int count = 0;	
	int HIT = 0, BLOW = 0;
	int i, j;

	for (i = 0; i < 4; i++){
		for (j = 0; j < 4; j++)	
		{
			if (arr1[i] == arr2[j])	  
			{
				i == j ? HIT++ : BLOW++;	//If the value of i and j is the same, increase in HIT or not increase in BLOW 
				break;
			}
		}
	}
	count++;		//Increase each time function is executed (if 0 is returned, function is terminated, but does not change to zero with static use)
	printf(">> %dHIT, %dBLOW!!\n", HIT, BLOW);
	if (count == 10) {
		if (HIT == 4) {		
			printf("Win\n");
			return 1;	
		}
		else {
			printf("Lose\n");
			return 1;	
		}
			
	}
	if (HIT == 4){		
		printf("Win");
		return 1;	
		}
	else
		return 0;
}
