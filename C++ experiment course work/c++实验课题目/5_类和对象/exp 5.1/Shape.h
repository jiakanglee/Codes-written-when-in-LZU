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
	//~Rectangle();//����
	//Rectangle();//�޲���
	Rectangle() {//�޲�����ʼ��
		wide = 0;
		len = 0;
	}
	Rectangle(float wide0) {//���ֲ�����ʼ��
		wide = wide0;
		len = 0;

	}
	Rectangle(float wide0, float len0) {//��������ʼ��
		wide = wide0;
		len = len0;
	}
	float GetArea();//�����
	void Show();//չʾ������Ϣ
	void Set(float wide0, float len0);//�޸Ĳ���
private:
	float wide;
	float len;
};
class Triangle {
public:
	//~Triangle();
	//Triangle();//�޲���
	Triangle() {//�޲���
		a = 0;
		b = 0;
		c = 0;
	}
	Triangle(float a0) {//���ֲ���
		a = a0;
		b = 0;

	}
	Triangle(float a0, float b0, float c0) {//�޲���
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