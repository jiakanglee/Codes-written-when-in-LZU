#pragma once
#include<string>
#include<string.h>
#include <iostream>
using namespace std;
class Shape {
public:
	double GetArea();
	void Show();
	void Set();
};
class circle :public Shape   //ºÃ≥–shape¿‡
{
public:
	circle();
	circle(int x, int y, int r0);
	double GetArea();
	void Show();
	void Set(int a, int b, int c);
private:
	int x1;
	int y1;
	int r;
};
class rectangle :public Shape
{
public:
	rectangle();
	rectangle(int x, int y);
	double GetArea();
	void Show();
	void Set(int a, int b);
private:
	int length;
	int width;
};
class triangle :public Shape
{
public:
	triangle();
	triangle(int x11, int y11, int x22, int y22, int x33, int y33);
	double GetArea();
	void Show();
	void Set(int a, int b, int c, int d, int e, int f);
private:
	int x31;
	int y31;
	int x32;
	int y32;
	int x33;
	int y33;
	double edgelen1;
	double edgelen2;
	double edgelen3;
};