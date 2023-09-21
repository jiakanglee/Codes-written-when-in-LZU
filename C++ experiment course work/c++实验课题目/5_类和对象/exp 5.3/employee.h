#pragma once
#include<string>
#include<string.h>
#include <iostream>
using namespace std;
class Date {
public:
	/*Date(int y = 1900, int m = 1, int d = 1) {//带默认参数的构造函数
		year = y;
		month = m;
		day = d;
	}*/
	Date();
	Date(int y0, int m0, int d0);
	//Date();//缺失构造函数
	friend class employee;
	void Show();
	void SetYear(int y) {
		year = y;
	}
	void SetMonth(int m) {
		month = m;
	}
	void SetDay(int d) {
		day = d;
	}

	int GetYear() {
		return year;
	}
	int GetMonth() {
		return month;
	}
	int GetDay() {
		return day;
	}
private:
	int year;
	int month;
	int day;
};
class employee {
public:
	employee();//缺省构造函数
	employee(string n, string nam, char s, Date  bir, string pos);//带参数构造函数，这里Date是引用&
	//employee(int ,string ,char,Data&,string="worker"); 

	void SetInfo(string n, string nam, string s, int year, int month, int day, string pos);
	friend class Date;
	void Show();
	string GetNum() { return num; }
	string GetName() { return name; }
	void SearchNum(string, employee*, int);
	void SearchName(string, employee*, int);

private:
	string num;
	string name;
	string sex;
	Date birthday;
	string position;

};