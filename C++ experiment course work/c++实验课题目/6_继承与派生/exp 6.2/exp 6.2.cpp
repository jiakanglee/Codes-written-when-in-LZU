#include<iostream>
#include<string>
#include"Teacher.h"
using namespace std;
int main() {
	cout << "��������Ա�ĸ���" << endl;
	int n;
	cin >> n;
	cout << endl;

	//�����������飺
	Teacher_Cadre Inf[100];

	for (int i = 0; i < n; i++) {
		cout << "�������" << i + 1 << "����Ա�����������䡢�Ա𡢵�ַ���绰��ְ�ơ�ְ��" << endl;
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
