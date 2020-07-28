#include "Util.h"
#include "2-4-5�� OOP������Ʈ 2�ܰ�.h"

#define True 1
#define False 0

namespace Simulate
{
	void	People::GetInBank(Bank *bank)
	{
		int num;

		system("cls");
		while (1)
		{
			ShowChooseNum("1. ���°��� 2.�Ա� 3.��� 4.���� ���� 5.������");
			cin >> num;

			if (num == 1)
				bank->MakeAccount(this);
			else if (num == 2)
				bank->DepositAndWithdrawal(this, true, currentMoney);
			else if (num == 3)
				bank->DepositAndWithdrawal(this, false, currentMoney);
			else if (num == 4)
				bank->ShowInfo(this);
			else if (num == 5)
				break ;
			else if (cin.fail())
			{
				cin.clear();
				cin.ignore(256, '\n');
			}
			Sleep(1000);
			system("cls");
		}
	}

	void	People::Working()
	{
		cout << "���� + 100��" << endl;
		currentMoney += 100;
		Sleep(100);
	}

	void	People::ShowMyInfo()
	{
		cout << "���� �� : " << endl;
		cout << currentMoney << endl;
		Sleep(1000);
	}

	int		Bank::CheckMoney(int money)
	{
		if (money < 0)
			while (money < 0)
				money = getNumber("\n�ݾ� �ٽ��Է�:");
		return money;
	}

	bool	Bank::FindAccount(People *currentPeople)
	{
		unordered_map<string, Account>::iterator *tmp = new unordered_map<string, Account>::iterator;
		
		*tmp = account->find(currentPeople->name);

		if (*tmp != account->end())
			return true;
		else
			return false;
	}

	void	Bank::MakeAccount(People *currentPeople)
	{
		if (!(FindAccount(currentPeople)))
		{
			Account peopleAccount;
			string  password;
			std::random_device rd;				 // �õ尪�� ��� ���� random_device ����.
			std::mt19937 gen(rd());				// random_device �� ���� ���� ���� ������ �ʱ�ȭ �Ѵ�.
			std::uniform_int_distribution<int> dis(1, 10000);	 // �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ� ���� ����.

			cout << currentPeople->name << " ���� ���� ���°� �����ϴ�." << endl;
			cout << "������ ��й�ȣ�� �Է����ּ���" << endl;
			cin >> password;
			peopleAccount.password = password;
			peopleAccount.Money = 0;	
			peopleAccount.id = dis(gen);
			account->insert(pair<string, Account>(currentPeople->name, peopleAccount));
			cout <<  "�輳 �Ϸ�!!" << endl;
		}
		else
			cout << "���� ���°� �ֽ��ϴ�! �������� ���¸� ����°��� ������ ���� �����Դϴ�." << endl;
	}

	bool	Bank::CheckPassword(People* currentPeople)
	{
		string password;

		cout << "��й�ȣ�� �Է����ּ���" << endl;
		cin >> password;
		if (account->find(currentPeople->name)->second.password == password)
			return true;
		else
			return false;
	}

	int		Bank::DepositAndWithdrawal(People* currentPeople, bool moneyComp, int &money)
	{
		if (FindAccount(currentPeople))
		{
			int tmpMoney;
			unordered_map<string, Account>::iterator *tmp = new unordered_map<string, Account>::iterator;

			*tmp = account->find(currentPeople->name);
			if (CheckPassword(currentPeople))
			{
				cout << "���� �� : " << endl;
				cout << (*tmp)->second.Money << endl;
				if (moneyComp)
				{
					if (money < (tmpMoney = CheckMoney(getNumber("�󸶸� �Ա��Ͻðڽ��ϱ�?"))))
						cout << "���� �����մϴ�." << endl;
					else
					{
						(*tmp)->second.Money += tmpMoney;
						money -= tmpMoney;
					}
				}
				else if(!moneyComp)
				{
					if ((*tmp)->second.Money < (tmpMoney = CheckMoney(getNumber("�󸶸� ����Ͻðڽ��ϱ�?"))))
						cout << "���� ���� �����մϴ�." << endl;
					else
					{
						(*tmp)->second.Money -= tmpMoney;
						money += tmpMoney;
					}
				}
				return (tmpMoney);
			}
			else
				cout << "��й�ȣ ����" << endl;
		}
		else
			cout << "���°� �����ϴ�" << endl;
		return (0);
	}

	void	Bank::ShowInfo(People *currentPeople)
	{
		if (FindAccount(currentPeople))
			if (CheckPassword(currentPeople))
			{
				Account myAccount = account->find(currentPeople->name)->second;

				cout << "���̵� : " << myAccount.id << endl;
				cout << "��й�ȣ : " << myAccount.password << endl;
				cout << "���� �� : " << myAccount.Money << endl;
				Sleep(1000);
			}
			else
				cout << "��й�ȣ�� Ʋ���ϴ�.";
		else
			cout << "���°� �����ϴ�." << endl;
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
		Bank *bank = new Bank();

		StartSimulate();
		People* currentPeople = MakePeople();
		while (1)
		{
			ShowChooseNum("1.���డ��  2.���ϱ�  3. ���� ĳ���� �������� 4.ĳ���� ����â");
			cin >> num;
			if (num == 1)
				currentPeople->GetInBank(bank);
			else if (num == 2)
				currentPeople->Working();
			else if (num == 3)
				currentPeople->ShowMyInfo();
			else if (cin.fail())
			{
				cin.clear(); // ������Ʈ���� �ʱ�ȭ
				cin.ignore(256, '\n'); // �Է¹��۸� ���
			}
			system("cls");
		}
		return 0;
	}
}