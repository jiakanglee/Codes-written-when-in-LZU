#include<iostream>
#include<math.h>
#include "Shape.h"
using namespace std;
#define PI 3.14
int main() {
	cout << "Please input the coordinates and the radius of the circle:" << endl;
	int x, y, r;
	cin >> x >> y >> r;
	circle a(x, y, r);
	Shape* t = &a;
	cout<<(t->GetArea())<<endl;
	cout << "Please input the coordinates and the radius of the circle for the test:" << endl;
	cin >> x >> y >> r;
	a.Set(x, y, r);
	t = &a;
	cout << (t->GetArea())<<endl;
	cout << "Please input the length and width of the rectangle:" << endl;
	int length, width;
	cin >> length >> width;
	rectangle b(length, width);
	t = &b;
	cout << (t->GetArea())<<endl;
	cout << "Please input the length and width of the rectangle again the test:" << endl;
	cin >> length >> width;
	b.Set(length, width);
	t = &b;
	cout << (t->GetArea())<<endl;
	cout << "please input the coordinates of those three points:" << endl;
	int x11, y11, x22, y22, x33, y33;
	cin >> x11 >> y11 >> x22 >> y22 >> x33 >> y33;
	triangle c(x11, y11, x22, y22, x33, y33);
	t = &c;
	cout << (t->GetArea())<<endl;
	cout << "please input the coordinates of those three points again for the test:" << endl;
	cin >> x11 >> y11 >> x22 >> y22 >> x33 >> y33;
	c.Set(x11, y11, x22, y22, x33, y33);
	t = &c;
	cout << (t->GetArea())<<endl;
	return 0;
}