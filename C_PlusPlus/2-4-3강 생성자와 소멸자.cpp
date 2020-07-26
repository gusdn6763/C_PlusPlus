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
	Pos pos;
public:
	SimpleClass(int x , int y, int n = 0)		//������
		:pos(x, y)								//��� �̴ϼȶ����� ->pos�� ������� ������
	{
		pos.AddPos(n);
	}

	void ShowNum()
	{
		pos.ShowPos();
	}
	~SimpleClass()
	{
		cout << "����!" << endl;
	}
};

int main243()
{
	SimpleClass simpleClass(5, 5);

	simpleClass.ShowNum();

	return 0;
}

