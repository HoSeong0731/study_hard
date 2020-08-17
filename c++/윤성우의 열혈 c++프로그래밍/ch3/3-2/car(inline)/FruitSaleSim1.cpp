#include <iostream>
using namespace std;

class FruitSeller
{
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;
public:
	void InintMembers(int price, int num, int money)
	{
		APPLE_PRICE=price;
		numOfApples=num;
		myMoney=money;
	}
	int SaleApples(int money)
	{
		int num=money/APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}
	void ShowSalesResult()
	{
		cout<<"남은 사과: "<<numOfApples<<endl;
		cout<<"판매 수익: "<<myMoney<<endl<<endl;
	}
};

class FruitBuyer
{
	int myMoney;
	int numOfApples;
	
public:
	void InitMembers(int money)
	{
		myMoney=money;
		numOfApples=0;
	}
	void ShowBuyResult()
	{
		cout<<"현재 잔액: "<<myMoney<<endl;
		cout<<"사과 개수: "<<numOfApples<<endl<<endl; 
	}
	void BuyApples(FruitSeller &seller, int money)
	{
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}
};

int main()
{
	FruitSeller seller;
	seller.InintMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000);
	
	cout<<"과일 판매자의 현황"<<endl;
	seller.ShowSalesResult();
	cout<<"과일 구매자의 현황"<<endl;
	buyer.ShowBuyResult();
	return 0; 
}
