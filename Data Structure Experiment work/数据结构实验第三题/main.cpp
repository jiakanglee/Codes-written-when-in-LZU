//��λ����,ready to die!
#include <cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<string.h>
#include<queue>
#include<map>
int k;//�ܵȼ���
struct bed {
	int tag;//�ô�λ��û�б�ռ,1��ʾ��ռ��0��ʾû�б�ռ
	char name[20];//��������
	long long ID;
	int age;//��������
	int sex;//�����Ա�
	int year;
	int month;
	int day;
};
struct room {//Ϊ�˷��������������ͬ�ȼ��µķ����ڵĴ�λ����ͬ��
	int sex;//��ס���Ա��ҵ������һ�������Ա�Ϊ��һ����ס�ÿ͵��Ա��������޷�����,0ΪŮ�ԣ�1Ϊ���ԣ�2Ϊ����
	int total;//���䴲λ����
	int leftover;//ʣ�ലλ�ĸ���
	bed beddie[200];
};
struct level {
	int roomnum;//�õȼ��·���ĸ���
	room roomie[200];
} levelling[200];

room* current;

//�Ƶ��ʼ������

void ini(){
	cout << "���Ѿ������ʼ��ϵͳ,֮���밴��ʾ��ʼ��" << endl;
	cout << "������Ƶ귿���ж��ٸ��ȼ�:" << endl;//k<=200
	cin >> k;
	for (int i = 1; i <= k; i++) {
		printf("���ʼ����%d���ȼ�������\n", i);
		cout << "������õȼ����ж��ٸ����䣬ÿ���������ж��ٸ���λ:" << endl;
		cin >> levelling[i].roomnum >> (levelling[i].roomie[i]).total;//�ٶ�ÿһ������������г�ʼ��
		for (int j = 1; j <= levelling[i].roomnum; j++) {
			levelling[i].roomie[j].sex = 2;
			levelling[i].roomie[j].total = levelling[i].roomie[i].total;
			levelling[i].roomie[j].leftover = levelling[i].roomie[j].total;
			//�������ٽ���ÿһ�������ڵĴ�λ���г�ʼ��
			for (int k = 1; k <= levelling[i].roomie[i].total;k++) {
				levelling[i].roomie[j].beddie[k].tag = 0;
		}
		}
	}
}
//��Ѱi�ȼ�����û�пշ���ʵ�ַ���Ǽ�
int allocate(int i,int sexy) {
	for (int j = 1; i <= levelling[i].roomnum; j++) {
		if (levelling[i].roomie[j].sex == 2 || levelling[i].roomie[j].sex == sexy) {
			for (int k = 1; k <= levelling[i].roomie[j].total; k++) {
				if (!levelling[i].roomie[j].beddie[k].tag)
				{
					cout << "��ϲ��������ɹ���" << endl;
					//�ټ����Ǽ���Ϣ
					levelling[i].roomie[j].beddie[k].tag = 1;
					if(levelling[i].roomie[j].leftover == levelling[i].roomie[j].total)
					levelling[i].roomie[j].sex = sexy;
					levelling[i].roomie[j].leftover--;
				    levelling[i].roomie[j].beddie[k].sex=sexy;
					cout << "��������������:" << endl;
					cin  >> levelling[i].roomie[j].beddie[k].name;
					cout << "�������������֤��:" << endl;
					cin  >> levelling[i].roomie[j].beddie[k].ID;
					cout << "��������������:" << endl;
					cin  >> levelling[i].roomie[j].beddie[k].age;
					cout << "���������������ڵ����:" << endl;
					cin  >> levelling[i].roomie[j].beddie[k].year;
					cout << "���������������ڵ��·�:" << endl;
					cin  >> levelling[i].roomie[j].beddie[k].month;
					cout << "���������������ڵ�����:" << endl;
					cin  >> levelling[i].roomie[j].beddie[k].day;
					cout << "���������ĵǼ���Ϣ�����ʵ" << endl;
					cout << "��������:" << endl;
					cout << levelling[i].roomie[j].beddie[k].name<<endl;
					cout << "�������֤��:" << endl;
					cout << levelling[i].roomie[j].beddie[k].ID <<endl;
					cout << "���������Ա�:" << endl;
					if (sexy == 1)
						cout << "��" << endl;
					else
						cout << "Ů" << endl;
					cout << "��������" << endl;
					cout << levelling[i].roomie[j].beddie[k].age<<endl;
					cout << "���������ڵ����:" << endl;
					cout << levelling[i].roomie[j].beddie[k].year<<endl;
					cout << "���������ڵ��·�:" << endl;
					cout << levelling[i].roomie[j].beddie[k].month<<endl;
					cout << "���������ڵ�����:" << endl;
					cout << levelling[i].roomie[j].beddie[k].day<<endl;
					cout << "���ķ���ȼ��ǣ�" <<k<< endl;
					cout << "���ķ������:" << j << endl;
					cout << "���Ĵ�λ����:" << k << endl;
					cout << "��ϲ������ɵǼǺͷ��䣬�����˳��ǼǺͷ���ϵͳ" << endl;
					return 1;
				}
			}
		}
	}
}
//�ÿ͵Ǽ�,���亯��
void signin() {
	//�ȵǼ��ٷ��䣻
	//�������Ա�
	cout << "���ѳɹ��������ÿ͵Ǽ�ϵͳ" << endl;
	int sex1;
	cout << "�����������Ա�,1�������ԣ�0����Ů��:" << endl;
	cin >> sex1;
	if (sex1 != 1 || sex1 != 0) {
		cout << "�������������˳�ϵͳ�Ǽ�ϵͳ" << endl;
			return;
	}
	//�ٷ���
	int temp=1;
	while (1) {
		printf("����Ϊ�������%d���ȼ��ķ���\n",temp);
		if (!allocate(temp,sex1)) {
			printf("�Բ��𣬵�%d���ȼ��ķ�����������������������ȼ���\n",temp);
			cout << "����1�����ǵģ�2������"<<endl;
			int ans;
			cin >> ans;
			if (ans == 2) {
				cout << "��Ȼ��ˣ�����Բ����Ѿ������ˣ��뻻һ���õ�" << endl;
				return;
			}
			else
			{
				cout << "�����������������" << endl;
				continue;
			}

		}
		else
			return;
		temp++;
		if (temp > k)
		{
			cout << "�Բ����Ѿ������ˣ��뻻һ���õ�" << endl;
			return;
		}
	}

}
//�ÿ���꺯��
void depart() {
	int i, j, k;
	cout << "���ѽ����ÿ����ϵͳ���밴����ʾ�����в���" << endl;
	cout << "���������ķ���ȼ��ţ�" << endl;
	cin >> i;
	cout << "���������ķ���ţ�" << endl;
	cin >> j;
	cout << "���������ķ��䴲λ�ţ�" << endl;
	cin >> k;
	levelling[i].roomie[j].leftover++;
	if (levelling[i].roomie[j].leftover == levelling[i].roomie[j].total)
		levelling[i].roomie[j].sex = 2;
	levelling[i].roomie[j].beddie[k].tag = 0;
	cout << "лл������ϣ����Ѿ��ɹ��Ǽ����ÿ����ϵͳ" << endl;
}
using namespace std;
int main() {
	int order1=100000;
	while(order1!=3)
	{
	cout << "    ���Գɹ��������ȷ��ϵͳ       " << endl;
	cout << "    ���������ִ������������ݻ��˳�      " << endl;
	cout << "    1->����Ա         2->�ÿ�        3->�˳����ȷ��ϵͳ" << endl;
	cin >> order1;
	if (order1 == 1) {
		int password;
		cout << "���������Ĺ���Ա���룺     " << endl;
		cin >> password;
		if (password == 666)
		{
			cout << "��¼�ɹ����뽨�����ݿ�" << endl;
			ini();
			cout << "������ɣ�" << endl;
		}
		else {
			cout << "������������ԣ�����" << endl;
			continue;
		}
	}
	if (order1 == 2) {
		while (1) {
			cout << "���Ѿ��ɹ������ÿ���������ϵͳ" << endl;
			cout << "�𾴵��ÿ����ã������������ʲô����" << endl;
			cout << "���������ִ��룬ִ�����²������" << endl;
			cout << "1->��ס�Ǽ�     2->���Ǽ�         3->�˳��ÿ���������ϵͳ" << endl;
			int order2;
			cin >> order2;
			if (order2 == 1) {
				signin();
				cout << endl;
			}
			if (order2 == 2) {
				depart();
				cout << endl;
			}
			if (order2 == 3)
				break;
			else
				cout << "�����������������" << endl;
			}
		}
	if (order1 == 3)
		break;
	else
	cout << "������������½���ϵͳ������" << endl;
	}

	return 0;
}
