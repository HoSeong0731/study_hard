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

	cout << "ù ��° �Է�" << endl;	//first input
	cout << "�̸�:";
	gets_s(Name);
	cout << "�ּ�:";
	gets_s(address);
	cout << "�ֹι�ȣ:";
	cin >> registration_number;
	cout << "��ȭ��ȣ:";
	cin >> phone_number;
	getchar();

	PatientInfo info(Name, address, registration_number, phone_number); //Create Object

	cout << "�� ��° �Է�" << endl;	//second input
	cout << "�̸�:";
	gets_s(Name);
	cout << "�ּ�:";
	gets_s(address);
	cout << "�ֹι�ȣ:";
	cin >> registration_number;
	cout << "��ȭ��ȣ:";
	cin >> phone_number;
	getchar();

	PatientInfo info1(Name, address, registration_number, phone_number); //Create Object

	cout << "�� ��° �Է�" << endl;	//third input
	cout << "�̸�:";
	gets_s(Name);
	cout << "�ּ�:";
	gets_s(address);
	cout << "�ֹι�ȣ:";
	cin >> registration_number;
	cout << "��ȭ��ȣ:";
	cin >> phone_number;
	getchar();

	PatientInfo info2(Name, address, registration_number, phone_number); //Create Object

	cout << "�� ��° �Է�" << endl;	//fourth input
	cout << "�̸�:";
	gets_s(Name);
	cout << "�ּ�:";
	gets_s(address);
	cout << "�ֹι�ȣ:";
	cin >> registration_number;
	cout << "��ȭ��ȣ:";
	cin >> phone_number;
	getchar();

	PatientInfo info3(Name, address, registration_number, phone_number); //Create Object

	cout << "ù ��° ���" << endl;					//first output
	cout << "�̸�:" << info.getName() << endl;
	cout << "�ּ�: " << info.getAdress() << endl;
	cout << "�ֹι�ȣ: " << info.get_R_Number() << endl;
	cout << "��ȭ��ȣ: " << info.get_P_Number() << endl;

	cout << "�� ��° ���" << endl;					//second output
	cout << "�̸�:" << info1.getName() << endl;
	cout << "�ּ�: " << info1.getAdress() << endl;
	cout << "�ֹι�ȣ: " << info1.get_R_Number() << endl;
	cout << "��ȭ��ȣ: " << info1.get_P_Number() << endl;

	cout << "�� ��° ���" << endl;					//third output
	cout << "�̸�:" << info2.getName() << endl;
	cout << "�ּ�: " << info2.getAdress() << endl;
	cout << "�ֹι�ȣ: " << info2.get_R_Number() << endl;
	cout << "��ȭ��ȣ: " << info2.get_P_Number() << endl;

	cout << "�� ��° ���" << endl;				//fourth output
	cout << "�̸�:" << info3.getName() << endl;
	cout << "�ּ�: " << info3.getAdress() << endl;
	cout << "�ֹι�ȣ: " << info3.get_R_Number() << endl;
	cout << "��ȭ��ȣ: " << info3.get_P_Number() << endl;

	return 0;
}