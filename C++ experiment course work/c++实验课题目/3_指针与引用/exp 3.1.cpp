#include<iostream>
using namespace std;
void swap(int* p1, int* p2);
void swap_call(int& p1, int& p2) {
	int temp;
	temp = p1;
	p1 = p2;
	p2 = temp;
}
//����˵����ͨ�������βΡ�ָ�����βΡ������������βε�����
int main() {
	cout << "______________________________________" << endl;
	int iv1 = 777;
	int* pointer_1;//����ָ��
	pointer_1 = &iv1;//��ָ�븳ֵ
	cout << "iv1            = " << iv1 << endl;
	cout << "*pointer_1 = " << *pointer_1 << endl;//*ָ�� = ָ��ָ���ֵ
	cout << "&iv1 = " << &iv1 << endl;
	cout << "pointer_1 = " << pointer_1 << endl;

	cout << "___________________________________________" << endl;
	int iv2 = 666;
	int* pointer_2;//����ָ��
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
	cout << "*pointer_2 = " << *pointer_2 << endl;//��������Ӧ��ֵҲ����
	cout << "pointer_1 = " << pointer_1 << endl;
	cout << "pointer_2 = " << pointer_2 << endl;
	return 0;
}
void swap(int* p1, int* p2) {
	int temp;//�����������������int��ָ�����������ָ���ֵ
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
	/*int* temp;//����Int�͵�ֵ�޷���ֵ��int*��
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;*/
}
