#include "0�� ����.h"
#include "2-4-5�� OOP������Ʈ 2�ܰ�.h"

using namespace Simulate;

int main()
{
	int part, chapter, chapter_num;

	cout << "1.c++���� ��ȯ" << endl;
	cout << "2.��ü������ ����" << endl;
	cout << endl << "��Ʈ ���� : ";
	cin >> part;
	system("cls");

	if (part == 1)
	{
		cout << "é��1 : c ��� ����� c++" << endl;
		cout << "é��2 : c ��� ����� c++" << endl;
		cout << endl << "é�� ���� : ";
		cin >> chapter;
		system("cls");
		if (chapter == 1)
		{
			system("cls");
			cout << "1. printf�� scanf�� ����ϴ� ����� ���" << endl;
			cout << "2. �Լ� �����ε�" << endl;
			cout << "3. �Ű����� ������ ��" << endl;
			cout << "4. �ζ��� �Լ�" << endl;
			cout << "5. �̸������� using" << endl;
			cout << "6. oop������Ʈ" << endl;
			cout << endl << "é�� ���뼱��";
			cin >> chapter_num;
			if (chapter_num == 1)
				main111();
			else if (chapter_num == 2)
				main112();
			else if (chapter_num == 3)
				main113();
			else if (chapter_num == 4)
				main114();
			else if (chapter_num == 5)
				main115();
			else if (chapter_num == 6)
				main116();		
		}
		else if(chapter == 2)
		{
			system("cls");
			cout << "1-2-1�� bool�ڷ���" << endl;
			cout << "1-2-2�� �������� ����" << endl;
			cout << "1-2-3�� �����ڿ� �Լ�" << endl;
			cout << "1-2-4�� new �� delete" << endl;
			cout << "1-2-5�� c++���� cȣ���ϱ�" << endl;
			cout << endl << "é�� ���뼱��";
			cin >> chapter_num;
			if (chapter_num == 1)
				main121();
			else if (chapter_num == 2)
				main122();
			else if (chapter_num == 3)
				main123();
			else if (chapter_num == 4)
				main124();
			else if (chapter_num == 5)
				main125();
		}
	}
	else if (part == 2)
	{
		cout << "é��3 : Ŭ������ �⺻" << endl;
		cout << "é��4 : Ŭ������ �ϼ�" << endl;
		cout << "é��5 : ���� ������" << endl;
		cout << "é��6 : friend�� static �׸��� const" << endl;
		cout << endl << "é�� ���� : ";
		cin >> chapter;
		system("cls");
		if (chapter == 3)
		{
			system("cls");
			cout << "1. c++������ ����ü" << endl;
			cout << "2. Ŭ������ ��ü" << endl;
			cout << "3 .��ü���� ���α׷����� ����" << endl;
			cout << "4. ����" << endl;
			cout << endl << "é�� ���뼱��";
			cin >> chapter_num;
			if (chapter_num == 1)
				main231();
			else if (chapter_num == 2)
				main232();
			else if (chapter_num == 3)
				main233();
			else if (chapter_num == 4)
				exam01();
		}
		else if (chapter == 4)
		{
			system("cls");
			cout << "1. ��������" << endl;
			cout << "2. ĸ��ȭ" << endl;
			cout << "3 .�����ڿ� �Ҹ���" << endl;
			cout << "4. Ŭ������ �迭 �׸��� this ������" << endl;
			cout << "5. oop������Ʈ 2�ܰ�" << endl;
			cout << endl << "é�� ���뼱��";
			cin >> chapter_num;
			if (chapter_num == 1)
				main241();
			if (chapter_num == 2)
				main242();
			if (chapter_num == 3)
				main243();
			if (chapter_num == 4)
				main244();
			if (chapter_num == 5)
				Simulate::main245();
		}
		else if (chapter == 5)
		{
			system("cls");
			cout << "1. ���� ������" << endl;
			cout << "2. ���� ���� �����ڿ� �A�� ���� ������" << endl;
			cout << "3 .���� �������� ȣ�����" << endl;
			cout << endl << "é�� ���뼱��";
			cin >> chapter_num;
			if (chapter_num == 1)
				main251();
			if (chapter_num == 2)
				main252();
			if (chapter_num == 3)
				main253();
		}
		else if (chapter == 6)
		{
			system("cls");
			cout << "1. const�� �߰�����" << endl;
			cout << "2. Ŭ������ �Լ��� ���� friend ����" << endl;
			cout << "3 .C++������ static" << endl;
			cout << endl << "é�� ���뼱��";
			cin >> chapter_num;
			if (chapter_num == 1)
				main261();
			if (chapter_num == 2)
				main262();
			if (chapter_num == 3)
				main263();
		}
	}
}

// ���α׷� ����: <Ctrl+F5> �Ǵ� [�����] > [��������� �ʰ� ����] �޴�
// ���α׷� �����: <F5> Ű �Ǵ� [�����] > [����� ����] �޴�

// ������ ���� ��: 
//   1. [�ַ�� Ž����] â�� ����Ͽ� ������ �߰�/�����մϴ�.
//   2. [�� Ž����] â�� ����Ͽ� �ҽ� ��� �����մϴ�.
//   3. [���] â�� ����Ͽ� ���� ��� �� ��Ÿ �޽����� Ȯ���մϴ�.
//   4. [���� ���] â�� ����Ͽ� ������ ���ϴ�.
//   5. [������Ʈ] > [�� �׸� �߰�]�� �̵��Ͽ� �� �ڵ� ������ ����ų�, [������Ʈ] > [���� �׸� �߰�]�� �̵��Ͽ� ���� �ڵ� ������ ������Ʈ�� �߰��մϴ�.
//   6. ���߿� �� ������Ʈ�� �ٽ� ������ [����] > [����] > [������Ʈ]�� �̵��ϰ� .sln ������ �����մϴ�.
