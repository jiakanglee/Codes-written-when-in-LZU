#include "Student.h"
#include <iostream>
#include <string>
using namespace std;
int main() {
	cout << "���������������ѧ���ĸ���" << endl;
	int n;
	cin >> n;
	cout << endl;
	student stu[50];
	for (int i = 0; i < n; i++) {
		cout << "�������" << i + 1 << "��ѧ����ѧ�š��������Ա𡢳������ڣ��꼶���༶��Ժϵ��רҵ��";
		string stuno2;
		string name2;
		string sex2;
		string birthdate2;//please input something like this 20010527
		string grade2;
		string class_2;
		string department2;
		string major2;
		cout << "Please input valid data,for sex it could only be Ů�� or ����,birthdate for eg be ��85��07�¡�,grade be 05����class be jy01��department be computer��major be application" << endl;
		cin >> stuno2 >> name2 >> sex2 >> birthdate2 >> grade2 >> class_2 >> department2 >> major2;
		if (sex2 != "Ů" && sex2 != "��") {//���ﲻ�����ƣ��ʽ���������һ������
			cout << "invalid attempt,Please try again for student" << i + 1 << endl;
			cin >> stuno2 >> name2 >> sex2 >> birthdate2 >> grade2 >> class_2 >> department2 >> major2;
		}

		stu[i].SetInfo(stuno2, name2, sex2, birthdate2, grade2, class_2, department2, major2);
		cout << endl;
	}
	for (int i = 0; i < n; i++) {
		cout << "��" << i + 1 << "��ѧ����ѧ�š��������Ա𡢳������� �꼶���༶��Ժϵ��רҵ��";
		stu[i].Show();
		cout << endl;
	}
	int x = 1;
	cout << "please input the order number of the student for updating and input ctrl + Z to stop" << endl;
	while (cin >> n) {
		string stuno2;
		string name2;
		string sex2;
		string birthdate2;//please input something like this 20010527
		string grade2;
		string class_2;
		string department2;
		string major2;
		cout << "Please input valid data, for sex it could only be Ů�� or ����, birthdate for eg be ��85��07�¡�, grade be 05����class be jy01��department be computer��major be application" << endl;
		cin >> stuno2 >> name2 >> sex2 >> birthdate2 >> grade2 >> class_2 >> department2 >> major2;
		if (sex2 != "Ů" && sex2 != "��") {
			cout << "invalid attempt,Please try again for student" << n << endl;
			cin >> stuno2 >> name2 >> sex2 >> birthdate2 >> grade2 >> class_2 >> department2 >> major2;
		}

		stu[x - 1].SetInfo(stuno2, name2, sex2, birthdate2, grade2, class_2, department2, major2);
		cout << endl;
		cout << "updated!The information is updated as:" << endl;
		stu[x - 1].Show();
		cout << "please input the order of the student for updating and input ctrl + Z to stop" << endl;
	}
	return 0;
}