#pragma once

#include <iostream>

using namespace std;

class Printer
{
private:
	const char* str;
public:
	void SetString(const char *str);
	void ShowString();
};
