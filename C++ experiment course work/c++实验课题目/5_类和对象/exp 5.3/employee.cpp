#include "employee.h"
#include <iostream>
using namespace std;
employee::employee() {
	num = "2001";
}//缺省构造函数
employee::employee(string n, string nam, char s, Date  bir, string pos) {
	num = n;
	name = nam;
	sex = s;
	Date birthay = bir;
	position = pos;
}//带参数构造函数，这里Date是引用&
//employee(int ,string ,char,Data&,string="worker"); 

void employee::SetInfo(string n, string nam, string s, int year, int month, int day, string pos) {
	num = n;
	name = nam;
	sex = s;
	birthday.SetDay(day);
	birthday.SetMonth(month);
	birthday.SetYear(year);
	position = pos;
}void employee::Show() {
	cout << "number,name,sex,birthday,position依次为:" << endl;
	cout << "number:" << num << endl;
	cout << "name:" << name << endl;
	cout << "sex:" << sex << endl;
	birthday.Show();
	cout << "position:" << position << endl;

}
void employee::SearchNum(string num, employee* p, int n) {
	bool flag = 1;
	for (int i = 0; i < n; i++) {
		if (num == p[i].GetNum()) {
			cout << "所找的员工的信息为：" << endl;
			p[i].Show();
			flag = 0;
			break;
		}
	}
	if (flag)cout << "没有编号为" << num << "的员工，请确认编号输入是否正确！" << endl;

}
void employee::SearchName(string name, employee* p, int n) {
	bool flag = 1;
	for (int i = 0; i < n; i++) {
		if (name == p[i].GetName()) {
			cout << "所找的员工的信息为：" << endl;
			p[i].Show();
			flag = 0;
			break;
		}
	}
	if (flag)cout << "没有姓名为" << name << "的员工，请确认姓名输入是否正确！" << endl;

}

	/*Date(int y = 1900, int m = 1, int d = 1) {//带默认参数的构造函数
		year = y;
		month = m;
		day = d;
	}*/
	Date::Date() {
		year = 1;
		month = 1;
		day = 1;
	}
	Date::Date(int y0, int m0, int d0) {//全参数
		year = y0;
		month = m0;
		day = d0;
	}
	//Date();//缺失构造函数
	void Date::Show() {
		cout << "年，月，日分别为:" << endl;
		cout << "年:" << year << endl;
		cout << "月:" << month << endl;
		cout << "日:" << day << endl;
	}