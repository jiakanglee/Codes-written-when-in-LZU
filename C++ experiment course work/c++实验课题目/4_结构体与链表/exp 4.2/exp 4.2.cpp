#include <iostream>
#include "functionlist.h"
using namespace std;
struct Student
{
	    int nu; //ѧ��
		char name[20]; //�༶ע���ֽڳ���
		char classname[20]; //�༶
		float score[3]; //���ſγ̳ɼ�
		float aver_score; //ƽ����
};
Student stu_info[20];
int main() {
	int number = 5;
	input(stu_info);
	average_perstu(stu_info, number);
	most_average(stu_info,number);
	return 0;
}