// zad_2.cpp: определяет точку входа для консольного приложения.
//strplus.cpp
//перешрузка операции =+

#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

using namespace std;

class String
{
private:
	enum { SZ = 80 };
	char str[SZ];
public:
	String()
	{ strcpy_s(str, "");}

	String(const char* s)
	{ strcpy_s(str, s);}

	void display() const
	{ cout << str;}

	String operator + (String ss) const
	{
		String temp;
		if (strlen(str) + strlen(ss.str) < SZ)
		{
			strcat_s(temp.str, _countof(temp.str), str);
			strcat_s(temp.str, _countof(temp.str), ss.str);
		}
		else
		{
			cout << "\nПереполнение!";
			exit(1);
		}
		return temp;
	}

	String operator += (String ss)
	{
		strcat_s(str, _countof(str), ss.str);
		return String (str);
	}
};
///////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL, "RUS");
	String s1("C Рождеством! ");
	String s2 = " C Новым годом!";
	String s3;

	//s1.display();
	//s2.display();
	//s3.display();

	//s3 = s1 + s2;
	s1 += s2;
	s3 = s1 += s2;

	s1.display(); cout << endl;
	s3.display(); cout << endl;
	cout << endl;

	cerr << "\n\nОтработал\n";
	system("pause");
    return 0;
}

