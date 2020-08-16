/*
 * Banking System Ver 0.1
 * 작성자: 김호성
 * 내 용: OOP 단계별 프로젝트의 기본 틀 구성
 * 필요한 것: 1. 예외처리(자료형에 맞지 않은 형식이 들어오지 않게 해야함.)
 * enum: 열거형 데이터들을 상수처럼 쓰게 할 수 있다.(번호를 몇 개 지정하면, 알아서 적절한 번호를 넣어준다.) 
 */
 
 #include <iostream>
 #include <cstring>
 
 using namespace std;
 const int NAME_LEN=20;
 	
 void ShowMenu();		//메뉴출력 
 void MakeAccount();	//계좌개설을 위한 함수 
 void DepositMoney();	//입 금 
 void WithdrawMoney();	//출 금 
 void ShowAllAccInfo(); //잔액 조회
 
 enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};
 
 typedef struct{
 	int accID;				//계좌번호 
 	int Balance;			//잔액 
 	char cusName[NAME_LEN];	//사용자 이름 
 } Account;
 
 Account accArr[100];
 int accNum=0;
 
 int main()
 {
 	int choice;
 	
 	while(1)
 	{
 		ShowMenu();
 		cout<<"선택: ";
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
				cout<<"다시 선택해주세요.."<<endl; 
		 } 
	 }
	 return 0;
 }
 
 void ShowMenu()
 {
 	cout<<"------Menu------"<<endl;
	cout<<"1. 계좌개설"<<endl;
	cout<<"2. 입 금"<<endl;
	cout<<"3. 출 금"<<endl;
	cout<<"4. 계좌정보 전체 출력"<<endl;
	cout<<"5. 프로그램 종료"<<endl;	
	cout<<"----------------"<<endl; 
 }
 
 void MakeAccount()
 {
 	int id;
 	char name[NAME_LEN];
 	int balance;
 	
 	cout<<"[계좌개설]"<<endl;
 	cout<<"계좌번호: "; cin>>id; cin.clear();
 	cout<<"이 름: "; cin>>name; cin.clear();
 	cout<<"입금액: "; cin>>balance;	cin.clear();
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
	cout<<"[입  금]"<<endl;
	cout<<"계좌ID: "; cin>>id; cin.clear();
	cout<<"입금액: "; cin>>money; cin.clear();
	
	for(int i=0; i<accNum; i++)
	{
		if(accArr[i].accID==id){
			accArr[i].Balance+=money;
			return;
		}
	 }
	 cout<<"유효하지 않은 ID 입니다."<<endl<<endl;
 }
 
 void WithdrawMoney()
 {
 	int money;
 	int id;
 	cout<<"[출  금]"<<endl;
	cout<<"계좌ID: "; cin>>id; cin.clear();
	cout<<"출금액: "; cin>>money; cin.clear();
	
	for(int i=0; i<accNum; i++)
	{
		if(accArr[i].accID=id)
		{
			if(accArr[i].Balance<money){
				cout<<"잔액부족"<<endl<<endl;
				return; 
			}
			
			accArr[i].Balance-=money;
			cout<<"출금완료"<<endl<<endl;
			return;
		}
	 } 
	 cout<<"유효하지 않은 ID 입니다."<<endl<<endl;
 }
 
 void ShowAllAccInfo()
 {
 	for(int i=0; i<accNum; i++)
 	{
 		cout<<"계좌ID: "<<accArr[i].accID<<endl;
 		cout<<"이 름: "<<accArr[i].cusName<<endl;
 		cout<<"잔 액: "<<accArr[i].Balance<<endl<<endl;
	 }
 }
