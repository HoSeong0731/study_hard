#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
 int len = 1;	//���� �� �޾Ƽ� ���� ���ϴ� ����  
 int input = 0;	//����ڿ��� ���� �޴� ����  
 int count = 1;	//����ڰ� �Է��� ������ ����ŭ len�� ���ϱ� 3�� �ݺ���.
 int i, j, k; 	//�ݺ������� ����ϱ� ���� ������ 
while(1)		//�������� �� �Է¹޴� �ݺ��� 
{
 cout << "Enter the power of 3(range = 3~2187): ";
 cin >> input;
 
 if(input <= 2187 and input >= 3 and input % 3 == 0)
 break;
 
 cout << "�߸� �� ���� �Է��߽��ϴ�.";
 cout << endl;
}
 
 if(input == 3){
 	input = 1;
 }else if(input == 9){
 	input = 2;
 }else if(input == 27){
 	input = 3;
 }else if(input == 81){
 	input = 4;
 }else if(input == 243){
 	input = 5;
 }else if(input == 729){
 	input = 6;
 }else{
 	input = 7;
 }
 
for(len = 1; count <= input; count++){ 	//len�� input�� ��ŭ ���� ���� ����. 
	len = len*3;
}	

	for (i = 0; i < len; i++)		//3�� input�¸�ŭ�� ���α��� 
	{			
		for (j = 0; j < len; j++)  //3�� input�¸�ŭ�� ���α���
		{		  
			for (k = len / 3; k; k /= 3)
				if ((j % (k * 3)) / k == 1 and (i % (k * 3)) / k == 1)
					break;
			cout << (k ? " " : "#");
		}
		cout << endl;
	}

 Sleep(1000); //1������ 
 return 0;
 
}
