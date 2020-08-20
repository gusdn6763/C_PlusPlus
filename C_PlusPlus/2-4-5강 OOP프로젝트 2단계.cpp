#include "Util.h"
#include "2-4-5강 OOP프로젝트 2단계.h"

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
			ShowChooseNum("1. 계좌개설 2.입금 3.출금 4.계좌 정보 5.나가기");
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
		cout << "일함 + 100원" << endl;
		currentMoney += 100;
		Sleep(100);
	}

	void	People::ShowMyInfo()
	{
		cout << "현재 돈 : " << endl;
		cout << currentMoney << endl;
		Sleep(1000);
	}

	int		Bank::CheckMoney(int money)
	{
		if (money < 0)
			while (money < 0)
				money = getNumber("\n금액 다시입력:");
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
			std::random_device rd;				 // 시드값을 얻기 위한 random_device 생성.
			std::mt19937 gen(rd());				// random_device 를 통해 난수 생성 엔진을 초기화 한다.
			std::uniform_int_distribution<int> dis(1, 10000);	 // 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.

			cout << currentPeople->name << " 님은 현재 계좌가 없습니다." << endl;
			cout << "설정할 비밀번호를 입력해주세요" << endl;
			cin >> password;
			peopleAccount.password = password;
			peopleAccount.Money = 0;	
			peopleAccount.id = dis(gen);
			account->insert(pair<string, Account>(currentPeople->name, peopleAccount));
			cout <<  "계설 완료!!" << endl;
		}
		else
			cout << "현재 계좌가 있습니다! 여러개의 계좌를 만드는것은 언젠가 구현 예정입니다." << endl;
	}

	bool	Bank::CheckPassword(People* currentPeople)
	{
		string password;

		cout << "비밀번호를 입력해주세요" << endl;
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
				cout << "계좌 돈 : " << endl;
				cout << (*tmp)->second.Money << endl;
				if (moneyComp)
				{
					if (money < (tmpMoney = CheckMoney(getNumber("얼마를 입금하시겠습니까?"))))
						cout << "돈이 부족합니다." << endl;
					else
					{
						(*tmp)->second.Money += tmpMoney;
						money -= tmpMoney;
					}
				}
				else if(!moneyComp)
				{
					if ((*tmp)->second.Money < (tmpMoney = CheckMoney(getNumber("얼마를 출금하시겠습니까?"))))
						cout << "계좌 돈이 부족합니다." << endl;
					else
					{
						(*tmp)->second.Money -= tmpMoney;
						money += tmpMoney;
					}
				}
				return (tmpMoney);
			}
			else
				cout << "비밀번호 오류" << endl;
		}
		else
			cout << "계좌가 없습니다" << endl;
		return (0);
	}

	void	Bank::ShowInfo(People *currentPeople)
	{
		if (FindAccount(currentPeople))
			if (CheckPassword(currentPeople))
			{
				Account myAccount = account->find(currentPeople->name)->second;

				cout << "아이디 : " << myAccount.id << endl;
				cout << "비밀번호 : " << myAccount.password << endl;
				cout << "현재 돈 : " << myAccount.Money << endl;
				Sleep(1000);
			}
			else
				cout << "비밀번호가 틀립니다.";
		else
			cout << "계좌가 없습니다." << endl;
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
		Bank *bank = new Bank("국민");

		StartSimulate();
		People* currentPeople = MakePeople();
		while (1)
		{
			ShowChooseNum("1.은행가기  2.일하기  3. 현재 캐릭터 정보보기 4.캐릭터 선택창");
			cin >> num;
			if (num == 1)
				currentPeople->GetInBank(bank);
			else if (num == 2)
				currentPeople->Working();
			else if (num == 3)
				currentPeople->ShowMyInfo();
			else if (cin.fail())
			{
				cin.clear(); // 오류스트림을 초기화
				cin.ignore(256, '\n'); // 입력버퍼를 비움
			}
			system("cls");
		}
		return 0;
	}
}