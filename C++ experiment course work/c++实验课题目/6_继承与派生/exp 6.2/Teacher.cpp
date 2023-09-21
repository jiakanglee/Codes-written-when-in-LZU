#include "Teacher.h"
#include <iostream>
using namespace std;
void Teacher::display() {
		cout << "姓名：" << name << " " << "年龄：" << age << " " << "性别：" << sex;
		cout << "地址：" << address << " " << "电话：" << tele << " " << "职称：" << title << " " << endl;
	}
void Cadre::display() {
		cout << "姓名：" << name << " " << "年龄：" << age << " " << "性别：" << sex;
		cout << "地址：" << address << " " << "电话：" << tele << " " << "职务：" << post << " ";
	}
void Teacher_Cadre::show() {
		Teacher::display();
		cout << "职务:" << post << endl;
	}
void Teacher_Cadre::Set(string name1, int age1, string sex1, string address1, long long tele1, string title1, string post1) {
		Teacher::name = name1;
		Teacher::age = age1;
		Teacher::sex = sex1;
		Teacher::address = address1;
		Teacher::tele = tele1;
		Cadre::post = post1;
	}