#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	int input;	//����ڰ� �Է��ϴ� ���� �޴� ���� 
	int p = 2; 		//�Ҽ�ã�⿡�� ���Ǵ� ����(2���� ����) 
	int count = 0; 	//�Ҽ��� �� �� ���Դ��� �ľ��� �� ���� ����  
	int i = 0;
	while(1){
		cout << "enter the n: ";	//����ڿ��� ���� ���� 
		cin >> input;
		if (input <= 1){
			cout << "�߸��� ���� �Է��߽��ϴ�."; 
			cout << endl;
		}else{
			break;
		}
		
	} 
	
	int *arr = (int*)malloc((input+1)*4);   //input�������� 1���� �迭 ����. 
	for(int i = 0; i < input-1; i++){		//2���� n������ ���ڸ� ����. 
		arr[i] = i+2;
	}
	while(p*p <= input){					//sqrt(input)���� ���� ��쿡�� �ݺ�  
		
	 	for(i = 0; i < input-1; i++){	//2���� n������ ���ڸ� ����. 
			if (arr[i+p] % p == 0){		//p���� ���� ���ڰ� ���������� �װ� �Ҽ��ϱ� i+p���� ���  
				arr[i+p] = 0;			//������ �� �������� 0�̴�. = ���μ��� �ִ� => �Ҽ��� �ִ�.  
			}		
		}
		p++;	//while�� Ż�� ����
	} 
	for(i = 0; i < input-1; i++){	//���� �Ҽ��� ��� �ݺ��� 
		if(arr[i] != 0){
			cout << arr[i];
			cout << " ";
			count++;
		}
	
	}
	cout << endl; 
	cout << "The number of Prime numbers: " << count;	//ī��Ʈ �� �Ҽ� ������. 
	Sleep(1000); 
	return 0;
}
