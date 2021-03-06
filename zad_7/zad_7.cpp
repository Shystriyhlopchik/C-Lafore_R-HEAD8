// zad_7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class fraction {
	int a;
	int b;
public:
	fraction(int v1, int v2):a(v1), b(v2) 
	{}
	fraction() :a(0), b(0)
	{}
	void set() {
		char slash='/';
		do{
			cin >> a >> slash >> b;
		} while (slash != '/');
	}
	void display() const {
		cout << "Результат: " << a << '/' << b << endl;
	}
	void lowterms(); 

	fraction operator + (fraction);
	fraction operator - (fraction);
	fraction operator * (fraction);
	fraction operator / (fraction);
	bool operator == (fraction);
	bool operator != (fraction);
};
//--------------------------------------------------------------
void fraction::lowterms() {
	long tnum, tden, temp, gcd;
	tnum = labs(a);
	tden = labs(b);
	if (tden == 0) {
		cout << "Недопустимый знаменатель!"; exit(1);
	}
	else if (tnum == 0) {
		a = 0; b = 1; return;
	}
	//нахождение наибольшего общего делителя
	while (tnum != 0) {
		if (tnum < tden) {
			temp = tnum; tnum = tden; tden = temp;
		}
		tnum -= tden;
	}
	gcd = tden;
	a /= gcd;
	b /= gcd;
}
fraction fraction :: operator + (fraction arg2) {
	a = a * arg2.b + b * arg2.a; 
	b = b * arg2.b;
	return fraction(a, b);
}
fraction fraction :: operator - (fraction arg2) {
	a = a * arg2.b - b * arg2.a; 
	b = b * arg2.b;
	return fraction(a, b);
}
fraction fraction :: operator * (fraction arg2) {
	a = a * arg2.a; 
	b = b * arg2.b;
	return fraction(a, b);
}
fraction fraction :: operator / (fraction arg2) {
	a = a * arg2.b; 
	b = b * arg2.a;
	return fraction(a, b);
}
bool fraction :: operator == (fraction arg2) {
	return (((double)a / b) == ((double)arg2.a / arg2.b)) ? true : false;
	if (((a == 0) && (b == 1)) || ((arg2.a == 0) && (arg2.b == 1))) {
		cerr << "Завершение работы."; system("pause"); exit(1);
	}
}
bool fraction :: operator != (fraction arg2) {
	if (((a == 0) && (b == 1)) || ((arg2.a == 0) && (arg2.b == 1))) {
		cerr << "Завершение работы."; system("pause"); exit(1);
	}
	return (((double)a / b) != ((double)arg2.a / arg2.b)) ? true : false;//необходимо применить С++11 защиту от сужения
}
///////////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL, "RUS");
		
	bool sooth = true;
	char continueComand;

	do{
		fraction fraction1;
		fraction fraction2;
	
		cout << "Введите первый аргумент ->"; fraction1.set();
		cout << "Введите второй аргумент ->"; fraction2.set();
		cout << (fraction1 != fraction2) << endl;

		cout << "Желаете продолжить (y/n)?"; cin >> continueComand;
	} while ((continueComand == 'y') ? true : false);
    return 0;
}


