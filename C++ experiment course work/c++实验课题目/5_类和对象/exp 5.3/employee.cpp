#include "employee.h"
#include <iostream>
using namespace std;
employee::employee() {
	num = "2001";
}//ȱʡ���캯��
employee::employee(string n, string nam, char s, Date  bir, string pos) {
	num = n;
	name = nam;
	sex = s;
	Date birthay = bir;
	position = pos;
}//���������캯��������Date������&
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
	cout << "number,name,sex,birthday,position����Ϊ:" << endl;
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
			cout << "���ҵ�Ա������ϢΪ��" << endl;
			p[i].Show();
			flag = 0;
			break;
		}
	}
	if (flag)cout << "û�б��Ϊ" << num << "��Ա������ȷ�ϱ�������Ƿ���ȷ��" << endl;

}
void employee::SearchName(string name, employee* p, int n) {
	bool flag = 1;
	for (int i = 0; i < n; i++) {
		if (name == p[i].GetName()) {
			cout << "���ҵ�Ա������ϢΪ��" << endl;
			p[i].Show();
			flag = 0;
			break;
		}
	}
	if (flag)cout << "û������Ϊ" << name << "��Ա������ȷ�����������Ƿ���ȷ��" << endl;

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