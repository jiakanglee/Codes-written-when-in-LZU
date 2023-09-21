#include <iostream>
#include "functionlist.h"
using namespace std;
struct Student
{
	int num; //学号
	char name[20]; //班级注意字节长度
	char classname[20]; //班级
	float score[3]; //三门课程成绩
	float aver_score; //平均分
};
void input(struct Student stu[]) {
	int stu_number = 0; //学生个数
	cout << "please enter student number:"<<endl;
	cin >> stu_number; //输入学生个数
	for (int i = 0; i < stu_number; i++)
	{
		cout << "please enter NO. " << i + 1 << " student info : num name class score1 score2 score3" << endl;
		cin >> stu[i].num >> stu[i].name >> stu[i].classname;
		cin >> stu[i].score[0] >> stu[i].score[1] >> stu[i].score[2];
	}
}
void average_perstu(Student stu[], int number) {
	for (int i = 0; i < number; i++)
	{
		stu[i].aver_score = (stu[i].score[0] + stu[i].score[1] + stu[i].score[2]) / 3.0;
		cout << " NO. " << i + 1 << " student average score : " << stu[i].aver_score<< endl;
	}
}
int most_average(Student stu[],int number) 
{
	int k = 0;
	int max = -1000000;
		//查找最高平均分并记录在数组中的下标值
		for (int i = 0; i < number; i++)
		{
			if (stu[i].aver_score > max)
			{
				k = i;
				max = stu[i].aver_score;
			}
		}
		cout << " NO. " << k + 1 << " student has the highest average score,the info is as below : " << endl;
		cout << "Student number:" << stu[k].num << endl; //学号
		cout << "Student name:" << stu[k].name<<endl; //班级注意字节长度
		cout << "Student class:" << stu[k].classname<<endl; //班级
		cout << "Student course 1 score :" << stu[k].score[0] << endl;
		cout << "Student course 2 score :" << stu[k].score[1] << endl;
		cout << "Student course 3 score :" << stu[k].score[2] << endl;
		cout << "Student average score:" << stu[k].aver_score<<endl; //平均分
		return k; //返回最高平均分数组元素的下标
}