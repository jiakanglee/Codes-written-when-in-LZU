#include <iostream>
#include<cmath>
#include"Shape.h"
#define pi 3.14
using namespace std;
int main() {
	//Բ�Ĳ��ֲ��ԣ�������������ֵ�Ĵ���
	bool flag;
	for (int i = 1; i <= 3; i++) {
		cout << "������Բ������Ͱ뾶��" << endl;
		float x1, y1, r1;
		cin >> x1 >> y1 >> r1;
		if (r1 < 0)
		{
			cout << "invalid input!" << endl;
			continue;
		}
		Circle c1(x1, y1, r1);
		c1.Show();
	}
	//���β��ֵĲ��ԣ�
	for (int i = 1; i <= 3; i++) {
		cout << "��������εĿ�ͳ���" << endl;
		float wide1, len1;
		cin >> wide1 >> len1;
		if (wide1 <= 0 || len1 <= 0)
		{
			cout << "invalid input!" << endl;
			continue;
		}
		Rectangle r2(wide1, len1);
		r2.Show();
	}
	//�����εĲ��ԣ� 
	for (int i = 1; i <= 3; i++) {
		cout << "�����������ζ�����������꣺" << endl;
		float coordinate[7];
		Triangle t1;
		calculation(coordinate, t1);
		t1.Show();
	}
	return 0;
}