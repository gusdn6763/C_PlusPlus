#include "Calculator.h"
#include "Printer.h"
#include <iostream>

int Exam01()
{
	Calculator cal;
	Printer pnt;

	cal.Init();
	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5 - 1.7 = " << cal.Min(3.5, 1.7) << endl;
	cout << "2.2 * 1.5 = " << cal.Mul(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
	cal.ShowOpCount();

	pnt.SetString("Hello World");
	pnt.ShowString();

	pnt.SetString("I Love World");
	pnt.ShowString();
	return 0;
}