#pragma once
#include<string>
#include<string.h>
#include <iostream>
using namespace std;
class student {
public:
	student();
	student(string stuno1, string name1);
	//~Student();
	student(string stuno1, string name1, string sex1, string birthdate1, int grade1, string class_1, string  department1, string major1);//带完整参数的构造函数
	void SetInfo(string stuno1, string name1, string sex1, string birthdate1, string grade1, string class_1, string  department1, string major1);
	void Show();
private:
	string stuno;
	string name;
	string sex;
	string birthdate;//please input something like this 20010527
	string grade;
	string class_;
	string department;
	string major;
};