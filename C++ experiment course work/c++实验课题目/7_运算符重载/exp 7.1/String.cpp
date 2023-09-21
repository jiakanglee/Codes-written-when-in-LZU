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
		//声明运算符重载函数为友元函数,此函数并不在String里面而是用friend则可以访问该类里面的各种变量,不过此处是定义在String类里面的public函数，仍然可以将该几个重载函数弄出String 外定义且不加范围限定符号
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