#pragma once
#pragma once
#include<string>
#include<string.h>
#include <iostream>
using namespace std;
int mapping(string a);
string ave_mapping(int a);
int mapping_department(string a);
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
protected:
	string eno;
	string name;
	string sex;
	Date birthdate;
	int title;
	long long wages;
public:
	employee();
	employee(string eno1, string name1);
	employee(string eno1, string name1, string sex1, Date birthdate1, string title1, long long wages1);
	void cal_and_show();
	void set(string eno1, string name1, string sex1, Date birthdate1, string title1);
};
class manager :public employee {
	/*  	manager(string eno1, string name1, string sex1, Date birthdate1, string title1) {//赋值调用只能在函数里调用
		  eno = eno1;
		  name = name1;
		  sex = sex1;
		  birthdate.SetDay(birthdate1.GetDay());
		  birthdate.SetMonth(birthdate1.GetMonth());
		  birthdate.SetYear(birthdate1.GetYear());
		  title = title1;
		  wages = 8000;
	  }*/
public:
	void cal_and_show();
	void set(string eno1, string name1, string sex1, Date birthdate1, string title1);
};

class technician : public employee {
protected:
	int working_time;
public:
	/*technician(string eno1, string name1, string sex1, Date birthdate1, string title1) {//赋值调用只能在函数里调用
		eno = eno1;
		name = name1;
		sex = sex1;
		birthdate.SetDay(birthdate1.GetDay());
		birthdate.SetMonth(birthdate1.GetMonth());
		birthdate.SetYear(birthdate1.GetYear());
		title = title1;
		wages = 8000;
	}*/
	void cal_and_show();
	void set(string eno1, string name1, string sex1, Date birthdate1, string title1, int working_time1);
};
class salesman : public employee {
protected:
	int sales_sum;
	string department;
public:
	/*salesman() {
		eno = '111';
	}*/
	/*salesman(string eno1, string name1, string sex1, Date birthdate1, string title1) {//赋值调用只能在函数里调用
		eno = eno1;
		name = name1;
		sex = sex1;
		birthdate.SetDay(birthdate1.GetDay());
		birthdate.SetMonth(birthdate1.GetMonth());
		birthdate.SetYear(birthdate1.GetYear());
		title = mapping(title1);
		wages = 8000;
	}*/
	void cal_and_show();
	void set(string eno1, string name1, string sex1, Date birthdate1, string title1, int sales_sum1, string department1);
};
class salesmanager :public salesman, manager {
public:
	int departmentsum = 1;
public:
	void cal_and_show();
	void set(string eno1, string name1, string sex1, Date birthdate1, string title1, string department1);
};
