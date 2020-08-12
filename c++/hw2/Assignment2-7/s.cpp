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
		

		cout << "0. ���α׷� ����" << endl;
		cout << "1. ����ũ ��� �����" << endl;
		cout << "2. ����ũ ���� �����" << endl;
		cout << "3. ����ũ �����ϱ�" << endl;
		cout << "4. �� ����ũ ���� Ȯ���ϱ�" << endl;
		cout << "5. �� ���� Ȯ���ϱ�" << endl;
		cin >> choice;

		Buyer info(M_mask, Money, B_mask);			//Create Object
		Pharmacist Info(p_mask, P_P_mask, B_mask);	//Create Object
	

		if (choice == 0) {
			cout << "���α׷� ����!" << endl;	//Output by Condition
			return 0;
		}
		else if (choice == 1) {
			cout << "���� ����ũ ����: "<< Info.HowManyMask() << "��" << endl << endl;	//Output by Condition
		}
		else if (choice == 2) {
			cout << "����ũ ����: " << Info.HowPriceMask()<< "��" << endl << endl;		//Output by Condition
		}
		else if (choice == 3) {
			cout << "�� ���� �����Ͻðڽ��ϱ�? " << endl ;								//Output by Condition
			cin >> b_mask;
			if (p_mask < b_mask and Money < b_mask * 1000) {
				cout << "����ũ ���� �ܾ� ��� �����մϴ�." << endl << endl;			//Output by Condition
				continue;
			}
			else if (p_mask < b_mask) {
				cout << "����ũ ��� �����մϴ�." << endl << endl;					//Output by Condition
				continue;
			}
			else if (Money < b_mask * 1000) {
				cout << "�ܾ��� �����մϴ�." << endl << endl;							//Output by Condition
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
			cout << "�� ����ũ ����: " << info.HowManyMask() << "��" << endl << endl;	//Output by Condition
		}
		else if (choice == 5) {
			cout << "�� �ܾ�: " << info.HowMuchMoney() << "��" << endl << endl;	//Output by Condition
		}
		else {
			cout << "error!";	//When the value is not between 0 and 5
			return 0;
		}

	}
}