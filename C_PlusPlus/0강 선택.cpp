#include "0�� ����.h"

int main()
{
	int part, chapter, chapter_num;

	cout << "1.C++���� ��ȯ" << endl;
	cout << "2.��ü������ ����" << endl;
	cout << endl << "��Ʈ ���� : ";
	cin >> part;
	system("cls");
	if (part == 1)
	{
		cout << "é��1 : C ��� ����� C++" << endl;
		cout << "é��2 : C ��� ����� C++" << endl;
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
			{
				main116();
			}
				
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
