#include "Time.h"
#include <iostream>
using namespace std;
Ctime::Ctime()
	{
		hour = minute = second = 0;
	}
Ctime::Ctime(int h, int m, int s) {
		hour = h;
		minute = m;
		second = s;
	}
Ctime Ctime::pp() {
		second++;
		if (second >= 60) {
			second = 0;
			minute++;
		}
		if (minute >= 60) {
			minute = 0;
			hour++;
		}
		if (hour >= 24)hour = 0;
		return *this;
	}
	//����ǰ��������������������Ҫ��������� operator++(int)
void Ctime::Display() {
	cout << hour << ':' << minute << ':' << second << endl;
}
void Ctime::SetHour(int h) {
	hour = h;
};
void Ctime::SetMinute(int m) {
	minute = m;
};
void Ctime::SetSecond(int s) {
	second = s;
};