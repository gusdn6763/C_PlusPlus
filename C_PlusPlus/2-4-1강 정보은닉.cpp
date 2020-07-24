#include "2-4-1강 정보은닉.h"


bool FruitSeller::InitMembers(int price, int num, int money)
{
	if ((price > 0 && price < 2000) && appleNum > 0 && currentMoney >= 0)
	{
		applePrice = price;
		appleNum = num;
		currentMoney = money;
		return true;
	}
	else
		return false;
};

int FruitSeller::SaleApples(int money)
{
	int num = money / applePrice;
	appleNum -= num;
	currentMoney += money;
	return num;
};

void FruitSeller::ShowSalesResult()	const
{
	cout << "남은 사과: " << appleNum << endl;
	cout << "판매 수익: " << currentMoney << endl << endl;
};

bool FruitBuyer::InitMembers(int money)
{
	if (money > 0)
	{
		currentMoney = money;
		appleNum = 0;
		return true;
	}
	else
		return false;
};

void FruitBuyer::BuyApples(FruitSeller& seller, int money)
{
	appleNum += seller.SaleApples(money);
	currentMoney -= money;
};

void FruitBuyer::ShowBuyResult()	const
{
	cout << "현재 잔액: " << currentMoney << endl;
	cout << "사과 개수: " << appleNum << endl << endl;
};

int main241(void)
{
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);

	buyer.BuyApples(seller, 2000);
	
	cout<<"과일 판매자의 현황"<<endl;
	seller.ShowSalesResult();
	cout<<"과일 구매자의 현황"<<endl;
	buyer.ShowBuyResult();
	return 0;
}
