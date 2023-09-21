#pragma once
#include<string>
#include<string.h>
#include <iostream>
using namespace std;
class String {
public:
	String();
	String(string b);
	void show();
	friend bool operator>(String& string1, String& string2);
	friend bool operator<(String& string1, String& string2);
	friend bool operator==(String& string1, String& string2);
	friend ostream& operator<<(ostream& os, String& string2);
	friend istream& operator>>(istream& is, String& string2);
	friend void show();
private:
	string a;
};