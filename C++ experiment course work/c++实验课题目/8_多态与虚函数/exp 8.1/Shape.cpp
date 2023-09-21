#include "Shape.h"
#include <iostream>
using namespace std;
#define PI 3.14
circle::circle()//无参构造
{
	x1 = 1;
	y1 = 1;
	r = 1;
}
circle::circle(int x, int y, int r0) {
	x1 = x;
	y1 = y;
	r = r0;
}
double circle::GetArea()
{
	double s;
	s = PI;
	s = s * r * r;
	return s;
}
void circle::Show()
{
	double c;
	c = PI;
	c = c * 2 * r;
	cout << "(" << x1 << "," << y1 << ")" << endl;//坐标；
	cout << "2R =" << 2 * r << endl;//直径；
	cout << "circum =" << c << endl;//周长；
	cout << "the area of the circle:" << GetArea() << endl;
}
void circle::Set(int a, int b, int c)
{
	this->x1 = a;
	this->y1 = b;
	this->r = c;
}
rectangle::rectangle()
{
	length = 0;
	width = 0;
}
rectangle::rectangle(int x0, int y0)
{
	length = x0;//依次输入长宽
	width = y0;
}
double rectangle::GetArea()
{
	int s;
	s = width * length;
	return s;
}
void rectangle::Show()
{
	cout << "length = " << length << endl;
	cout << " width= " << width << endl;
	cout << "rectangle circum = " << 2 * (length + width) << endl;
	cout << "rectangle area = " << GetArea() << endl;
}
void rectangle::Set(int a, int b)
{
	length = a;
	width = b;
}
triangle::triangle() {
	x31 = 0;
	y31 = 0;
	x32 = 0;
	y32 = 0;
	x33 = 0;
	y33 = 0;
	edgelen1 = 0;
	edgelen2 = 0;
	edgelen3 = 0;
}
triangle::triangle(int x11, int y11, int x22, int y22, int x34, int y34) {
	x31 = x11;
	y31 = y11;
	x32 = x22;
	y32 = y22;
	x33 = x34;
	y33 = y34;
}
double triangle::GetArea()
{
	double s;
	double p;
	p = (edgelen1 + edgelen2 + edgelen3) / 2;
	s = p * (p - edgelen1) * (p - edgelen2) * (p - edgelen3);
	s = sqrt(s);
	return s;
}
void triangle::Show()
{
	cout << "location:\n(" << x31 << "," << y31 << ")" << endl;
	cout << "(" << x32 << "," << y32 << ")" << endl;
	cout << "(" << x33 << "," << y33 << ")" << endl;
	double a, b, c, c1;
	a = pow((x31 - x32), 2) + pow((y31 - y32), 2);
	a = sqrt(a);
	b = pow((x31 - x33), 2) + pow((y31 - y33), 2);
	b = sqrt(b);
	c = pow((x32 - x33), 2) + pow((y32 - y33), 2);
	c = sqrt(c);
	c1 = a + b + c;
	edgelen1 = a;
	edgelen2 = b;
	edgelen3 = c;
	cout << "triangle circum = " << c1 << endl;
	cout << "The area is :" << GetArea() << endl;
}
void triangle::Set(int a, int b, int c, int d, int e, int f)
{
	x31 = a;//依次输入每个点的横纵坐标
	y31 = b;
	x32 = c;
	y32 = d;
	x33 = e;
	y33 = f;
}