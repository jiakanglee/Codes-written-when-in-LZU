//床位分配,ready to die!
#include <cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<string.h>
#include<queue>
#include<map>
int k;//总等级数
struct bed {
	int tag;//该床位有没有被占,1表示被占，0表示没有被占
	char name[20];//客人姓名
	long long ID;
	int age;//客人年龄
	int sex;//客人性别
	int year;
	int month;
	int day;
};
struct room {//为了方便起见，假设相同等级下的房间内的床位数相同。
	int sex;//入住的性别，我的理解是一个房间性别为第一个入住旅客的性别，且异性无法分配,0为女性，1为男性，2为待定
	int total;//房间床位个数
	int leftover;//剩余床位的个数
	bed beddie[200];
};
struct level {
	int roomnum;//该等级下房间的个数
	room roomie[200];
} levelling[200];

room* current;

//酒店初始化函数

void ini(){
	cout << "您已经进入初始化系统,之后请按提示初始化" << endl;
	cout << "请输入酒店房间有多少个等级:" << endl;//k<=200
	cin >> k;
	for (int i = 1; i <= k; i++) {
		printf("请初始化第%d个等级的内容\n", i);
		cout << "请输入该等级下有多少个房间，每个房间下有多少个床位:" << endl;
		cin >> levelling[i].roomnum >> (levelling[i].roomie[i]).total;//再对每一个下属房间进行初始化
		for (int j = 1; j <= levelling[i].roomnum; j++) {
			levelling[i].roomie[j].sex = 2;
			levelling[i].roomie[j].total = levelling[i].roomie[i].total;
			levelling[i].roomie[j].leftover = levelling[i].roomie[j].total;
			//接下来再进入每一个房间内的床位进行初始化
			for (int k = 1; k <= levelling[i].roomie[i].total;k++) {
				levelling[i].roomie[j].beddie[k].tag = 0;
		}
		}
	}
}
//搜寻i等级下有没有空房并实现分配登记
int allocate(int i,int sexy) {
	for (int j = 1; i <= levelling[i].roomnum; j++) {
		if (levelling[i].roomie[j].sex == 2 || levelling[i].roomie[j].sex == sexy) {
			for (int k = 1; k <= levelling[i].roomie[j].total; k++) {
				if (!levelling[i].roomie[j].beddie[k].tag)
				{
					cout << "恭喜您，分配成功！" << endl;
					//再继续登记信息
					levelling[i].roomie[j].beddie[k].tag = 1;
					if(levelling[i].roomie[j].leftover == levelling[i].roomie[j].total)
					levelling[i].roomie[j].sex = sexy;
					levelling[i].roomie[j].leftover--;
				    levelling[i].roomie[j].beddie[k].sex=sexy;
					cout << "请输入您的名字:" << endl;
					cin  >> levelling[i].roomie[j].beddie[k].name;
					cout << "请输入您的身份证号:" << endl;
					cin  >> levelling[i].roomie[j].beddie[k].ID;
					cout << "请输入您的年龄:" << endl;
					cin  >> levelling[i].roomie[j].beddie[k].age;
					cout << "请输入您到达日期的年份:" << endl;
					cin  >> levelling[i].roomie[j].beddie[k].year;
					cout << "请输入您到达日期的月份:" << endl;
					cin  >> levelling[i].roomie[j].beddie[k].month;
					cout << "请输入您到达日期的天数:" << endl;
					cin  >> levelling[i].roomie[j].beddie[k].day;
					cout << "以下是您的登记信息，请核实" << endl;
					cout << "您的名字:" << endl;
					cout << levelling[i].roomie[j].beddie[k].name<<endl;
					cout << "您的身份证号:" << endl;
					cout << levelling[i].roomie[j].beddie[k].ID <<endl;
					cout << "您的年龄性别:" << endl;
					if (sexy == 1)
						cout << "男" << endl;
					else
						cout << "女" << endl;
					cout << "您的年龄" << endl;
					cout << levelling[i].roomie[j].beddie[k].age<<endl;
					cout << "您到达日期的年份:" << endl;
					cout << levelling[i].roomie[j].beddie[k].year<<endl;
					cout << "您到达日期的月份:" << endl;
					cout << levelling[i].roomie[j].beddie[k].month<<endl;
					cout << "您到达日期的天数:" << endl;
					cout << levelling[i].roomie[j].beddie[k].day<<endl;
					cout << "您的房间等级是：" <<k<< endl;
					cout << "您的房间号是:" << j << endl;
					cout << "您的床位号是:" << k << endl;
					cout << "恭喜您已完成登记和分配，正在退出登记和分配系统" << endl;
					return 1;
				}
			}
		}
	}
}
//旅客登记,分配函数
void signin() {
	//先登记再分配；
	//先输入性别
	cout << "您已成功进入了旅客登记系统" << endl;
	int sex1;
	cout << "请输入您的性别,1代表男性，0代表女性:" << endl;
	cin >> sex1;
	if (sex1 != 1 || sex1 != 0) {
		cout << "输入有误，正在退出系统登记系统" << endl;
			return;
	}
	//再分配
	int temp=1;
	while (1) {
		printf("正在为您分配第%d个等级的房间\n",temp);
		if (!allocate(temp,sex1)) {
			printf("对不起，第%d个等级的房间已满，您还想继续更换等级吗？\n",temp);
			cout << "输入1代表是的，2代表不想"<<endl;
			int ans;
			cin >> ans;
			if (ans == 2) {
				cout << "既然如此，本店对不起已经满客了，请换一家旅店" << endl;
				return;
			}
			else
			{
				cout << "输入错误请重新输入" << endl;
				continue;
			}

		}
		else
			return;
		temp++;
		if (temp > k)
		{
			cout << "对不起已经满客了，请换一家旅店" << endl;
			return;
		}
	}

}
//旅客离店函数
void depart() {
	int i, j, k;
	cout << "您已进入旅客离店系统，请按照提示，进行操作" << endl;
	cout << "请输入您的房间等级号：" << endl;
	cin >> i;
	cout << "请输入您的房间号：" << endl;
	cin >> j;
	cout << "请输入您的房间床位号：" << endl;
	cin >> k;
	levelling[i].roomie[j].leftover++;
	if (levelling[i].roomie[j].leftover == levelling[i].roomie[j].total)
		levelling[i].roomie[j].sex = 2;
	levelling[i].roomie[j].beddie[k].tag = 0;
	cout << "谢谢您的配合，您已经成功登记完旅客离店系统" << endl;
}
using namespace std;
int main() {
	int order1=100000;
	while(order1!=3)
	{
	cout << "    您以成功进入身份确认系统       " << endl;
	cout << "    请输入数字代码代表您的身份或退出      " << endl;
	cout << "    1->管理员         2->旅客        3->退出身份确认系统" << endl;
	cin >> order1;
	if (order1 == 1) {
		int password;
		cout << "请输入您的管理员密码：     " << endl;
		cin >> password;
		if (password == 666)
		{
			cout << "登录成功！请建立数据库" << endl;
			ini();
			cout << "建立完成！" << endl;
		}
		else {
			cout << "密码错误请重试！！！" << endl;
			continue;
		}
	}
	if (order1 == 2) {
		while (1) {
			cout << "您已经成功进入旅客自助服务系统" << endl;
			cout << "尊敬的旅客您好，请问你想办理什么服务？" << endl;
			cout << "请输入数字代码，执行如下操作命令。" << endl;
			cout << "1->入住登记     2->离店登记         3->退出旅客自助服务系统" << endl;
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
				cout << "输入错误请重新输入" << endl;
			}
		}
	if (order1 == 3)
		break;
	else
	cout << "输入错误请重新进入系统再输入" << endl;
	}

	return 0;
}
