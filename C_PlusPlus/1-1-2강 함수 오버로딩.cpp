#include <iostream>

//�Ű����� �ڷ��� �Ǵ� ������ �޶����  
int myfun(int num)
{
	return num + 1;
}

int myfun(char str)
{
	return str;
}

int myfun(int num1, int num2)
{
	return num1 + num2;
}

int main112()
{
	int num;
	char str = 'A';

	std::cout << "���Է�";
	std::cin >> num;

	std::cout << myfun(num) << std::endl;
	std::cout << myfun(str) << std::endl;
	std::cout << myfun(num, num);
	return 0;
}