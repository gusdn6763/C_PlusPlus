#include <iostream>

using namespace std;

class Pos
{
private:
	int xpos;
	int ypos;
public:
	Pos(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	void AddPos(int num)
	{
		xpos += num;
		ypos += num;
	}
	void ShowPos()
	{
		cout << xpos << endl << ypos << endl;
	}
};

class SimpleClass
{
private:
	int num;
	Pos pos;
public:
	SimpleClass(int x , int y, int n = 0)		//생성자
		:pos(x, y)								//멤버 이니셜라이저 ->pos의 멤버변수 넣을때
	{
		pos.AddPos(n);
	}

	void ShowNum()
	{
		pos.ShowPos();
	}
};

int main243()
{
	SimpleClass simpleClass(5, 5);

	simpleClass.ShowNum();

	return 0;
}

