#include <iostream>
#include <string>

using namespace std;

class PatientInfo {
private:
	char* name;
	char* address;
	int registration_number;
	int phone_number;

public:
	PatientInfo(char* name, char* address, int registration_number, int phone_number) {	//Create Object
		this->name = name;
		this->address = address;
		this->registration_number = registration_number;
		this->phone_number = phone_number;
	};
	~PatientInfo() {};

	char* getName();
	char* getAdress();
	int get_R_Number();
	int get_P_Number();
};

char* PatientInfo::getName() {	//function content
	return name;
}

char* PatientInfo::getAdress() {//function content
	return address;
}
int PatientInfo::get_R_Number() {//function content
	return registration_number;
}
int PatientInfo::get_P_Number() {//function content
	return phone_number;
}

int main() {
	char Name[100] = { NULL, };
	char address[100] = { NULL, };
	int registration_number;
	int phone_number;

	cout << "첫 번째 입력" << endl;	//first input
	cout << "이름:";
	gets_s(Name);
	cout << "주소:";
	gets_s(address);
	cout << "주민번호:";
	cin >> registration_number;
	cout << "전화번호:";
	cin >> phone_number;
	getchar();

	PatientInfo info(Name, address, registration_number, phone_number); //Create Object

	cout << "두 번째 입력" << endl;	//second input
	cout << "이름:";
	gets_s(Name);
	cout << "주소:";
	gets_s(address);
	cout << "주민번호:";
	cin >> registration_number;
	cout << "전화번호:";
	cin >> phone_number;
	getchar();

	PatientInfo info1(Name, address, registration_number, phone_number); //Create Object

	cout << "세 번째 입력" << endl;	//third input
	cout << "이름:";
	gets_s(Name);
	cout << "주소:";
	gets_s(address);
	cout << "주민번호:";
	cin >> registration_number;
	cout << "전화번호:";
	cin >> phone_number;
	getchar();

	PatientInfo info2(Name, address, registration_number, phone_number); //Create Object

	cout << "네 번째 입력" << endl;	//fourth input
	cout << "이름:";
	gets_s(Name);
	cout << "주소:";
	gets_s(address);
	cout << "주민번호:";
	cin >> registration_number;
	cout << "전화번호:";
	cin >> phone_number;
	getchar();

	PatientInfo info3(Name, address, registration_number, phone_number); //Create Object

	cout << "첫 번째 출력" << endl;					//first output
	cout << "이름:" << info.getName() << endl;
	cout << "주소: " << info.getAdress() << endl;
	cout << "주민번호: " << info.get_R_Number() << endl;
	cout << "전화번호: " << info.get_P_Number() << endl;

	cout << "두 번째 출력" << endl;					//second output
	cout << "이름:" << info1.getName() << endl;
	cout << "주소: " << info1.getAdress() << endl;
	cout << "주민번호: " << info1.get_R_Number() << endl;
	cout << "전화번호: " << info1.get_P_Number() << endl;

	cout << "세 번째 출력" << endl;					//third output
	cout << "이름:" << info2.getName() << endl;
	cout << "주소: " << info2.getAdress() << endl;
	cout << "주민번호: " << info2.get_R_Number() << endl;
	cout << "전화번호: " << info2.get_P_Number() << endl;

	cout << "네 번째 출력" << endl;				//fourth output
	cout << "이름:" << info3.getName() << endl;
	cout << "주소: " << info3.getAdress() << endl;
	cout << "주민번호: " << info3.get_R_Number() << endl;
	cout << "전화번호: " << info3.get_P_Number() << endl;

	return 0;
}