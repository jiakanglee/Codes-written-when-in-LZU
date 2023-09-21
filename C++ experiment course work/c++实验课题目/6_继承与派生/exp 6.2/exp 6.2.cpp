#include<iostream>
#include<string>
#include"Teacher.h"
using namespace std;
int main() {
	cout << "请输入人员的个数" << endl;
	int n;
	cin >> n;
	cout << endl;

	//创立对象数组：
	Teacher_Cadre Inf[100];

	for (int i = 0; i < n; i++) {
		cout << "请输入第" << i + 1 << "个人员的姓名、年龄、性别、地址、电话、职称、职务" << endl;
		string name;
		int age;
		string sex;
		string address;
		long long tele;
		string title;
		string post;
		cin >> name >> age >> sex >> address >> tele >> title >> post;
		Inf[i].Set(name, age, sex, address, tele, title, post);
		cout << endl;
	}
	for (int i = 0; i < n; i++) {
		Inf[i].show();
	}
	return 0;
}
