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
        array[len] = decimal2 % 2;    // 2�� �������� �� �������� �迭�� ����
        decimal2 = decimal2 / 2;             // 2�� ���� ���� ����

        len--;    // �ڸ��� ����

        if (decimal2 == 0)    // ���� 0�� �Ǹ� �ݺ��� ����
            break;
    }
    
    for(i = 0; i <32; i++){	//�� �³� ����ϱ�  
    	if(array[i] == 0 or array[i] == 1){
    		cout << array[i];
		}else{	
			continue;
		}
	}
	
	for(i = 0; i <32; i++){	//�� �³� ����ϱ�  
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
Assignment 1-3(��ȭ��) -> �������� �ʿ�
S(0) = user input vit stream (2���� ������ �Է��ؾ� ��.)
S(n) �� Ȧ���϶� 1�� ���ϰ� ¦�� �϶��� 0�� ����.

-�� �� �ݺ��� ����
-input 2�������� �ƴ϶�� �ٽ� �޴� ����
-input ���� �������� ��ȯ�ϴ� �ڵ�
-overflow ���� ����ϱ�(32��Ʈ������) 
-���� Ȧ���� �̰� ¦���� �̰� ����
2, 3, 5
*/
