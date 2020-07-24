#include "Calculator.h"

void Calculator::Init()
{
	add_count = 0;
	div_count = 0;
	min_count = 0;
	mul_count = 0;
}

void Calculator::ShowOpCount()
{
	cout << "µ¡¼À : " << add_count << endl;
	cout << "»¬¼À : " << min_count << endl;
	cout << "°ö¼À : " << mul_count << endl;
	cout << "³ª´°¼À : " << div_count << endl;
}

float Calculator::Add(float num1, float num2)
{
	add_count++;
	return num1 + num2;
}

float Calculator::Div(float num1, float num2)
{
	div_count++;
	return num1 / num2;
}

float Calculator::Min(float num1, float num2)
{
	min_count++;
	return num1 - num2;
}

float Calculator::Mul(float num1, float num2)
{
	mul_count++;
	return num1 * num2;
}