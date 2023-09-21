#include <iostream>

using namespace std;
/*
int main()
{
    int work_time,wage_per_hour;
    double wages;//由于程序很简单我就不写注释了，真的很简单
    cout<<"Please input employee's work_time and wage_per_hour:"<<endl;
    cin >> work_time >> wage_per_hour;
    if (work_time>72 || work_time < 0)//特判
    {
        cout << "error occurred!work_time should be less than 72 and no less than 0!" <<endl;
        return 0;
    }
    if (work_time <= 40)
        wages = work_time * wage_per_hour;
    if (work_time > 40 && work_time <= 60)
        wages = 40 * wage_per_hour + (work_time - 40) * 1.5 * wage_per_hour;
    if (work_time > 60)
        wages = 40 * wage_per_hour + 20*1.5*wage_per_hour + (work_time-60) * wage_per_hour;
    cout << "The employee's wage:" << endl;
    cout << wages << endl;
    return 0;
}
*/
    int main()
{
    int work_time,wage_per_hour;
    double wages;
    cout<<"Please input employee's work_time and wage_per_hour:"<<endl;

    cin >> work_time >> wage_per_hour;
    if(work_time>72 || work_time < 0)//特判
    {
        cout << "error occurred!work_time should be less than 72 and no less than 0!" <<endl;
        return 0;
    }
    int count1;
    if(work_time <= 60)
    count1 = work_time/20;
    else count1 = 3;
    switch(count1){
case 0:
    wages = work_time * wage_per_hour;
    break;
case 1:
    wages = work_time * wage_per_hour;
    break;
case 2:
    wages = 40 * wage_per_hour + (work_time - 40) * 1.5 * wage_per_hour;
    break;
case 3:
    wages = 40 * wage_per_hour + 20*1.5*wage_per_hour + (work_time-60) * wage_per_hour;
    break;
    }
    cout << wages;
    return 0;
}
