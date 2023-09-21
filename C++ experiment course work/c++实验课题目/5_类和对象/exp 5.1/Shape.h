#pragma once
class Circle {
public:
	//~Circle();
	//Circle() {  }//missing initializing
	Circle() {   //non-argumental initializing
		x = 0;
		y = 0;
		r = 0;
	}
	Circle(float x0) {//partly initializing

		x = x0;
		y = 1;
		r = 1;
	}
	Circle(float x0, float y0, float r0)//standard initializing
	{
		x = x0;
		y = y0;
		r = r0;
	}
	float GetArea();
	void Show();
	void Set(float x0, float y0, float r0);
private:
	float x;
	float y;
	float r;
};
class Rectangle {
public:
	//~Rectangle();//析构
	//Rectangle();//无操作
	Rectangle() {//无参数初始化
		wide = 0;
		len = 0;
	}
	Rectangle(float wide0) {//部分参数初始化
		wide = wide0;
		len = 0;

	}
	Rectangle(float wide0, float len0) {//满参数初始化
		wide = wide0;
		len = len0;
	}
	float GetArea();//求面积
	void Show();//展示基本信息
	void Set(float wide0, float len0);//修改参数
private:
	float wide;
	float len;
};
class Triangle {
public:
	//~Triangle();
	//Triangle();//无操作
	Triangle() {//无参数
		a = 0;
		b = 0;
		c = 0;
	}
	Triangle(float a0) {//部分参数
		a = a0;
		b = 0;

	}
	Triangle(float a0, float b0, float c0) {//无参数
		a = a0;
		b = b0;
		c = c0;
	}
	float GetArea();
	void Show();
	void Set(float A, float B, float C) {
		a = A;
		b = B;
		c = C;
	}
private:
	float a;
	float b;
	float c;
};
void calculation(float* arr, Triangle& t);