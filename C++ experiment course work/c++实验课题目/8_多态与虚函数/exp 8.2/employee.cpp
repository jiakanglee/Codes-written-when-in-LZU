#include "employee.h"
#include <iostream>
using namespace std;
int mapping(string a) {
	if (a == "总经理")
		return 1;
	if (a == "销售员")
		return 2;
	if (a == "销售经理")
		return 3;
	if (a == "技术人员")
		return 4;
}
string ave_mapping(int a) {
	if (a == 1)
		return "总经理";
	if (a == 3)
		return "销售经理";
	if (a == 2)
		return "销售员";
	if (a == 4)
		return "技术人员";
}
int mapping_department(string a) {
	if (a == "华东地区")
		return 1;
	if (a == "华南地区")
		return 2;
	if (a == "华西地区")
		return 3;
	if (a == "华北地区")
		return 4;
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
employee::employee() {
	eno = 110;
	name = 'Fitz';
	sex = 'male';
	birthdate.SetDay(1);
	birthdate.SetMonth(1);
	birthdate.SetYear(1);
	title = 1;
	wages = 100;
}
employee::employee(string eno1, string name1) {
	eno = eno1;
	name = name1;
}
employee::employee(string eno1, string name1, string sex1, Date birthdate1, string title1, long long wages1) {
	eno = eno1;
	name = name1;
	sex = sex1;
	birthdate.SetDay(birthdate1.GetDay());
	birthdate.SetMonth(birthdate1.GetMonth());
	birthdate.SetYear(birthdate1.GetYear());
	title = mapping(title1);
	wages = wages1;
}
void employee::cal_and_show() {
	cout << "编号: " << eno << "姓名: " << name << "性别: " << sex << "出生日期: " << birthdate.GetYear() << "/" << birthdate.GetMonth() << "/ " << birthdate.GetDay() << "职务: " << ave_mapping(title) << endl;
}
void employee::set(string eno1, string name1, string sex1, Date birthdate1, string title1) {
	eno = eno1;
	name = name1;
	sex = sex1;
	birthdate.SetDay(birthdate1.GetDay());
	birthdate.SetMonth(birthdate1.GetMonth());
	birthdate.SetYear(birthdate1.GetYear());
	title = mapping(title1);
}
void manager::cal_and_show() {
	employee::cal_and_show();
	cout << "月薪为:" << wages << endl;
}
void manager::set(string eno1, string name1, string sex1, Date birthdate1, string title1) {
	eno = eno1;
	name = name1;
	sex = sex1;
	birthdate.SetDay(birthdate1.GetDay());
	birthdate.SetMonth(birthdate1.GetMonth());
	birthdate.SetYear(birthdate1.GetYear());
	title = mapping(title1);
	wages = 8000;
}
void technician::cal_and_show() {
	employee::cal_and_show();
	cout << "工作总时长为:" << working_time << endl;
	wages = working_time * 25;
	cout << "月薪为:" << wages << endl;
}
void technician::set(string eno1, string name1, string sex1, Date birthdate1, string title1, int working_time1) {
	eno = eno1;
	name = name1;
	sex = sex1;
	birthdate.SetDay(birthdate1.GetDay());
	birthdate.SetMonth(birthdate1.GetMonth());
	birthdate.SetYear(birthdate1.GetYear());
	title = mapping(title1);
	working_time = working_time1;
	//wages = working_time * 25;
}
void salesman::cal_and_show() {
	employee::cal_and_show();
	cout << "销售额为:" << sales_sum << endl;
	cout << "部门为:" << ave_mapping(title) << endl;
	wages = sales_sum * 0.04;
	cout << "月薪为:" << wages << endl;
}
void salesman::set(string eno1, string name1, string sex1, Date birthdate1, string title1, int sales_sum1, string department1) {
	eno = eno1;
	name = name1;
	sex = sex1;
	birthdate.SetDay(birthdate1.GetDay());
	birthdate.SetMonth(birthdate1.GetMonth());
	birthdate.SetYear(birthdate1.GetYear());
	title = mapping(title1);
	sales_sum = sales_sum1;
	department = department1;
	//wages = sales_sum * 0.04;
}
void salesmanager::cal_and_show() {
	cout << "编号:" << salesman::eno << "姓名:" << salesman::name << "性别:" << salesman::sex << "出生日期:" << salesman::birthdate.GetYear() << "/" << salesman::birthdate.GetMonth() << "/" << salesman::birthdate.GetDay() << "职务:" << ave_mapping(salesman::title) << endl;
	cout << "部门为:" << ave_mapping(salesman::title) << endl;
	cout << "部门销售总额为:" << departmentsum << endl;
	salesman::wages = 5000 + 0.004 * departmentsum;
	cout << "月薪为:" << salesman::wages << endl;
}
void salesmanager::set(string eno1, string name1, string sex1, Date birthdate1, string title1, string department1) {
	salesman::eno = eno1;
	salesman::name = name1;
	salesman::sex = sex1;
	salesman::birthdate.SetDay(birthdate1.GetDay());
	salesman::birthdate.SetMonth(birthdate1.GetMonth());
	salesman::birthdate.SetYear(birthdate1.GetYear());
	salesman::title = mapping(title1);
	salesman::department = department1;
	//salesman::wages = 5000 + 0.004 * departmentsum;
}
