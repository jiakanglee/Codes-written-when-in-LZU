#include<iostream>
#include <math.h>
using namespace std;
int main() {
	float a, b, c;
	char ch,ch1;
	while (1) {
		cout << "Please input forms like 5 + 6 = " << endl;
		cout << "hint on the calculation sign is as follows:" << endl;
		cout << "+ means add" << endl;
		cout << "- means minus" << endl;
		cout << "* means multiply" << endl;
		cout << "/ means divide" << endl;
		cout << "^ means power" << endl;
		cout << "& means rooting" << endl;
		cout << "~ means sin,in this situation,a means 系数，b为sin里面的值，下同" << endl;
		cout << "！ means cos" << endl;
		cout << "$ means tan" << endl;
		cout << "Now start your input:" << endl;
		cin >> a >> ch >> b >> ch1;
		switch (ch) {
		case'+':c = a + b; cout << c << endl; break;
		case'-':c = a - b; cout << c << endl; break;
		case'*':c = a * b; cout << c << endl; break;
		case'/':c = a / b; cout << c << endl; break;
		case'^':c = pow(a, b); cout << c << endl; break;
		case'&':c = pow(a, 1.0 / b); cout << c << endl; break;
		case'~':c = a * sin(b); cout << c << endl; break;
		case'!':c = a * cos(b); cout << c << endl; break;
		case'$':c = a * tan(b); cout << c << endl; break;
		default:break;
		}
		//终止条件
/*		cout << "now you've got your answer,do you want to continue?enter 0 to quit,anything else to continue:" << endl;
		int flag = 0;
		cin >> flag;
		if (flag == 0)
			break;
	
		*/
	}
	return 0;
	}
