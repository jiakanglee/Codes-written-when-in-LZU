#pragma once
#include<string>
#include<string.h>
#include <iostream>
using namespace std;
class Teacher {
public:
	void display();
protected:
	string name;
	int age;
	string sex;
	string address;
	long long tele;
	string title;
};
class Cadre {
public:
	void display();
protected:
	string name;
	int age;
	string sex;
	string address;
	long long tele;
	string post;
};
class Teacher_Cadre :public Teacher, Cadre {
	/*�������������е����������䡢�Ա𡢵�ַ���绰�����ݳ�Աʹ����ͬ���֣�������
	����������Щ���ݳ�Աʱ������ָ��������ķ�ʽ��*/
	//���ý�ʦ��display����
public:
	void show();
	void Set(string name1, int age1, string sex1, string address1, long long tele1, string title1, string post1);
private:
	int wage;
};