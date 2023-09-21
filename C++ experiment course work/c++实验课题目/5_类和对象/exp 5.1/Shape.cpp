#include<iostream>
#include "Shape.h"
using namespace std;
#define pi 3.14
float Circle::GetArea() {
	return pi * r * r;
}
void Circle::Show() {
	cout << "圆心坐标：" << x << "," << y << endl;
	cout << "直径:" << 2 * r << endl;
	cout << "周长:" << 2 * pi * r << endl;
	cout << "面积:" << GetArea() << endl;
}
void Circle::Set(float x0, float y0, float r0) {
	x = x0;
	y = y0;
	r = r0;
	cout << "Now it's fully updated as below:" << endl;
	Show();
}
float Rectangle::GetArea() {
	return wide * len;
}
void Rectangle::Show() {
	cout << "长，宽：" << len << "," << wide << endl;
	cout << "周长:" << 2 * (wide + len) << endl;
	cout << "面积:" << GetArea() << endl;
}
void Rectangle::Set(float x0, float y0) {
	wide = x0;
	len = y0;
	cout << "Now it's fully updated as below:" << endl;
	Show();
}
float Triangle::GetArea() {
	float temp = (a + b + c) / 2;
	return sqrt(temp * (temp - a) * (temp - b) * (temp - c));//用公式
}
void Triangle::Show() {
	cout << "三边长：" << a << b << c << endl;
	cout << "周长:" << a + b + c << endl;
	cout << "面积:" << GetArea() << endl;
}
void calculation(float* arr, Triangle& t) {//形参为引用，此函数的目的是将坐标转换为边，并判断输入是否合理
	for (int i = 0; i < 6; i++)
		cin >> arr[i];//一次性输入坐标，先输x再输y
	float A, B, C;//三条边的长度。 
	A = sqrt(pow((arr[0] - arr[2]), 2) + pow((arr[1] - arr[3]), 2));
	B = sqrt(pow((arr[0] - arr[4]), 2) + pow((arr[1] - arr[5]), 2));
	C = sqrt(pow((arr[2] - arr[4]), 2) + pow((arr[3] - arr[5]), 2));
	bool flag = true;
	if (A + B <= C)flag = 0;//依次判断三条边是否符合题意
	if (A + C <= B)flag = 0;
	if (B + C <= A)flag = 0;
	if (flag == true) {
		t.Set(A, B, C);
	}
	else {
		cout << "输入的坐标无法构成三角形，请重新输入坐标:";
		calculation(arr, t);
	}
}