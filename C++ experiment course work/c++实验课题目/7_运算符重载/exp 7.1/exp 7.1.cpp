#include <iostream>
#pragma warning(disable:4996)
#include<cstring>
#include"String.h"
using namespace std;
int main() {
	String string1("china"), string2("China"), string3("National"), string4("Computer"), string5("Examination"), string6("Rank"), string7("swust"), string8("swust"), string9("Hello"), string10;
	cout << (string1 > string2) << endl;
	cout << (string3 < string4) << endl;
	cout << (string5 < string6) << endl;
	cout << (string7 == string8) << endl;
	cout << string9 << endl;
	cin >> string10;	
	cout << string10;
}