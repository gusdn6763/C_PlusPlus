#pragma once
bool trueone(int num)
{
	if (num > 0)
	{
		return true;
	}
	else
		return false;
}

int main2()
{
	bool a = false;
	bool b = true;
	cout<<trueone(b);
	return 0;
}