#pragma once

#include <cstring>
#include <unordered_map>

namespace Simulate2
{
	class Bank;
	class People;

	typedef struct Account
	{
		int			id = 0;
		int			Money = 0;
		string		password;
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
			cout << "ĳ���� ������";
		}
		string		name;
		void		GetInBank(Bank* bank);
		void		Working();
		void		ShowMyInfo();
	private:
		int			currentMoney;
	};

	class			Bank
	{
	public:
		void		MakeAccount(People* currentPeople);
		bool		FindAccount(People* currentPeople);
		int			CheckMoney(int money);
		int			DepositAndWithdrawal(People* currentPeople, bool moneyComp, int& money);
		bool		CheckPassword(People* currentPeople);
		void		ShowInfo(People* currentPeople);
	private:
		unordered_map<string, Account>* account = new unordered_map<string, Account>;
	};

	void	ShowChooseNum(const char* str);
	int		main375();
	string	GetName();
}