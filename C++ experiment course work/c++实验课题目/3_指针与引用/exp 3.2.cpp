#include <iostream>
using namespace std;
//���õڶ��ַ�����
void func1(float stu_info[5][7]) {
	for (int i = 0; i < 5; i++) {
		int sum = 0;
		for (int j = 1; j < 6; j++) {
			sum += stu_info[i][j];
		}
		stu_info[i][6] = sum / 5;
	}
	for (int i = 0; i < 5; i++) {
		cout << "��" << i+1 << "λѧ����ѧ�ţ�5�ſεĳɼ�,ƽ���ɼ��ֱ���:" << endl;
		for (int j = 0; j < 6; j++) {
			cout << stu_info[i][j] << endl;
		}
	}
}
float func2(float (*pointer)[7], int n) {
	float ans = 0;
	for (int i = 0; i < 5; i++) {
		ans += *(*(pointer+i)+n);
	}
	return ans/5;
}
int main() {
	float stu_info[5][7];
	for (int i = 0; i < 5; i++) {
		cout << "�������" << i + 1 << "λѧ����ѧ�ţ�5�ſεĳɼ�" << endl;
		for (int j = 0; j < 6; j++) {
			cin >> stu_info[i][j];
		}
	}
	func1(stu_info);
	int n;
	cout << "��������������ǵڼ��ſγ̵�ƽ���ֵĿ����" << endl;
	cin >> n;
	cout << "������:" << endl;
	cout << func2(stu_info, n) << endl;
	return 0;
}