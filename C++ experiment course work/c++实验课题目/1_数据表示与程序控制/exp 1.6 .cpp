#include <iostream>

using namespace std;
/*
int isleapyear(int x){//判断是否是闰年的函数
if(( x % 4 == 0 && x % 100 != 0 ) || (x % 400 == 0))
    return 1;
    return 0;
}
int monthly_leapdays[13]={31,29,31,30,31,30,31,31,30,31,30,31};//定义月份数组，方便直接乘
int monthly_days[13]={31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
    int year,month,day;
    int totaldays=0;
    cout << "please enter year month day,input 0 0 0 to end:" << endl;
    cin >> year >> month >> day;
    if( month > 12 || day > 31)//特判
    {
    cout << "error!Month shouldn't be more than 12 and day shouldn't be more than 31!" << endl;
    return 0;
    }
    while(year != 0 && month != 0 && month != 0)
    {
       int  totaldays = 0;
    for (int i = 1;i < year;i++)//年份的天数相加
        {
          if(isleapyear(i))
          totaldays += 366;
          else totaldays += 365;
        }
    if(isleapyear(year))
    for(int j=0;j<month-1;j++){//月份的天数相加
        totaldays += monthly_leapdays[j];
    }
    else {
        for(int j=0;j<month-1;j++){
           totaldays += monthly_days[j];
        }
    }
    totaldays += day;//天数
    int weekday = totaldays % 7;//星期几
    cout << year << "年" << month << "月" << day << "日" << "是星期" << weekday << endl;
    cout << "please enter year month day,input 0 0 0 to end:" << endl;
    cin >> year >> month >> day;
    if( month > 12 || day > 31)
    {
    cout << "error!Month shouldn't be more than 12 and day shouldn't be more than 31!" << endl;
    return 0;
    }
    }
    return 0;
}*/
int isleapyear(int x){
if(( x % 4 == 0 && x % 100 != 0 ) || (x % 400 == 0))
    return 1;
    return 0;
}
int monthly_leapdays[13]={31,29,31,30,31,30,31,31,30,31,30,31};
int monthly_days[13]={31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
    int year,month,day;
    int totaldays=0;
    cout << "please enter year month day,input 0 0 0 to end:" << endl;
    cin >> year >> month >> day;
    if( month > 12 || day > 31)
    {
    cout << "error!Month shouldn't be more than 12 and day shouldn't be more than 31!" << endl;
    return 0;
    }
    while(year != 0 && month != 0 && month != 0)
    {
       int  totaldays = 0;
       for (int i = 1;i < year;i++)
        {
          switch(isleapyear(i)){
      case 1:
        totaldays+=366;
        break;
      case 0:
        totaldays+=365;
        break;

          }
        }
        switch(isleapyear(year)){
    case 1:
        for(int j=0;j<month-1;j++)
        totaldays += monthly_leapdays[j];
        break;
    case 0:
        for(int j=0;j<month-1;j++)
        totaldays += monthly_days[j];
        break;
        }
    totaldays += day;
    int weekday = totaldays % 7;
    cout << year << "年" << month << "月" << day << "日" << "是星期" << weekday << endl;
    cout << "please enter year month day,input 0 0 0 to end:" << endl;
    cin >> year >> month >> day;
    if( month > 12 || day > 31)
    {
    cout << "error!Month shouldn't be more than 12 and day shouldn't be more than 31!" << endl;
    return 0;
    }
    }
return 0;
}
