#include<iostream>
using namespace std;
#include"Post.h"
int main() {
	cout << "请分别输入有多少个总经理，销售员，销售经理,技术人员：" << endl;
	int n1,n2,n3,n4;
	cin >> n1>>n2>>n3>>n4;
	manager a1[100];
	salesmanager a3[100];
	salesman a2[100];
	technician a4[100];
	int departmensum1[100] = { 0 };
	for (int i = 0; i < n1; i++) {//总经理
		string eno1;
		string name1;
		string sex1;
		Date birthdate1;
		int year, month, day;
		string title1;
		cout << "请分别输入其编号，姓名，性别，出生日期，职务：" << endl;
		cin >> eno1 >> name1 >> sex1 >> year >> month >> day >> title1;
		birthdate1.SetYear(year);
		birthdate1.SetMonth(month);
		birthdate1.SetDay(day);
		a1[i].set(eno1, name1, sex1, birthdate1, title1);
	}
	for (int i = 0; i < n2; i++) {//销售员
		string eno1;
		string name1;
		string sex1;
		Date birthdate1;
		int year, month, day;
		string title1;
		int sales_sum1;
		string department1;
		cout << "请分别输入其编号，姓名，性别，出生日期，职务,销售总额，部门：" << endl;
		cin >> eno1 >> name1 >> sex1 >> year >> month >> day >> title1 >> sales_sum1 >> department1;
		birthdate1.SetYear(year);
		birthdate1.SetMonth(month);
		birthdate1.SetDay(day);
		a2[i].set(eno1, name1, sex1, birthdate1, title1, sales_sum1, department1);
		departmensum1[mapping_department(department1)] += sales_sum1;
	}
	for (int i = 0; i < n3; i++) {//销售经理
		string eno1;
		string name1;
		string sex1;
		Date birthdate1;
		int year, month, day;
		string title1;
		string department1;
		cout << "请分别输入其编号，姓名，性别，出生日期，职务，部门：" << endl;
		cin >> eno1 >> name1 >> sex1 >> year >> month >> day >> title1>>department1;
		birthdate1.SetYear(year);
		birthdate1.SetMonth(month);
		birthdate1.SetDay(day);
		a3[i].departmentsum = departmensum1[mapping_department(department1)];
		a3[i].set(eno1, name1, sex1, birthdate1, title1,department1);
		
	}
	for (int i = 0; i < n4; i++) {//技术人员
		string eno1;
		string name1;
		string sex1;
		Date birthdate1;
		int year, month, day;
		string title1;
		int working_time1;
		cout << "请分别输入其编号，姓名，性别，出生日期，职务,工作时长：" << endl;
		cin >> eno1 >> name1 >> sex1 >> year >> month >> day >> title1>>working_time1;
		birthdate1.SetYear(year);
		birthdate1.SetMonth(month);
		birthdate1.SetDay(day);
		a4[i].set(eno1, name1, sex1, birthdate1, title1,working_time1);
	}
	for (int i = 0; i < n1; i++) {
		a1[i].cal_and_show();
	}
	for (int i = 0; i < n2; i++) {
		a2[i].cal_and_show();
	}
	for (int i = 0; i < n3; i++) {
		a3[i].cal_and_show();
	}
	for (int i = 0; i < n4; i++) {
		a4[i].cal_and_show();
	}
	return 0;
}
//
/*
1 3 1 1
10001 张可 男 75 6 10 总经理
10003 王刚 男 80 12 10 销售员 3000 华北地区
10004 陈浩月 女 82 1 10 销售员 4000 华北地区
10006 付强 男 82 4 12 销售员 5000 华东地区
10002 李兵 男 79 10 10 销售经理 华北地区
10005 宋书 男 79 1 19 技术人员 120
*/