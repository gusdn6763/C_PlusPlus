#include "Util.h"
#include "2-4-5강 OOP프로젝트 2단계.h"

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
		account = new unordered_map<string, Account>;
		cout << "계좌는 최대 1개까지 생성할 수 있습니다." << endl;
		if (account->empty() == 0)
		{
			cout << currentPeople->name << "은(는) 현재 계좌가 없습니다. 만드시겠습니까?" << endl;
		}
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
		cout << "무엇을 하시겠습니까?" << endl;
		cout << str << endl;
	}

	string GetName()
	{
		string name;
		cout << "이름입력 : ";
		cin >> name;
		return	name;
	}

	People* MakePeople()
	{
		system("cls");
		cout << "캐릭터 이름을 입력해주세요" << endl << endl;

		People* people = new People(GetName());
		cout << "캐릭터 생성완료 !" << endl;
		Sleep(1000);
		system("cls");
		return people;
	}

	void StartSimulate()
	{
		cout << "현우의 임시 시뮬레이터" << endl << endl;
		Sleep(500);
		cout << "캐릭터를 만들어야 합니다!!" << endl;
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
			ShowChooseNum("1.은행가기  2.일하기  3.캐릭터 선택창");
			cin >> num;
			if (num == 1)
			{
				ShowChooseNum("1. 계좌개설 2.입금 3.출금 4.계좌 정보 5.나가기");
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