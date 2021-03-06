// zad_9.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
const int LIMIT = 100;
/////////////////////////////////////////////////////
class safearray {
	int arr[LIMIT];
	unsigned short int indexMIN;
	unsigned short int indexMAX;
public:
	safearray(int MIN, int MAX) : indexMIN(MIN), indexMAX(MAX) 
	{}
	int& operator[] (int n) {
		if (n < indexMIN || n >= indexMAX) {
			cout << "\nОшибка индекса!"; system("pause"); exit(1);
		}
		if ((indexMAX - indexMIN) > 100) {
			cout << "\nОшибка!Размер массива не должен быть больше 100!"; system("pause"); exit(1);
		}

		return arr[n-indexMIN];
	}
};
/////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL, "RUS");
	const int MIN = 100;
	const int MAX = 175;
	safearray sa1(MIN, MAX);

	for (int j = 100; j < MAX; j++)
		sa1[j] = j * 10;
	
	for (int j = 100; j < MAX; j++) {
		int temp = sa1[j];
		cout << "Элемент " << j << " равен " << temp << endl;
	}
	system("pause");
    return 0;
}

