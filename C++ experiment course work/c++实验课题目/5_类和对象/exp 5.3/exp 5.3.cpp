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
	cout << "���������������Ա���ĸ���" << endl;
	int n;
	cin >> n;
	cout << endl;

	//��ʼ����
	employee emp[80];
	for (int i = 0; i < n; i++) {
		cout << "�������" << i + 1 << "��Ա���ı�š��������Ա𡢳����ꡢ�¡��ա�ְλ"<<endl;
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
	//�޸���Ϣ��
	cout << "�����������޸ĵ�����Ա�������" << endl;
	int x;
	while (cin >> x && x) {
		string num2, name2, sex2, position2;
		int year, month, day;
		cout << "�������µı�ţ��������Ա𡢳����ꡢ�¡��ա�ְλ" << endl;
		cin >>num2 >> name2 >> sex2 >> year >> month >> day>>position2;
		emp[x-1].SetInfo(num2, name2, sex2,year,month,day,position2);
		cout << "���������޸���Ϣ������������չʾ��Ա������ţ��������µ�������ְλ����Ϣ����������0����" << endl;
	}
	cout << "---------------------------------------------------" << endl << endl;
	for (int i = 0; i < n; i++) {
		emp[i].Show();
		cout << endl;
	}

	cout << endl;
	cout << "����1�ñ�Ų�ѯԱ����Ϣ" << endl;
	cout << "����2��������ѯԱ����Ϣ" << endl;
	cout << "��������ֵ��������" << endl;
	cin >> x;

	switch (x) {
	case 1: {
		string num;
		cout << "��������Ҫ�ҵ�Ա���ı�ţ�";
		cin >> num;
		emp[0].SearchNum(num, emp, n);
		break;
	}
	case 2: {
		string name;
		cout << "��������Ҫ�ҵ�Ա����������";
		cin >> name;
		emp[0].SearchName(name, emp, n);
		break;
	}
	}

	return 0;
}
