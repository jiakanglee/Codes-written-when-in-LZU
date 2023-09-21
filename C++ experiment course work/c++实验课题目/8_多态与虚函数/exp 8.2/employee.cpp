#include "employee.h"
#include <iostream>
using namespace std;
int mapping(string a) {
	if (a == "�ܾ���")
		return 1;
	if (a == "����Ա")
		return 2;
	if (a == "���۾���")
		return 3;
	if (a == "������Ա")
		return 4;
}
string ave_mapping(int a) {
	if (a == 1)
		return "�ܾ���";
	if (a == 3)
		return "���۾���";
	if (a == 2)
		return "����Ա";
	if (a == 4)
		return "������Ա";
}
int mapping_department(string a) {
	if (a == "��������")
		return 1;
	if (a == "���ϵ���")
		return 2;
	if (a == "��������")
		return 3;
	if (a == "��������")
		return 4;
}
/*Date(int y = 1900, int m = 1, int d = 1) {//��Ĭ�ϲ����Ĺ��캯��
	year = y;
	month = m;
	day = d;
}*/
Date::Date() {
	year = 1;
	month = 1;
	day = 1;
}
Date::Date(int y0, int m0, int d0) {//ȫ����
	year = y0;
	month = m0;
	day = d0;
}
//Date();//ȱʧ���캯��
void Date::Show() {
	cout << "�꣬�£��շֱ�Ϊ:" << endl;
	cout << "��:" << year << endl;
	cout << "��:" << month << endl;
	cout << "��:" << day << endl;
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
	cout << "���: " << eno << "����: " << name << "�Ա�: " << sex << "��������: " << birthdate.GetYear() << "/" << birthdate.GetMonth() << "/ " << birthdate.GetDay() << "ְ��: " << ave_mapping(title) << endl;
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
	cout << "��нΪ:" << wages << endl;
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
	cout << "������ʱ��Ϊ:" << working_time << endl;
	wages = working_time * 25;
	cout << "��нΪ:" << wages << endl;
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
	cout << "���۶�Ϊ:" << sales_sum << endl;
	cout << "����Ϊ:" << ave_mapping(title) << endl;
	wages = sales_sum * 0.04;
	cout << "��нΪ:" << wages << endl;
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
	cout << "���:" << salesman::eno << "����:" << salesman::name << "�Ա�:" << salesman::sex << "��������:" << salesman::birthdate.GetYear() << "/" << salesman::birthdate.GetMonth() << "/" << salesman::birthdate.GetDay() << "ְ��:" << ave_mapping(salesman::title) << endl;
	cout << "����Ϊ:" << ave_mapping(salesman::title) << endl;
	cout << "���������ܶ�Ϊ:" << departmentsum << endl;
	salesman::wages = 5000 + 0.004 * departmentsum;
	cout << "��нΪ:" << salesman::wages << endl;
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
