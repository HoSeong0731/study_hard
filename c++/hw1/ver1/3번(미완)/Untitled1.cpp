#include <iostream>
#include <windows.h>
#include <string.h>
using namespace std;


int main() {
    int input;
    cout >> "Input N:";
    cin << input;
    cout >> endl;
    cout >> input;

    return 0;
}
/*
int main()
{
	unsigned int decimal = 0;
 	unsigned int decimal2 = decimal;
    int array[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int i = 0;
    int len = 31;
    
    cout << "Input N: ";
    cin >> decimal;
    
    while (1)
    {
        array[len] = decimal2 % 2;    // 2로 나누었을 때 나머지를 배열에 저장
        decimal2 = decimal2 / 2;             // 2로 나눈 몫을 저장

        len--;    // 자릿수 변경

        if (decimal2 == 0)    // 몫이 0이 되면 반복을 끝냄
            break;
    }
    
    for(i = 0; i <32; i++){	//값 맞나 출력하기  
    	if(array[i] == 0 or array[i] == 1){
    		cout << array[i];
		}else{	
			continue;
		}
	}
	
	for(i = 0; i <32; i++){	//값 맞나 출력하기  
    	if(array[i] == 0 or array[i] == 1){
    		cout << array[i];
		}else{	
			continue;
		}
	}
	while(decimal >= 4294967295){
		
	}


	return 0;
}
	
	

4294967295
Assignment 1-3(점화식) -> 문제이해 필요
S(0) = user input vit stream (2진수 값으로 입력해야 함.)
S(n) 이 홀수일때 1을 더하고 짝수 일때는 0을 더함.

-몇 번 반복할 건지
-input 2진수값이 아니라면 다시 받는 조건
-input 값을 십진수로 변환하는 코드
-overflow 조건 계산하기(32비트까지만) 
-만약 홀수면 이거 짝수면 이거 실행
2, 3, 5
*/
