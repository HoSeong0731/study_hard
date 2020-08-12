#include <iostream>
using namespace std;

int main(){
	
	int Text, CALL = 0;
	char type;
	while(1){
		cout << "Which type: ";
		cin >> type;
		if(type == 'A' or type == 'B' or type == 'C' or type == 'D'){
			break;
		}else{
			cout << "다시 입력하세요." << endl;
			cin.ignore(5, '\n');
		}
	}
	while(1){
		cout << "Text: ";
		cin >> Text;
	
		cout << "CALL: ";
		cin >> CALL;
		
		if(Text >=0 and CALL >= 0 and Text <= 1000 and CALL <=1000){
			break;
		}else{
			cout << "다시 입력하세요." << endl;
			cin.clear();
		}
	}
	cout << "======" <<endl;
	cout << "Result" << endl;
	switch(type){
		case 'A':
			if(Text - 100 >= 0){
				Text = 20*(Text-100);
			}else{
				Text = 0;
			}
			if(CALL - 60 >= 0){
				CALL = 180*(CALL-60);
			}else{
				CALL = 0;
			}
			cout << "Extra text: " << Text << endl;
			cout << "Extra call: " << CALL << endl;
			cout << "Total: "<< 10000 + Text + CALL;
			break;
			
		case 'B':
			if(Text - 150 >= 0){
				Text = 15*(Text-150);
			}else{
				Text = 0;
			}
			if(CALL - 90 >= 0){
				CALL = 150*(CALL-90);
			}else{
				CALL = 0;
			}
			cout << "Extra text: " << Text << endl;
			cout << "Extra call: " << CALL << endl;
			cout << "Total: "<< 15000 + Text + CALL;
			break;
			
		case 'C':
			if(Text - 200 >= 0){
				Text = 10*(Text-200);
			}else{
				Text = 0;
			}
			if(CALL - 120 >= 0){
				CALL = 60*(CALL-120);
			}else{
				CALL = 0;
			}
			cout << "Extra text: " << Text << endl;
			cout << "Extra call: " << CALL << endl;
			cout << "Total: "<< 20000 + Text + CALL;
			break;
			
		default:
			if(Text - 250 >= 0){
				Text = 5*(Text-250);
			}else{
				Text = 0;
			}
			if(CALL - 150 >= 0){
				CALL = 30*(CALL-150);
			}else{
				CALL = 0;
			}
			cout << "Extra text: " << Text << endl;
			cout << "Extra call: " << CALL << endl;
			cout << "Total: "<< 25000 + Text + CALL;
			
	}
}
