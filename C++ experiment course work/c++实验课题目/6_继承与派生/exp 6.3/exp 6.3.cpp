#include<iostream>
using namespace std;
#include"Post.h"
int main() {
	cout << "��ֱ������ж��ٸ��ܾ�������Ա�����۾���,������Ա��" << endl;
	int n1,n2,n3,n4;
	cin >> n1>>n2>>n3>>n4;
	manager a1[100];
	salesmanager a3[100];
	salesman a2[100];
	technician a4[100];
	int departmensum1[100] = { 0 };
	for (int i = 0; i < n1; i++) {//�ܾ���
		string eno1;
		string name1;
		string sex1;
		Date birthdate1;
		int year, month, day;
		string title1;
		cout << "��ֱ��������ţ��������Ա𣬳������ڣ�ְ��" << endl;
		cin >> eno1 >> name1 >> sex1 >> year >> month >> day >> title1;
		birthdate1.SetYear(year);
		birthdate1.SetMonth(month);
		birthdate1.SetDay(day);
		a1[i].set(eno1, name1, sex1, birthdate1, title1);
	}
	for (int i = 0; i < n2; i++) {//����Ա
		string eno1;
		string name1;
		string sex1;
		Date birthdate1;
		int year, month, day;
		string title1;
		int sales_sum1;
		string department1;
		cout << "��ֱ��������ţ��������Ա𣬳������ڣ�ְ��,�����ܶ���ţ�" << endl;
		cin >> eno1 >> name1 >> sex1 >> year >> month >> day >> title1 >> sales_sum1 >> department1;
		birthdate1.SetYear(year);
		birthdate1.SetMonth(month);
		birthdate1.SetDay(day);
		a2[i].set(eno1, name1, sex1, birthdate1, title1, sales_sum1, department1);
		departmensum1[mapping_department(department1)] += sales_sum1;
	}
	for (int i = 0; i < n3; i++) {//���۾���
		string eno1;
		string name1;
		string sex1;
		Date birthdate1;
		int year, month, day;
		string title1;
		string department1;
		cout << "��ֱ��������ţ��������Ա𣬳������ڣ�ְ�񣬲��ţ�" << endl;
		cin >> eno1 >> name1 >> sex1 >> year >> month >> day >> title1>>department1;
		birthdate1.SetYear(year);
		birthdate1.SetMonth(month);
		birthdate1.SetDay(day);
		a3[i].departmentsum = departmensum1[mapping_department(department1)];
		a3[i].set(eno1, name1, sex1, birthdate1, title1,department1);
		
	}
	for (int i = 0; i < n4; i++) {//������Ա
		string eno1;
		string name1;
		string sex1;
		Date birthdate1;
		int year, month, day;
		string title1;
		int working_time1;
		cout << "��ֱ��������ţ��������Ա𣬳������ڣ�ְ��,����ʱ����" << endl;
		cin >> eno1 >> name1 >> sex1 >> year >> month >> day >> title1>>working_time1;
		birthdate1.SetYear(year);
		birthdate1.SetMonth(month);
		birthdate1.SetDay(day);
		a4[i].set(eno1, name1, sex1, birthdate1, title1,working_time1);
	}
	for (int i = 0; i < n1; i++) {
		a1[i].cal_and_show();
	}
	for (int i = 0; i < n2; i++) {
		a2[i].cal_and_show();
	}
	for (int i = 0; i < n3; i++) {
		a3[i].cal_and_show();
	}
	for (int i = 0; i < n4; i++) {
		a4[i].cal_and_show();
	}
	return 0;
}
//
/*
1 3 1 1
10001 �ſ� �� 75 6 10 �ܾ���
10003 ���� �� 80 12 10 ����Ա 3000 ��������
10004 �º��� Ů 82 1 10 ����Ա 4000 ��������
10006 ��ǿ �� 82 4 12 ����Ա 5000 ��������
10002 ��� �� 79 10 10 ���۾��� ��������
10005 ���� �� 79 1 19 ������Ա 120
*/