#include "Printer.h"

void Printer::SetString(const char *str)
{
	this->str = str;
}

void Printer::ShowString()
{
	cout << str << endl;
}