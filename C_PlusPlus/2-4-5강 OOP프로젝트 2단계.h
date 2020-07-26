#pragma once

#include <cstring>
#include <map>

namespace Simulate
{
	class Bank;
	class People;

	typedef struct Account
	{
		int			Money;
	}				Account;

	class			People
	{
	public:
		People(string name, int money = 0) : currentMoney(money)
		{
			this->name = name;
		}
		~People()
		{
			cout << "캐릭터 삭제됨";
		}
		string		name;
		void		GetInBank(Bank *bank);
	private:
		int			currentMoney;
	};

	class			Bank
	{
	public:
		void		ShowInfo(People *currentPeople);
		int			AddMoney(People *currentPeople);
		int			MinusMoney(People *currentPeople);
		void		MakeAccount(People *currentPeople);
	private:
		map<string, Account> *account;
	};

	void	ShowChooseNum(const char* str);
	int		main245();
	string GetName();
}