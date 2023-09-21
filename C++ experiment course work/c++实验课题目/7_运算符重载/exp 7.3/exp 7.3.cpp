#include<iostream>
#pragma warning(disable:4996)
using namespace std;
#include"Student.h"
int main() {
	Student s1("Jim", 70, 80, 90);
	Student s2("Ftiz", 85, 90, 95);
	Student s3("Jiakang", 70, 80, 76);
	Student s4("Jessica", 87, 89, 95);
	Student s5("Abbolo", 86, 54, 97);
	Student s6 = s1 + s2 + s3 + s4 + s5;
	s6.cal_for_ave();
	s1.set(s6.average1, s6.average2, s6.average3);
	s2.set(s6.average1, s6.average2, s6.average3);
	s3.set(s6.average1, s6.average2, s6.average3);
	s4.set(s6.average1, s6.average2, s6.average3);
	s5.set(s6.average1, s6.average2, s6.average3);
	avg(s1);
	avg(s2);
	avg(s3);
	avg(s4);
	avg(s5);
}