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
	//����ǰ��������������������Ҫ��������� operator++(int)
	Ctime operator ++() //ǰ��������
	{
		return pp();
	}
	Ctime operator ++(int)//����������
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