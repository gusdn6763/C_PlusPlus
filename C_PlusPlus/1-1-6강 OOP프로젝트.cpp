#include "Util.h"

using namespace std;

typedef struct bank
{
	int id;
	char name[10];
	int money;
}bank;

bank people[100];

int CheckMoney(int money)
{
	if (money < 0)
		while (money < 0)
			money = getNumber("\n금액 다시입력:");
	return money;
}

void MakeBank(int i)
{
	cout << "\n[계좌개설]" << endl;
	people[i].id = getNumber("계좌ID:");
	cout << "이름";
	cin >> people[i].name;
	people[i].money = CheckMoney(getNumber("입금액 : "));
}

void AddMoney()
{
	int id;
	cout << "[입금]" << endl;
	id = getNumber("계좌ID : ");
	for (int i = 0; i < 100; i++)
		if (id == people[i].id)
		{
			people[i].money += CheckMoney(getNumber("입금액 : "));
			break ;
		}
		cout << "없는 계좌입니다" << endl;
		Sleep(1000);
}

void MinusMoney()
{
	int id,save;
	cout << "[출금]" << endl;
	id = getNumber("계좌ID : ");
	for (int i = 0; i < 100; i++)
		if (id == people[i].id)
		{
			save = CheckMoney(getNumber("출금액 : "));
			if (save > people[i].id)
				cout << "출금하려는 금액이 더 많습니다" << endl;
			else
				people[i].money -= save;
			cout << "잔액 : " << people[i].money;
			Sleep(1000);
			break;
		}
	cout << "없는 계좌입니다" << endl;
	Sleep(1000);
}

void CheckInfo()
{
	int c;
	cout << "계좌정보\n" << "계좌ID:";
	cin >> c;
	for (int i = 0; i < 100; i++)
	{
		if (c == people[i].id)
		{
			cout << "계좌id : " << people[i].id << endl;
			cout << "계좌이름 : " <<people[i].name <<endl;
			cout << "계좌 돈 : "<<people[i].money << endl;
		}
	}
	cout << " " << endl;
}

int main116()
{
	int num, i = 0;
	while (1)
	{
		cout << "-----Menu------" << endl;
		cout << "1. 계좌개설" << endl;
		cout << "2. 입금" << endl;
		cout << "3. 출금" << endl;
		cout << "4. 계좌정보 전체 출력" << endl;
		cout << "5. 프로그램종료" << endl;
		num = getNumber("선택 : ");
		system("cls");
		if (num == 1)
			MakeBank(i++);
		else if (num == 2)
			AddMoney();
		else if (num == 3)
			MinusMoney();
		else if (num == 4)
			CheckInfo();
		else if (num == 5)
			break;
		num = 0;
	}
	return 0;
}