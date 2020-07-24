#pragma once

#include <iostream>

using namespace std;

class FruitSeller
{
private:
	int applePrice;
	int appleNum;
	int currentMoney;
public:
	bool InitMembers(int price, int num, int money);
	int SaleApples(int money);
	void ShowSalesResult() const;
};

class FruitBuyer
{
private:
	int currentMoney;
	int appleNum;
public:
	bool InitMembers(int money);
	void BuyApples(FruitSeller& seller, int money);
	void ShowBuyResult() const;
};
