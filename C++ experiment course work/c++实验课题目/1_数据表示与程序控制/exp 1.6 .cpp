#include <iostream>

using namespace std;
/*
int isleapyear(int x){//�ж��Ƿ�������ĺ���
if(( x % 4 == 0 && x % 100 != 0 ) || (x % 400 == 0))
    return 1;
    return 0;
}
int monthly_leapdays[13]={31,29,31,30,31,30,31,31,30,31,30,31};//�����·����飬����ֱ�ӳ�
int monthly_days[13]={31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
    int year,month,day;
    int totaldays=0;
    cout << "please enter year month day,input 0 0 0 to end:" << endl;
    cin >> year >> month >> day;
    if( month > 12 || day > 31)//����
    {
    cout << "error!Month shouldn't be more than 12 and day shouldn't be more than 31!" << endl;
    return 0;
    }
    while(year != 0 && month != 0 && month != 0)
    {
       int  totaldays = 0;
    for (int i = 1;i < year;i++)//��ݵ��������
        {
          if(isleapyear(i))
          totaldays += 366;
          else totaldays += 365;
        }
    if(isleapyear(year))
    for(int j=0;j<month-1;j++){//�·ݵ��������
        totaldays += monthly_leapdays[j];
    }
    else {
        for(int j=0;j<month-1;j++){
           totaldays += monthly_days[j];
        }
    }
    totaldays += day;//����
    int weekday = totaldays % 7;//���ڼ�
    cout << year << "��" << month << "��" << day << "��" << "������" << weekday << endl;
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
    cout << year << "��" << month << "��" << day << "��" << "������" << weekday << endl;
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
