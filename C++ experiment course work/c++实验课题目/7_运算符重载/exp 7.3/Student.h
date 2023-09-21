#pragma once
#include<iostream>
#pragma warning(disable:4996)
#include"Student.h"
using namespace std;
class Student {
public:
	Student();
	Student(const char* na, int d1, int d2, int d3);
	friend Student operator+(Student s1, Student s2);
    friend void avg(Student& s);
	void set(float average11, float average22, float average33);
	void cal_for_ave();
private:
	char name[10];
	int deg1, deg2, deg3;
public:
	float average1;
	float average2;
	float average3;
};