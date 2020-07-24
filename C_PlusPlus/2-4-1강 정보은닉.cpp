#include "2-4-1�� ��������.h"


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
	cout << "���� ���: " << appleNum << endl;
	cout << "�Ǹ� ����: " << currentMoney << endl << endl;
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
	cout << "���� �ܾ�: " << currentMoney << endl;
	cout << "��� ����: " << appleNum << endl << endl;
};

int main241(void)
{
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);

	buyer.BuyApples(seller, 2000);
	
	cout<<"���� �Ǹ����� ��Ȳ"<<endl;
	seller.ShowSalesResult();
	cout<<"���� �������� ��Ȳ"<<endl;
	buyer.ShowBuyResult();
	return 0;
}
