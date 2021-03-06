// zad_3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
class Time
{
private:
	int hour;
	int minute;
	int second;
public:
	Time():hour(0), minute(0), second(0)
	{}

	Time(int h, int m, int s) :hour(h), minute(m), second(s)
	{}

	void display() const
	{cout << hour << ':' << minute << ':' << second;}

	Time operator + (Time);
};

Time Time::operator + (Time t2) {
	int totalTimeSecond=0;
	totalTimeSecond = second + t2.second;
	totalTimeSecond += (minute + t2.minute)*60;
	totalTimeSecond += (hour + t2.hour)*3600;
	totalTimeSecond %= 86400;

	hour = totalTimeSecond / 3600;
	minute = (totalTimeSecond - (hour * 3600)) / 60;
	second = totalTimeSecond - (hour * 3600) - (minute * 60);
	return Time(hour, minute, second);
}
int main()
{
	setlocale(LC_ALL, "RUS");
	Time time1(12,59,59);
	const Time time2(12,1,1);
	Time time3;

	time3 = time1 + time2;

	time3.display(); cout << endl;
	system("pause");
    return 0;
}

