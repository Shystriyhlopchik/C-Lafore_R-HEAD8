// zad_6.cpp: определяет точку входа для консольного приложения.
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
	Time() :hour(0), minute(0), second(0)
	{}

	Time(int h, int m, int s) :hour(h), minute(m), second(s)
	{}

	void display() const
	{
		cout << hour << ':' << minute << ':' << second;
	}

	Time operator + (Time);
	Time operator - (Time);
	Time operator ++ ();
	Time operator ++ (int);
	Time operator -- ();
	Time operator -- (int);
};

Time Time::operator + (Time t2) {
	int totalTimeSecond = 0;
	totalTimeSecond = second + t2.second;
	totalTimeSecond += (minute + t2.minute) * 60;
	totalTimeSecond += (hour + t2.hour) * 3600;
	totalTimeSecond %= 86400;

	hour = totalTimeSecond / 3600;
	minute = (totalTimeSecond - (hour * 3600)) / 60;
	second = totalTimeSecond - (hour * 3600) - (minute * 60);
	return Time(hour, minute, second);
}
Time Time::operator - (Time t2) {
	second -= t2.second;
	if (second < 0) {
		minute--;
		second += 60;
		if (minute < 0) {
			hour--;
			minute += 60;
			if (hour < 0)
				hour += 24;
		}
	}
	minute -= t2.minute;
	if (minute < 0) {
		hour--;
		minute += 60;
		if (hour < 0)
			hour += 24;
	}
	hour -= t2.hour;
	if (hour < 0)
		hour += 24;

	return Time(hour, minute, second);
}
Time Time::operator ++() {
	second++;
	if (second == 60) {
		minute++;
		second = 0;
		if (minute == 60) {
			hour++;
			minute = 0;
			if (hour == 24)
				hour = 0;
		}
	}
	return Time(hour, minute, second);
}
Time Time::operator ++ (int) {
	++second;
	if (second == 60) {
		minute++;
		second = 0;
		if (minute == 60) {
			hour++;
			minute = 0;
			if (hour == 24)
				hour = 0;
		}
	}
	return Time(hour, minute, second);
}
Time Time::operator --() {
	second--;
	if (second < 0) {
		minute--;
		second = 59;
		if (minute < 0) {
			hour--;
			minute = 59;
			if (hour < 0)
				hour = 23;
		}
	}
	return Time(hour, minute, second);
}
Time Time::operator --(int) {
	second--;
	if (second < 0) {
		--minute;
		second = 59;
		if (minute < 0) {
			hour--;
			minute = 59;
			if (hour < 0)
				hour = 23;
		}
	}
	return Time(hour, minute, second);
}

int main()
{
	setlocale(LC_ALL, "RUS");
	Time time1(1, 1, 1);
	Time time2(2, 2, 2);
	Time time3;

	time3 = time1-time2;

	time3.display(); cout << endl;
	system("pause");
	return 0;
}

