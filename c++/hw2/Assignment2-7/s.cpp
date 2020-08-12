#include <iostream>

using namespace std;

class Buyer {	//Buyer Class
private:
	int M_mask;
	int Money;
	int B_mask;
public:
	Buyer(int M_mask, int Money, int B_mask) {	//Default Constructor
		this->M_mask = M_mask;
		this->Money = Money;
		this->B_mask = B_mask;
	};
	~Buyer() {};								//destructor
	int HowMuchMoney() {						//Return Value
		return Money;
	};
	int HowManyMask() {							//Return Value
		return M_mask;
	}
};

class Pharmacist {								//pharmacist class

private:
	int p_mask;
	int P_P_mask;
	int B_mask;
public:
	Pharmacist(int p_mask, int P_P_mask, int B_mask) {	//Default Constructor
		this->p_mask = p_mask;
		this->P_P_mask = P_P_mask;
		this->B_mask = B_mask;
	};
	~Pharmacist() {};					//destructor
	int HowManyMask() {					//Return Value
		return p_mask;
	};
	int HowPriceMask() {				//Return Value
		return P_P_mask;
	}
};

int main() {
	int choice = 5;					//Set Initial Value
	int p_mask = 5;
	int P_P_mask = 1000;
	int B_mask = 0, b_mask = 0;
	int M_mask = 0;
	int Money = 3000;

	while (choice != 0) {		//Repeat until zero is entered
		

		cout << "0. 프로그램 종료" << endl;
		cout << "1. 마스크 재고 물어보기" << endl;
		cout << "2. 마스크 가격 물어보기" << endl;
		cout << "3. 마스크 구매하기" << endl;
		cout << "4. 내 마스크 갯수 확인하기" << endl;
		cout << "5. 내 지갑 확인하기" << endl;
		cin >> choice;

		Buyer info(M_mask, Money, B_mask);			//Create Object
		Pharmacist Info(p_mask, P_P_mask, B_mask);	//Create Object
	

		if (choice == 0) {
			cout << "프로그램 종료!" << endl;	//Output by Condition
			return 0;
		}
		else if (choice == 1) {
			cout << "남은 마스크 갯수: "<< Info.HowManyMask() << "개" << endl << endl;	//Output by Condition
		}
		else if (choice == 2) {
			cout << "마스크 가격: " << Info.HowPriceMask()<< "원" << endl << endl;		//Output by Condition
		}
		else if (choice == 3) {
			cout << "몇 개를 구매하시겠습니까? " << endl ;								//Output by Condition
			cin >> b_mask;
			if (p_mask < b_mask and Money < b_mask * 1000) {
				cout << "마스크 재고와 잔액 모두 부족합니다." << endl << endl;			//Output by Condition
				continue;
			}
			else if (p_mask < b_mask) {
				cout << "마스크 재고가 부족합니다." << endl << endl;					//Output by Condition
				continue;
			}
			else if (Money < b_mask * 1000) {
				cout << "잔액이 부족합니다." << endl << endl;							//Output by Condition
				continue;
			}
			else {
				B_mask = B_mask + b_mask;				//Calculate value after purchase
				p_mask = p_mask - b_mask;
				M_mask = M_mask + b_mask;
				Money = Money - (b_mask * 1000);
				cout << endl;
			}
		}
		else if (choice == 4) {
			cout << "내 마스크 갯수: " << info.HowManyMask() << "개" << endl << endl;	//Output by Condition
		}
		else if (choice == 5) {
			cout << "내 잔액: " << info.HowMuchMoney() << "원" << endl << endl;	//Output by Condition
		}
		else {
			cout << "error!";	//When the value is not between 0 and 5
			return 0;
		}

	}
}