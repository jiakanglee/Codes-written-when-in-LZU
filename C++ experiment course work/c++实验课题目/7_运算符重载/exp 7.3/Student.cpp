#include<iostream>
#pragma warning(disable:4996)
#include"Student.h"
using namespace std;
Student::Student() {
		deg1 = 0, deg2 = 0, deg3 = 0;
	}
Student::Student(const char* na, int d1, int d2, int d3) {
		strcpy(name, na);
		deg1 = d1;//����
		deg2 = d2;//Ӣ��
		deg3 = d3;//�����
	}
 Student operator+(Student s1, Student s2) {
		char name1[100] = "combination:";
		return Student(strcat(strcat(name1, s1.name), s2.name), s1.deg1 + s2.deg1, s1.deg2 + s2.deg2, s1.deg3 + s2.deg3);
	}
void avg(Student& s) {
		cout << "regarding info is as below:" << endl;
		cout << "name:" << s.name << "����:" << s.deg1 << "Ӣ��" << s.deg2 << "�����" << s.deg3;
		cout << "����ƽ����:" << s.average1 << "Ӣ��ƽ����:" << s.average2 << "�����ƽ����:" << s.average3 << endl;
	}
void Student::set(float average11, float average22, float average33) {
		average1 = average11;
		average2 = average22;
		average3 = average33;
	}
void Student::cal_for_ave() {
		average1 = deg1 / 5;
		average2 = deg2 / 5;
		average3 = deg3 / 5;
	}