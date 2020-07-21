#include <iostream>
#include <windows.h>
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
			money = getNumber("\n�ݾ� �ٽ��Է�:");
	return money;
}

void MakeBank(int i)
{
	cout << "\n[���°���]" << endl;
	people[i].id = getNumber("����ID:");
	cout << "�̸�";
	cin >> people[i].name;
	people[i].money = CheckMoney(getNumber("�Աݾ� : "));
}

void AddMoney()
{
	int id;
	cout << "[�Ա�]" << endl;
	id = getNumber("����ID : ");
	for (int i = 0; i < 100; i++)
		if (id == people[i].id)
		{
			people[i].money += CheckMoney(getNumber("�Աݾ� : "));
			break ;
		}
		cout << "���� �����Դϴ�" << endl;
		Sleep(1000);
}

void MinusMoney()
{
	int id,save;
	cout << "[���]" << endl;
	id = getNumber("����ID : ");
	for (int i = 0; i < 100; i++)
		if (id == people[i].id)
		{
			save = CheckMoney(getNumber("��ݾ� : "));
			if (save > people[i].id)
				cout << "����Ϸ��� �ݾ��� �� �����ϴ�" << endl;
			else
				people[i].money -= save;
			cout << "�ܾ� : " << people[i].money;
			Sleep(1000);
			break;
		}
	cout << "���� �����Դϴ�" << endl;
	Sleep(1000);
}

void menu4()
{
	int c, save;
	cout << "��������\n" << "����ID:";
	cin >> c;
	for (int i = 0; i < 100; i++)
	{
		if (c == people[i].id)
		{
			cout << people[i].id << endl;
			cout << people[i].name <<endl;
			cout << people[i].money << endl;
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
		cout << "1. ���°���" << endl;
		cout << "2. �Ա�" << endl;
		cout << "3. ���" << endl;
		cout << "4. �������� ��ü ���" << endl;
		cout << "5. ���α׷�����" << endl;
		num = getNumber("���� : ");
		system("cls");
		if (num == 1)
			MakeBank(i++);
		else if (num == 2)
			AddMoney();
		else if (num == 3)
			MinusMoney();
		else if (num == 4)
			menu4();
		else if (num == 5)
			break;
		num = 0;
	}
	return 0;
}