#include <iostream>

using namespace std;

class CopyConstructor
{
public:
	int num1;
	int num2;
	CopyConstructor(int n1, int n2) : num1(n1), num2(n2)
	{
	}
	explicit CopyConstructor(int n1) : num1(n1)		//������ ��ȯ�� �߻����� �ʴ´� == ����Ʈ �����ڸ� �������� �ʴ´�.
	{
	}

	void ShowInfo()
	{
		cout << num1 << endl << num2 << endl;
	}
};

class DeepCopyConstructor
{
	char* name;
	int age;
public:
	DeepCopyConstructor(const char* myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}
	DeepCopyConstructor(const DeepCopyConstructor& copy)
		: age(copy.age)
	{
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
	}
	void ShowPersonInfo() const
	{
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}
	~DeepCopyConstructor()
	{
		delete[]name;
		cout << "called destructor!" << endl;
	}
};

class DeepCopyConstructorExample2
{
private:
	int num;
public:
	DeepCopyConstructorExample2(int n) : num(n)
	{  }
	DeepCopyConstructorExample2(const DeepCopyConstructorExample2& copy) : num(copy.num)
	{
		cout << "Called SoSimple(const SoSimple& copy)" << endl;
	}
	void ShowData()
	{
		cout << "num: " << num << endl;
	}
};

void SimpleFuncObj2(DeepCopyConstructorExample2 ob)			
{
	ob.ShowData();
}

class DeepCopyConstructorExample3
{
private:
	int num;
public:
	DeepCopyConstructorExample3(int n) : num(n)
	{ }
	DeepCopyConstructorExample3(const DeepCopyConstructorExample3& copy) : num(copy.num)
	{
		cout << "Called SoSimple(const SoSimple& copy)" << endl;
	}
	DeepCopyConstructorExample3& AddNum(int n)
	{
		num += n;
		return *this;
	}
	void ShowData()
	{
		cout << "num: " << num << endl;
	}
};

DeepCopyConstructorExample3 SimpleFuncObj3(DeepCopyConstructorExample3 ob)
{
	cout << "return ����" << endl;
	return ob;					//2��° ���� ������ ���� -> �ӽð�ü�� ��������� ȣ��
}

class SoSimple {
private:
	int num;
public:
	SoSimple(int n) :num(n) {
		cout << "New Object: " << this << endl;
	}
	SoSimple(const SoSimple& copy) :num(copy.num) {
		cout << "New Copy obj: " << this << endl;
	}
	~SoSimple() {
		cout << "Destroy obj: " << this << endl;
	}
};

SoSimple SimpleFuncObj(SoSimple ob) {
	cout << "Param ADR: " << &ob << endl;
	return ob;
}

int main251(void)
{
	CopyConstructor copyConstructor1(1,2);
	CopyConstructor copyConstructor2(copyConstructor1);
	copyConstructor2.ShowInfo();

	CopyConstructor copyConstructor3 = { 1, 2 };
	CopyConstructor copyConstructor4 = copyConstructor3;
	copyConstructor4.ShowInfo();

	DeepCopyConstructor man1("Lee dong woo", 29);
	DeepCopyConstructor man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	DeepCopyConstructorExample2 obj1(7);
	cout << "�Լ�ȣ�� ��" << endl;
	SimpleFuncObj2(obj1);					//��ü obj�� ���ڷ� �����ϰ��ִ�. SimpleFuncObj�Լ��� �Ű����� ob�� obj�� ���޹����鼭 ��������ڰ� ����ȴ�
	cout << "�Լ�ȣ�� ��" << endl;

	DeepCopyConstructorExample3 obj2(7);
	SimpleFuncObj3(obj2).AddNum(5).AddNum(5).ShowData();		//�ӽ� ��ü�̱⶧���� obj ��ü�� �ٸ� ���� ������ �Ҹ��
	obj2.ShowData();
	
	SoSimple obj(7);
	SimpleFuncObj(obj);

	cout << endl;

	SoSimple tempRef = SimpleFuncObj(obj);
	cout << "Return Obj " << &tempRef << endl;


	return 0;
}

/*
SoSimple Ŭ���� ��°�
New Object: 002AFCCC		Sosimple obj ���� (SoSimple obj(7))  
New Copy obj: 002AFBB4		�Ű������� ��ü�� �����鼭 ��������� ���� (SoSimple SimpleFuncObj(SoSimple ob))  
Param ADR: 002AFBB4			SoSimple SimpleFuncObj(SoSimple ob) �Լ� ����  
New Copy obj: 002AFBE8		SoSimple SimpleFuncObj(SoSimple ob)�� ��ȯ�� �����ϸ鼭 �ӽ� ��ü ����  
Destroy obj: 002AFBB4		�Ű������� ���� ���� ������ �Ҹ�
Destroy obj: 002AFBE8		��ȯ������ ������ �ӽ� ��ü �Ҹ� 
							cout << endl;
New Copy obj: 002AFBB4		�Ű������� ��ü�� �����鼭 ��������� ���� (SoSimple SimpleFuncObj(SoSimple ob))  
Param ADR: 002AFBB4			SoSimple SimpleFuncObj(SoSimple ob) �Լ� ����  
New Copy obj: 002AFCC0		SoSimple SimpleFuncObj(SoSimple ob)�� ��ȯ�� �����ϸ鼭 �ӽ� ��ü ���� 
Destroy obj: 002AFBB4		�Ű������� ���� ���� ������ �Ҹ�
Return Obj 002AFCC0			&tempRef�� �ּҰ� ���� -> 002AFCC0 �ӽð�ü�� �ּҰ� -> ob�� ��ȯ�����Ƿ�
Destroy obj: 002AFCC0		SoSimple tempRef �Ҹ�
Destroy obj: 002AFCCC		SoSimple obj(7) �Ҹ�
*/