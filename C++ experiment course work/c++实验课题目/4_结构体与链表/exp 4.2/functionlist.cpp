#include <iostream>
#include "functionlist.h"
using namespace std;
struct Student
{
	int num; //ѧ��
	char name[20]; //�༶ע���ֽڳ���
	char classname[20]; //�༶
	float score[3]; //���ſγ̳ɼ�
	float aver_score; //ƽ����
};
void input(struct Student stu[]) {
	int stu_number = 0; //ѧ������
	cout << "please enter student number:"<<endl;
	cin >> stu_number; //����ѧ������
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
		//�������ƽ���ֲ���¼�������е��±�ֵ
		for (int i = 0; i < number; i++)
		{
			if (stu[i].aver_score > max)
			{
				k = i;
				max = stu[i].aver_score;
			}
		}
		cout << " NO. " << k + 1 << " student has the highest average score,the info is as below : " << endl;
		cout << "Student number:" << stu[k].num << endl; //ѧ��
		cout << "Student name:" << stu[k].name<<endl; //�༶ע���ֽڳ���
		cout << "Student class:" << stu[k].classname<<endl; //�༶
		cout << "Student course 1 score :" << stu[k].score[0] << endl;
		cout << "Student course 2 score :" << stu[k].score[1] << endl;
		cout << "Student course 3 score :" << stu[k].score[2] << endl;
		cout << "Student average score:" << stu[k].aver_score<<endl; //ƽ����
		return k; //�������ƽ��������Ԫ�ص��±�
}