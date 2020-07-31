#include <iostream>
#include <cstring>
using namespace std;

class DeepCopyConstructorExample2
{
	int num;
public:
	DeepCopyConstructorExample2(int n) : num(n)
	{
		cout<<"num="<<num<<", ";
		cout<<"address="<<this<<endl;
	}

	void ShowSimpleData()
	{
		cout<<num<<endl;
	}

	DeepCopyConstructorExample2 * GetThisPointer()
	{
		return this;
	}
};

int main244(void)
{
	DeepCopyConstructorExample2 sim1(100);
	DeepCopyConstructorExample2 * ptr1=sim1.GetThisPointer();
	cout<<ptr1<<", ";
	ptr1->ShowSimpleData();

	DeepCopyConstructorExample2 sim2(200);
	DeepCopyConstructorExample2 * ptr2=sim2.GetThisPointer();
	cout<<ptr2<<", ";
	ptr2->ShowSimpleData();
	return 0;
}