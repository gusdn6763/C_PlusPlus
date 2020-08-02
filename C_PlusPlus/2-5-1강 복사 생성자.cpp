#include <iostream>
#include "Util.h"

using namespace std;

class CopyConstructor
{
public:
	int num1;
	int num2;
	CopyConstructor(int n1, int n2) : num1(n1), num2(n2)
	{
	}
	explicit CopyConstructor(int n1) : num1(n1)	//묵시적 변환이 발생하지 않는다 == 디폴트 생성자를 생성하지 않는다.
	{
		num2 = 1;
	}

	void ShowInfo()
	{
		cout << num1 << endl << num2 << endl;
	}
};

int main251()
{
	CopyConstructor copyConstructor1(1,2);
	CopyConstructor copyConstructor2(copyConstructor1);
	copyConstructor2.ShowInfo();

	CopyConstructor copyConstructor3 = { 1, 2 };
	CopyConstructor copyConstructor4 = copyConstructor3;
	copyConstructor4.ShowInfo();

	return 0;
}