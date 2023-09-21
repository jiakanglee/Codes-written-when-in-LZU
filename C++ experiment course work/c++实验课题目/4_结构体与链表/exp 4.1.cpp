#include<iostream>
using namespace std;
int monthly_days[13] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
struct date{
	int year;
	int month;
	int day;
};
int isleapyear(int x) {
	if ((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0))
		return 1;
	return 0;
}
int main() {
	date a;
	date* p = &a;
	cout << "please enter year month day,input 0 0 0 to end:" << endl;
	cin >> p->year;
	cin >> p->month;
	cin >> p->day;
    if (p->month > 12 || p->day > 31)//输入检查
    {
        cout << "error!Month shouldn't be more than 12 and day shouldn't be more than 31!" << endl;
        return 0;
    }
    while (p->year != 0 && p->month != 0 && p->month != 0)//计算年+月
    {
        int  totaldays = 0;
        for (int i = 1; i < p->year; i++)
        {
            switch (isleapyear(i)) {
            case 1:
                totaldays += 366;
                break;
            case 0:
                totaldays += 365;
                break;

            }
        }
        switch (isleapyear(p->year)) {//考虑闰年
        case 1:
            for (int j = 0; j < p->month - 1; j++)
                totaldays += monthly_days[j];
            break;
        case 0:
            for (int j = 0; j < p->month - 1; j++)
                totaldays += monthly_days[j];
            break;
        }
        totaldays += p->day;
        int weekday = totaldays % 7;
        cout << p->year << "年" << p->month << "月" << p->day << "日" << "是星期" << weekday << endl;
        cout << "please enter year month day,input 0 0 0 to end:" << endl;
        cin >> p->year >> p->month >> p->day;
        if (p->month > 12 || p->day > 31)
        {
            cout << "error!Month shouldn't be more than 12 and day shouldn't be more than 31!" << endl;
            return 0;
        }
    }
    cout << "size of the Struct date is " << sizeof(a) << endl;
    cout << "size of year is " << sizeof(p->year) << endl;
    cout << "size of month is " << sizeof(p->month) << endl;
    cout << "size of day is " << sizeof(p->day) << endl;
	return 0;
}