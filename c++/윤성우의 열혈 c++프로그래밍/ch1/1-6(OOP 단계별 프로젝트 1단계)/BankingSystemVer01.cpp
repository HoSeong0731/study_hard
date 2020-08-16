/*
 * Banking System Ver 0.1
 * �ۼ���: ��ȣ��
 * �� ��: OOP �ܰ躰 ������Ʈ�� �⺻ Ʋ ����
 * �ʿ��� ��: 1. ����ó��(�ڷ����� ���� ���� ������ ������ �ʰ� �ؾ���.)
 * enum: ������ �����͵��� ���ó�� ���� �� �� �ִ�.(��ȣ�� �� �� �����ϸ�, �˾Ƽ� ������ ��ȣ�� �־��ش�.) 
 */
 
 #include <iostream>
 #include <cstring>
 
 using namespace std;
 const int NAME_LEN=20;
 	
 void ShowMenu();		//�޴���� 
 void MakeAccount();	//���°����� ���� �Լ� 
 void DepositMoney();	//�� �� 
 void WithdrawMoney();	//�� �� 
 void ShowAllAccInfo(); //�ܾ� ��ȸ
 
 enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};
 
 typedef struct{
 	int accID;				//���¹�ȣ 
 	int Balance;			//�ܾ� 
 	char cusName[NAME_LEN];	//����� �̸� 
 } Account;
 
 Account accArr[100];
 int accNum=0;
 
 int main()
 {
 	int choice;
 	
 	while(1)
 	{
 		ShowMenu();
 		cout<<"����: ";
 		cin>>choice;
		cout<<endl;
		
		switch(choice)
		{
			case MAKE:
				MakeAccount();
				break;
			case DEPOSIT:
				DepositMoney();
				break;
			case WITHDRAW:
				WithdrawMoney();
				break;
			case INQUIRE:
				ShowAllAccInfo();
				break;
			case EXIT:
				return 0;
			defult:
				cout<<"�ٽ� �������ּ���.."<<endl; 
		 } 
	 }
	 return 0;
 }
 
 void ShowMenu()
 {
 	cout<<"------Menu------"<<endl;
	cout<<"1. ���°���"<<endl;
	cout<<"2. �� ��"<<endl;
	cout<<"3. �� ��"<<endl;
	cout<<"4. �������� ��ü ���"<<endl;
	cout<<"5. ���α׷� ����"<<endl;	
	cout<<"----------------"<<endl; 
 }
 
 void MakeAccount()
 {
 	int id;
 	char name[NAME_LEN];
 	int balance;
 	
 	cout<<"[���°���]"<<endl;
 	cout<<"���¹�ȣ: "; cin>>id; cin.clear();
 	cout<<"�� ��: "; cin>>name; cin.clear();
 	cout<<"�Աݾ�: "; cin>>balance;	cin.clear();
 	cout<<endl;
 	
 	accArr[accNum].accID=id;
 	accArr[accNum].Balance=balance;
 	strcpy(accArr[accNum].cusName, name);
 	accNum++;
 }
 
 void DepositMoney()
 {
	int money;
	int id;
	cout<<"[��  ��]"<<endl;
	cout<<"����ID: "; cin>>id; cin.clear();
	cout<<"�Աݾ�: "; cin>>money; cin.clear();
	
	for(int i=0; i<accNum; i++)
	{
		if(accArr[i].accID==id){
			accArr[i].Balance+=money;
			return;
		}
	 }
	 cout<<"��ȿ���� ���� ID �Դϴ�."<<endl<<endl;
 }
 
 void WithdrawMoney()
 {
 	int money;
 	int id;
 	cout<<"[��  ��]"<<endl;
	cout<<"����ID: "; cin>>id; cin.clear();
	cout<<"��ݾ�: "; cin>>money; cin.clear();
	
	for(int i=0; i<accNum; i++)
	{
		if(accArr[i].accID=id)
		{
			if(accArr[i].Balance<money){
				cout<<"�ܾ׺���"<<endl<<endl;
				return; 
			}
			
			accArr[i].Balance-=money;
			cout<<"��ݿϷ�"<<endl<<endl;
			return;
		}
	 } 
	 cout<<"��ȿ���� ���� ID �Դϴ�."<<endl<<endl;
 }
 
 void ShowAllAccInfo()
 {
 	for(int i=0; i<accNum; i++)
 	{
 		cout<<"����ID: "<<accArr[i].accID<<endl;
 		cout<<"�� ��: "<<accArr[i].cusName<<endl;
 		cout<<"�� ��: "<<accArr[i].Balance<<endl<<endl;
	 }
 }
