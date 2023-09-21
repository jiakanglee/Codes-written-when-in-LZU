#include <iostream>
#include<cmath>
#include"Shape.h"
#define pi 3.14
using namespace std;
int main() {
	//圆的部分测试：用引用来进行值的传递
	bool flag;
	for (int i = 1; i <= 3; i++) {
		cout << "请输入圆的坐标和半径：" << endl;
		float x1, y1, r1;
		cin >> x1 >> y1 >> r1;
		if (r1 < 0)
		{
			cout << "invalid input!" << endl;
			continue;
		}
		Circle c1(x1, y1, r1);
		c1.Show();
	}
	//矩形部分的测试：
	for (int i = 1; i <= 3; i++) {
		cout << "请输入矩形的宽和长：" << endl;
		float wide1, len1;
		cin >> wide1 >> len1;
		if (wide1 <= 0 || len1 <= 0)
		{
			cout << "invalid input!" << endl;
			continue;
		}
		Rectangle r2(wide1, len1);
		r2.Show();
	}
	//三角形的测试： 
	for (int i = 1; i <= 3; i++) {
		cout << "请输入三角形顶点的三个坐标：" << endl;
		float coordinate[7];
		Triangle t1;
		calculation(coordinate, t1);
		t1.Show();
	}
	return 0;
}