#include <iostream>
using namespace std;
//仅用第二种方法。
void func1(float stu_info[5][7]) {
	for (int i = 0; i < 5; i++) {
		int sum = 0;
		for (int j = 1; j < 6; j++) {
			sum += stu_info[i][j];
		}
		stu_info[i][6] = sum / 5;
	}
	for (int i = 0; i < 5; i++) {
		cout << "第" << i+1 << "位学生的学号，5门课的成绩,平均成绩分别是:" << endl;
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
		cout << "请输入第" << i + 1 << "位学生的学号，5门课的成绩" << endl;
		for (int j = 0; j < 6; j++) {
			cin >> stu_info[i][j];
		}
	}
	func1(stu_info);
	int n;
	cout << "请输入您想求的是第几门课程的平均分的课序号" << endl;
	cin >> n;
	cout << "其结果是:" << endl;
	cout << func2(stu_info, n) << endl;
	return 0;
}