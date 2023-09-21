#pragma once
#include<string>
#include<string.h>
#include <iostream>
using namespace std;
class Ctime {
public:
	Ctime();
	Ctime(int h, int m, int s);
	Ctime pp();
	//重载前自增运算符，如果后自增要变成这样： operator++(int)
	Ctime operator ++() //前置型自增
	{
		return pp();
	}
	Ctime operator ++(int)//后置型自增
	{
		Ctime p = *this;
		pp();
		return p;
	}
	void Display();
	void SetHour(int);
	void SetMinute(int);
	void SetSecond(int);
private:
	int hour, minute, second;

};