#include <iostream>
#include "functionlist.h"
using namespace std;
struct Student
{
	    int nu; //学号
		char name[20]; //班级注意字节长度
		char classname[20]; //班级
		float score[3]; //三门课程成绩
		float aver_score; //平均分
};
Student stu_info[20];
int main() {
	int number = 5;
	input(stu_info);
	average_perstu(stu_info, number);
	most_average(stu_info,number);
	return 0;
}