#include "Teacher.h"
#include <iostream>
using namespace std;
void Teacher::display() {
		cout << "������" << name << " " << "���䣺" << age << " " << "�Ա�" << sex;
		cout << "��ַ��" << address << " " << "�绰��" << tele << " " << "ְ�ƣ�" << title << " " << endl;
	}
void Cadre::display() {
		cout << "������" << name << " " << "���䣺" << age << " " << "�Ա�" << sex;
		cout << "��ַ��" << address << " " << "�绰��" << tele << " " << "ְ��" << post << " ";
	}
void Teacher_Cadre::show() {
		Teacher::display();
		cout << "ְ��:" << post << endl;
	}
void Teacher_Cadre::Set(string name1, int age1, string sex1, string address1, long long tele1, string title1, string post1) {
		Teacher::name = name1;
		Teacher::age = age1;
		Teacher::sex = sex1;
		Teacher::address = address1;
		Teacher::tele = tele1;
		Cadre::post = post1;
	}