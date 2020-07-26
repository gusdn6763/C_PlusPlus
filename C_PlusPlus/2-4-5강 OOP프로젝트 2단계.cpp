#include "Util.h"
#include "2-4-5�� OOP������Ʈ 2�ܰ�.h"

#define True 1
#define False 0

namespace Simulate
{
	void	People::GetInBank(Bank *bank)
	{
		int num;

		while (1)
		{
			cin >> num;

			if (num == 1)
				bank->MakeAccount(this);
			else if (num == 2)
				currentMoney -= bank->AddMoney(this);
			else if (num == 3)
				currentMoney += bank->MinusMoney(this);
			else if (num == 4)
				bank->ShowInfo(this);
			else if (num == 5)
				return ;
		}
	}

	void	Bank::MakeAccount(People *currentPeople)
	{
		cout << "���´� �ִ� 1������ ������ �� �ֽ��ϴ�." << endl;
		if (account->count(currentPeople->name) == 0)
		{
			cout << currentPeople->name << "��(��) ���� ���°� �����ϴ�. ����ðڽ��ϱ�?" << endl;
		}
		account = new map<string, Account>;
	}

	void	Bank::ShowInfo(People *currentPeople)
	{

	}

	int		Bank::AddMoney(People *currentPeople)
	{
		return 1;
	}

	int		Bank::MinusMoney(People *currentPeople)
	{
		return 1;
	}

	void	ShowChooseNum(const char* str)
	{
		cout << "������ �Ͻðڽ��ϱ�?" << endl;
		cout << str << endl;
	}

	string GetName()
	{
		string name;
		cout << "�̸��Է� : ";
		cin >> name;
		return	name;
	}

	People* MakePeople()
	{
		system("cls");
		cout << "ĳ���� �̸��� �Է����ּ���" << endl << endl;

		People* people = new People(GetName());
		cout << "ĳ���� �����Ϸ� !" << endl;
		Sleep(1000);
		system("cls");
		return people;
	}

	void StartSimulate()
	{
		cout << "������ �ӽ� �ùķ�����" << endl << endl;
		Sleep(500);
		cout << "ĳ���͸� ������ �մϴ�!!" << endl;
		Sleep(500);
	}

	int main245()
	{
		int num;
		Bank *bank = new Bank;

		StartSimulate();
		People* currentPeople = MakePeople();
		while (1)
		{
			ShowChooseNum("1.���డ��  2.���ϱ�  3.ĳ���� ����â");
			cin >> num;
			if (num == 1)
			{
				ShowChooseNum("1. ���°��� 2.�Ա� 3.��� 4.���� ���� 5.������");
				currentPeople->GetInBank(bank);
			}
			else if (num == 2)
			{

			}
			else if (num == 3)
			{

			}
		}
		return 0;
	}
}