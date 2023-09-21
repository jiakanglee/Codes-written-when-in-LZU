#include<iostream>
#include "Shape.h"
using namespace std;
#define pi 3.14
float Circle::GetArea() {
	return pi * r * r;
}
void Circle::Show() {
	cout << "Բ�����꣺" << x << "," << y << endl;
	cout << "ֱ��:" << 2 * r << endl;
	cout << "�ܳ�:" << 2 * pi * r << endl;
	cout << "���:" << GetArea() << endl;
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
	cout << "������" << len << "," << wide << endl;
	cout << "�ܳ�:" << 2 * (wide + len) << endl;
	cout << "���:" << GetArea() << endl;
}
void Rectangle::Set(float x0, float y0) {
	wide = x0;
	len = y0;
	cout << "Now it's fully updated as below:" << endl;
	Show();
}
float Triangle::GetArea() {
	float temp = (a + b + c) / 2;
	return sqrt(temp * (temp - a) * (temp - b) * (temp - c));//�ù�ʽ
}
void Triangle::Show() {
	cout << "���߳���" << a << b << c << endl;
	cout << "�ܳ�:" << a + b + c << endl;
	cout << "���:" << GetArea() << endl;
}
void calculation(float* arr, Triangle& t) {//�β�Ϊ���ã��˺�����Ŀ���ǽ�����ת��Ϊ�ߣ����ж������Ƿ����
	for (int i = 0; i < 6; i++)
		cin >> arr[i];//һ�����������꣬����x����y
	float A, B, C;//�����ߵĳ��ȡ� 
	A = sqrt(pow((arr[0] - arr[2]), 2) + pow((arr[1] - arr[3]), 2));
	B = sqrt(pow((arr[0] - arr[4]), 2) + pow((arr[1] - arr[5]), 2));
	C = sqrt(pow((arr[2] - arr[4]), 2) + pow((arr[3] - arr[5]), 2));
	bool flag = true;
	if (A + B <= C)flag = 0;//�����ж��������Ƿ��������
	if (A + C <= B)flag = 0;
	if (B + C <= A)flag = 0;
	if (flag == true) {
		t.Set(A, B, C);
	}
	else {
		cout << "����������޷����������Σ���������������:";
		calculation(arr, t);
	}
}