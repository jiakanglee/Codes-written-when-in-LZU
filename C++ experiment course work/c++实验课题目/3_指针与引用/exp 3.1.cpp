#include<iostream>
using namespace std;
void swap(int* p1, int* p2);
void swap_call(int& p1, int& p2) {
	int temp;
	temp = p1;
	p1 = p2;
	p2 = temp;
}
//归纳说明普通变量作形参、指针作形参、引用作函数形参得区别。
int main() {
	cout << "______________________________________" << endl;
	int iv1 = 777;
	int* pointer_1;//定义指针
	pointer_1 = &iv1;//给指针赋值
	cout << "iv1            = " << iv1 << endl;
	cout << "*pointer_1 = " << *pointer_1 << endl;//*指针 = 指针指向的值
	cout << "&iv1 = " << &iv1 << endl;
	cout << "pointer_1 = " << pointer_1 << endl;

	cout << "___________________________________________" << endl;
	int iv2 = 666;
	int* pointer_2;//定义指针
	pointer_2 = &iv2;
	cout << "iv2            = " << iv2 << endl;
	cout << "*pointer_2 = " << *pointer_2 << endl;
	cout << "&iv2 = " << &iv2 << endl;
	cout << "pointer_2 = " << pointer_2 << endl;
	cout << "___________________________________________" << endl;
	//swap(pointer_1, pointer_2);
	swap_call(iv1, iv2);
	cout << "iv1 = " << iv1 << endl;
	cout << "iv2 = " << iv2 << endl;
	cout << "*pointer_1 = " << *pointer_1 << endl;
	cout << "*pointer_2 = " << *pointer_2 << endl;//交换完后对应的值也交换
	cout << "pointer_1 = " << pointer_1 << endl;
	cout << "pointer_2 = " << pointer_2 << endl;
	return 0;
}
void swap(int* p1, int* p2) {
	int temp;//交换函数，传入的是int型指针变量，交换指向的值
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
	/*int* temp;//这里Int型的值无法赋值给int*型
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;*/
}
