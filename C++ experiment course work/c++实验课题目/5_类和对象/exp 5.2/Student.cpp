#include "Student.h"
#include <iostream>
using namespace std;
student::student() {
	stuno = "320190941301";
}//Ĭ��
student::student(string stuno1, string name1) {//����
	stuno = stuno1;
	name = name1;
}
//~Student();
student::student(string stuno1, string name1, string sex1, string birthdate1, int grade1, string class_1, string  department1, string major1) {//������
	stuno = stuno1;
	name = name1;
	sex = sex1;
	birthdate = birthdate1;
	grade = grade1;
	class_ = class_1;
	department = department1;
	major = major1;

}//�����������Ĺ��캯��
void student::SetInfo(string stuno1, string name1, string sex1, string birthdate1, string grade1, string class_1, string  department1, string major1) {//������
	stuno = stuno1;
	name = name1;
	sex = sex1;
	birthdate = birthdate1;
	grade = grade1;
	class_ = class_1;
	department = department1;
	major = major1;

}
void student::Show() {
	cout << endl;
	cout << "stu number:" << stuno << endl;
	cout << "stu name:" << name << endl;
	cout << "stu sex:" << sex << endl;
	cout << "stu birthdate:" << birthdate << endl;
	cout << "stu grade:" << grade << endl;
	cout << "stu class:" << class_ << endl;
	cout << "stu department:" << department << endl;
	cout << "stu major:" << major << endl;
}