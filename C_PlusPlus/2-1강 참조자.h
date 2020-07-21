#pragma once

int main21()
{
	int num1 = 1;
	int& num2 = num1;

	cout << num1 << endl;
	cout << num2 << endl;

	cout << &num1 << endl;
	cout << &num2 << endl;
	return 0;
}