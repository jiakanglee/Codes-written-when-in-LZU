#include "String.h"
#include <iostream>
using namespace std;
String::String() {
		a = "Hi";
	}
String::String(string b) {
		a = b;
	}
void String::show() {
		cout << a;
	}
bool operator >(String& string1, String& string2) {
		//������������غ���Ϊ��Ԫ����,�˺���������String���������friend����Է��ʸ�������ĸ��ֱ���,�����˴��Ƕ�����String�������public��������Ȼ���Խ��ü������غ���Ū��String �ⶨ���Ҳ��ӷ�Χ�޶�����
		if (string1.a > string2.a)
			return true;
		else
			return false;
	}
bool operator<(String& string1, String& string2) {
		if (string1.a > string2.a)
			return false;
		else
			return true;
	}
bool operator==(String& string1, String& string2) {
		if (string1.a == string2.a)
			return true;
		else
			return false;
	}
ostream& operator<<(ostream& os, String& string2) {
		os << string2.a;
		return os;
	}
istream& operator>>(istream& is, String& string2) {
		is >> string2.a;
		return is;
	}