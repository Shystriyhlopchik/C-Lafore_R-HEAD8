// HEAD8.cpp: определяет точку входа для консольного приложения.
//engplusminus.cpp
//перегрузка операций + и - для сложения и вычитания переменных типа Distance

#include "stdafx.h"
#include <iostream>

using namespace std;

class Distance 
{
private:
	int feet;
	float inches;
public:
	Distance() :feet(0), inches(0.0)
	{}
	Distance(int ft, float in) :feet(ft), inches(in)
	{}
	void getdist()
	{
		cout << "\nВведите футы: "; cin >> feet;
		cout << "Введите дюймы: "; cin >> inches;
	}
	void showdist()
	{
		cout << feet << "\'-" << inches << '\"';
	}
	Distance operator + (Distance);
	Distance operator - (Distance);
};
Distance Distance::operator+(Distance d2)
{
	int f = feet + d2.feet;
	float i = inches + d2.inches;
	if (i >= 12.0)
	{
		i -= 12.0;
		f++;
	}
	return Distance(f, i);
}
Distance Distance :: operator-(Distance d2)
{
	int f;
	float i;
	if ((inches-d2.inches) < 0)
	{
		f=feet-1;
		i = (inches + 12) - d2.inches;
		f -= d2.feet;
	}
	else
	{
		f = feet - d2.feet;
		i = inches - d2.inches;
	}
	return Distance(f, i);
}
int main()
{
	setlocale(LC_ALL, "RUS");
	Distance dist1, dist3;
	dist1.getdist();

	Distance dist2(11, 6.25);

	dist3 = dist1 - dist2;

	cout << "dist1 = "; dist1.showdist(); cout << endl;
	cout << "dist2 = "; dist2.showdist(); cout << endl;
	cout << "dist3 = "; dist3.showdist(); cout << endl;
	system("pause");
    return 0;
}

