#include "2-3-3�� ��ü���� ���α׷����� ����.h"


void FruitSell::InitMembers(int price, int num, int money)
{
	applePrice = price;
	appleNum = num;
	currentMoney = money;
};

int FruitSell::SaleApples(int money)
{
	int num = money / applePrice;
	appleNum -= num;
	currentMoney += money;
	return num;
};

void FruitSell::ShowSalesResult()
{
	cout << "���� ���: " << appleNum << endl;
	cout << "�Ǹ� ����: " << currentMoney << endl << endl;
};

void FruitBuy::InitMembers(int money)
{
	currentMoney = money;
	appleNum = 0;
};
void FruitBuy::BuyApples(FruitSell& seller, int money)
{
	appleNum += seller.SaleApples(money);
	currentMoney -= money;
};

void FruitBuy::ShowBuyResult()
{
	cout << "���� �ܾ�: " << currentMoney << endl;
	cout << "��� ����: " << appleNum << endl << endl;
};

int main233(void)
{
	FruitSell seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuy buyer;
	buyer.InitMembers(5000);

	buyer.BuyApples(seller, 2000);
	
	cout<<"���� �Ǹ����� ��Ȳ"<<endl;
	seller.ShowSalesResult();
	cout<<"���� �������� ��Ȳ"<<endl;
	buyer.ShowBuyResult();
	return 0;
}
