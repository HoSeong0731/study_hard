#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	int input;	//사용자가 입력하는 값을 받는 변수 
	int p = 2; 		//소수찾기에서 사용되는 변수(2부터 시작) 
	int count = 0; 	//소수가 몇 번 나왔는지 파악할 때 쓰는 변수  
	int i = 0;
	while(1){
		cout << "enter the n: ";	//사용자에게 값을 받음 
		cin >> input;
		if (input <= 1){
			cout << "잘못된 값을 입력했습니다."; 
			cout << endl;
		}else{
			break;
		}
		
	} 
	
	int *arr = (int*)malloc((input+1)*4);   //input사이즈의 1차원 배열 만듬. 
	for(int i = 0; i < input-1; i++){		//2부터 n까지의 숫자를 넣음. 
		arr[i] = i+2;
	}
	while(p*p <= input){					//sqrt(input)보다 작을 경우에만 반복  
		
	 	for(i = 0; i < input-1; i++){	//2부터 n까지의 숫자를 넣음. 
			if (arr[i+p] % p == 0){		//p보다 작은 숫자가 남아있으면 그건 소수니까 i+p부터 계산  
				arr[i+p] = 0;			//나눴을 때 나머지가 0이다. = 소인수가 있다 => 소수가 있다.  
			}		
		}
		p++;	//while문 탈출 조건
	} 
	for(i = 0; i < input-1; i++){	//남은 소수들 출력 반복문 
		if(arr[i] != 0){
			cout << arr[i];
			cout << " ";
			count++;
		}
	
	}
	cout << endl; 
	cout << "The number of Prime numbers: " << count;	//카운트 된 소수 개수들. 
	Sleep(1000); 
	return 0;
}
