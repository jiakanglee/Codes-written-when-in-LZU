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
	/*、在两个基类中的姓名、年龄、性别、地址、电话等数据成员使用相同名字，在派生
	类中引用这些数据成员时，采用指定作用域的方式；*/
	//调用教师的display函数
public:
	void show();
	void Set(string name1, int age1, string sex1, string address1, long long tele1, string title1, string post1);
private:
	int wage;
};