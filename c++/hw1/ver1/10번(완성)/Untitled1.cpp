#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <time.h>

using namespace std;

void ComSel(int *arr); // 컴퓨터가 4개의 숫자를 선택
int IsValid(int *arr); // 사용자 입력 유효성 검사. 유효하면 1 리턴
void UsrSel(int *arr); // 사용자 4개의 숫자를 입력.
int Compare(int *arr1, int *arr2); // 선택 결과 비교.

int main(void)
{
	int comArr[4];		// 컴퓨터의 자동 선택
	int usrArr[4];		// 사용자에 의한 선택
	int result=0;		// 반복문 조건  

	printf("Start Game! \n");
	ComSel(comArr);	//컴퓨터의 숫자 지정 함수  
	cout << comArr[0] <<endl;
	cout << comArr[1] <<endl;
	cout << comArr[2] <<endl;
	cout << comArr[3] <<endl;
	while(result!=1)	//result가 1일때 까지 반복  
	{
		UsrSel(usrArr);	//유저의 숫자 선택 함수  
		result=Compare(comArr, usrArr);	//결과비교 함수 
		printf("\n");
	}
	printf("Game End! \n");
	return 0;
}

void ComSel(int *arr)	// 컴퓨터가 4개의 숫자를 선택
{
	srand((int)time(NULL));	//난수생성 
	arr[0]=rand()%9+1;		//백의 자리 숫자 지정(앞의 숫자가 1이상이어야 함.) 
	do{					
		arr[1]=rand()%9;	//십의 자리 숫자 지정(백의 자리와 겹치지 않을 때 까지) 
	}while(arr[0]==arr[1]);
	do{					
		arr[2]=rand()%9;	//일의 자리 숫자 지정(백의 자리와 십의 자리 숫자가 겹치지 않을 때 까지) 
	}while((arr[0]==arr[2])or(arr[1]==arr[2])); 
	do{					
		arr[3]=rand()%9;	//일의 자리 숫자 지정(백의 자리와 십의 자리 숫자가 겹치지 않을 때 까지) 
	}while((arr[0]==arr[3])or(arr[1]==arr[3])or(arr[2]==arr[3]));
}

int IsValid(int *arr) 	//user가 올바른 숫자입력했는지 검사  
{
	if(arr[0]==arr[1] or arr[0]==arr[2] or arr[0]==arr[3] or arr[1]==arr[2] or arr[1]==arr[3] or arr[2]==arr[3] )	
	//유저가 선택한 숫자 4개가 겹친다면  
		return 0;	//0값을 반환 
	else	//겹치지 않는 다면  
		return 1;	//1값을 반환  
}

void UsrSel(int *arr)	//유저가 입력한 숫자 받는 함수  
{
	int valid;
	printf("4개의 숫자 선택 : ");

	while(1)
	{
		scanf("%1d %1d %1d %1d", &arr[0], &arr[1], &arr[2], &arr[3]);	//하나씩만 입력받게 하기 위해 %1d로 함. 
		fflush(stdin);		//입력버퍼 지우기 
		valid=IsValid(arr);	//valid값을 isvalid값으로 지정, 올바른 숫자 입력했는지 함수 실행   

		if(valid==1)	//겹치지 않으면  
			break;		//반복문 탈출  
		else			//겹치면  
			printf("잘못된 입력, 재 입력 : ");
	}
}

int Compare(int *arr1, int *arr2)	//비교 함수 
{
	static int count=0;	//후에 몇 번의 시도만에 맞췄는가  
	int strike=0, ball=0;
	int i, j;

	for(i=0; i<4; i++)	//4번 반복  
	{
		for(j=0; j<4; j++)	//4번 반복  
		{
			if(arr1[i]==arr2[j])	//비교한 두 개의 값이 같을 때  
			{
				i==j? strike++:ball++;	//i와 j의 값이 같으면 strike증가 아니면 ball증가  
				break;
			}
		}
	}
	count++;		//함수 실행할때 마다 증가(0이 반환된다면 함수종료지만 static사용으로 0으로 변하지 않음) 
	printf("%d번째 도전 결과 : %dstrike, %dball!!\n", count, strike, ball);

	if(strike==4)	//3개 다 순서까지 맞추었을 경우  
		return 1;	//1값 반환  
	else
		return 0;	//0값 반환  
}
