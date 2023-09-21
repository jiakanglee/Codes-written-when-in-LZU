#include<iostream>
#include<string>
#include"employee.h"
using namespace std;
/*employee::employee() {
	num = 1000;
	name = "xiaoming";
	sex = 'f';

	Date birthday(1900, 1, 1);
	position = "worker";
}*/
int main() {
	cout << "请输入你想输入的员工的个数" << endl;
	int n;
	cin >> n;
	cout << endl;

	//初始化：
	employee emp[80];
	for (int i = 0; i < n; i++) {
		cout << "请输入第" << i + 1 << "个员工的编号、姓名、性别、出生年、月、日、职位"<<endl;
		string num1, name1, sex1, position1;
		int year, month, day;
		cin >> num1 >> name1 >> sex1 >> year >> month >> day>>position1;
		emp[i].SetInfo(num1, name1, sex1,year ,month,day, position1);
		cout << endl;
	}
	for (int i = 0; i < n; i++) {
		emp[i].Show();
		cout << endl;
	}
	//修改信息：
	cout << "请输入你想修改的上面员工的序号" << endl;
	int x;
	while (cin >> x && x) {
		string num2, name2, sex2, position2;
		int year, month, day;
		cout << "输入其新的编号，姓名、性别、出生年、月、日、职位" << endl;
		cin >>num2 >> name2 >> sex2 >> year >> month >> day>>position2;
		emp[x-1].SetInfo(num2, name2, sex2,year,month,day,position2);
		cout << "若您还想修改信息，请输入上面展示的员工的序号，并输入新的姓名和职位等信息，否则输入0结束" << endl;
	}
	cout << "---------------------------------------------------" << endl << endl;
	for (int i = 0; i < n; i++) {
		emp[i].Show();
		cout << endl;
	}

	cout << endl;
	cout << "输入1用编号查询员工信息" << endl;
	cout << "输入2用姓名查询员工信息" << endl;
	cout << "输入其他值，结束。" << endl;
	cin >> x;

	switch (x) {
	case 1: {
		string num;
		cout << "请输入你要找的员工的编号：";
		cin >> num;
		emp[0].SearchNum(num, emp, n);
		break;
	}
	case 2: {
		string name;
		cout << "请输入你要找的员工的姓名：";
		cin >> name;
		emp[0].SearchName(name, emp, n);
		break;
	}
	}

	return 0;
}
