// zad_4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
class Int {
	int value;//предпологаем, что наш Int для 32-битной системы
public:
	Int():value(0)
	{}
	Int(int v){
		if (overflowValue(v))
			value = v;
		else {
			cerr << "Переполнение!"; system("pause");
			exit(1);
		}
	}

	void display()const {
		cout << value << endl;
	}

	Int operator + (Int);
	Int operator - (Int);
	Int operator * (Int);
	Int operator / (Int);
	bool overflowChecking(Int v1) {
		long double variable = value;
		if (((variable + v1.value) > 2147483647) || ((variable * v1.value) > 2147483647))
			return false;
		else return true;
	}
	bool overflowValue(int v) {
		if (v > 2147483647)
			return false;
		else return true;
	}
};

Int Int::operator + (Int v) {
	if (!overflowChecking(v)) {
		cerr << "Переполнение!" << endl; system("pause"); exit(1);
	}
	else {
		value += v.value;
		return Int(value);
	}
}
Int Int::operator - (Int v) {
	if (!overflowChecking(v)) {
		cerr << "Переполнение!\n"; system("pause"); exit(1);
	}
	else {
		value -= v.value;
		return Int(value);
	}
}
Int Int::operator * (Int v) {
	if (!overflowChecking(v)) {
		cerr << "Переполнение!\n"; system("pause"); exit(1);
	}
	else {
		value *= v.value;
		return Int(value);
	}
}
Int Int::operator / (Int v) {
		value /= v.value;
		return Int(value);
}
int main()
{
	setlocale(LC_ALL, "rus");
	Int iValue1 = 2147483646;
	Int iValue2 = 1;
	Int iValue3;
	
//	iValue3 = iValue1 + iValue2;
//	iValue3.display();
//	iValue3 = iValue1 - iValue2;
//	iValue3.display();
//	iValue3 = iValue1 * iValue2;
//	iValue3.display();
	iValue3 = iValue1 / iValue2;
	iValue3.display();

	system("pause");
    return 0;
}


