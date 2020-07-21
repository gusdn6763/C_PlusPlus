#pragma once


void swap(int num1, int num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

int *adder(int* str)
{
	return str + 1;
}

void reswap(int& abc, int& def)
{
	int temp = abc;
	abc = def;
	def = temp;
}
int main22()
{
	int num1 = 10;
	int num2 = 20;

	swap(num1,num2);    //call-by-value
	cout << num1 <<endl<< num2 << endl;

	adder(&num1);  //call-by-value   //외부에 선언된 변수에 접근하는것이 아닌 주소값을 증가시킴

	reswap(num1, num2);   //call-by-reference   참조자를 이용
	cout << num1 << endl << num2 << endl;

	int& refer();


	return 0;

}

