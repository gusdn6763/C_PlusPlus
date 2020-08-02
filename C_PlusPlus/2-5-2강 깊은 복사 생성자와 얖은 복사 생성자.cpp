#include <iostream>
#include "Util.h"

using namespace std;

class DeepCopyConstructor
{
	char* name;
	int age;
public:
	DeepCopyConstructor(const char* myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		ft_strcpy(name, myname);
		age = myage;
	}
	DeepCopyConstructor(const DeepCopyConstructor& copy)
		: age(copy.age)
	{
		name = new char[strlen(copy.name) + 1];
		ft_strcpy(name, copy.name);
	}
	void ShowPersonInfo() const
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~DeepCopyConstructor()
	{
		delete[]name;
		cout << "called destructor!" << endl;
	}
};

int	main252()
{
	DeepCopyConstructor man1("Lee dong woo", 29);
	DeepCopyConstructor man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	return (0);
}