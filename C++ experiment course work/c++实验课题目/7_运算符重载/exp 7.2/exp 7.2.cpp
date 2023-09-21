#include<iostream>
#include"Time.h"
using namespace std;
int main() {
	Ctime t;
	t.SetHour(13);
	t.SetMinute(45);
	t.SetSecond(39);
	for (int i = 0; i < 120; i++) {
		++t;
	}
	t.Display();
	t.SetHour(23);
	t.SetMinute(58);
	t.SetSecond(5);
	for (int i = 0; i < 120; i++) {
		++t;
	}
	t.Display();
	t.SetHour(23);
	t.SetMinute(58);
	t.SetSecond(5);
	Ctime b;
	b = t.operator++(1);
	b.Display();
	t.Display();
	return 0;
}