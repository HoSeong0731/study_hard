#include <iostream>
#include <windows.h>
using namespace std;

int main(){
	char arr1[1000];		//�Է¿� �ʿ��� �迭  
	char arr2[1000];		//��ȯ�� �ʿ��� �迭  
	int i, count, j = 0; 	//�ݺ����� �ʿ��� ������  
	
	
	cout << "Enter the string(range < 1000) : ";	 
	gets(arr1);										//�������� 1000�������� 1���� �迭   
	
	for(i = 0; i < 1000; i++){						//��ȯ �ݺ���  
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
	count = i;						//�ʱ�ȭ���� ���� i�� = if�� ���ư� Ƚ�� = ����  
	for(j = 0; j <= count; j++){	//���ڿ� ������ �ݺ���  
		arr2[count - j] = arr1[j];
	}
	cout << "Result : " ;
	for(j = 1; j <= count; j++){	//���� �տ� ���͸� ���� ���� 1�� �����ؼ� ���  
		cout << arr2[j];
	}
	Sleep(1000); 	//���α׷� ���Ḧ 1�ʰ� ����. 
	return 0;	
}
