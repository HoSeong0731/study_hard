#include <iostream>
#include <windows.h>
using namespace std;

int main(){
	char arr1[1000];		//입력에 필요한 배열  
	char arr2[1000];		//변환에 필요한 배열  
	int i, count, j = 0; 	//반복문에 필요한 변수들  
	
	
	cout << "Enter the string(range < 1000) : ";	 
	gets(arr1);										//고정으로 1000사이즈인 1차원 배열   
	
	for(i = 0; i < 1000; i++){						//변환 반복문  
		if(arr1[i]>= 'A' and arr1[i]<= 'Z'){
			arr1[i] = arr1[i]+32;
		}
		else if(arr1[i]>= 'a' and arr1[i]<= 'z'){
			arr1[i] = arr1[i]-32;
		}else if(arr1[i] >= ' '){
			arr1[i] = arr1[i];
		}else if(arr1[i] = '\n'){
			break;
		}		
	}
	count = i;						//초기화되지 않은 i값 = if가 돌아간 횟수 = 길이  
	for(j = 0; j <= count; j++){	//문자열 리버스 반복문  
		arr2[count - j] = arr1[j];
	}
	cout << "Result : " ;
	for(j = 1; j <= count; j++){	//가장 앞에 엔터를 빼기 위해 1로 시작해서 출력  
		cout << arr2[j];
	}
	Sleep(1000); 	//프로그램 종료를 1초간 멈춤. 
	return 0;	
}
