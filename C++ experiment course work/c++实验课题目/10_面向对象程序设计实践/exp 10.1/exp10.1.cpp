#include <iostream> 
#include <fstream> 
#include <string> 
#include "Stack.h"
//����elemtype����Ϊchar��
using namespace std;
int main()
{
    Stack iStack;
    ifstream fin;
    string str;
    bool result = false;

    iStack.InitStack();


    fin.open("C:/Users/45373/Desktop/private file/c++ʵ�����Ŀ/10_�������������ʵ��/test_for_comparing.txt");
    if (fin.fail())
    {
        cout << "File open error!";
        exit(1);
    }
    int i = 0;
    while (getline(fin, str))  //���{}������
    {
        i = 0;
        while ('\0' != str[i])
        {
            if ('{' == str[i])
            {
                iStack.Push('{');
            }
            else if ('}' == str[i] && '{' == iStack.Peek())
            {
                iStack.Pop();
            }
            i++;
        }
    }
   /* while (getline(fin, str))  //���[]������
    {
        i = 0;
        while ('\0' != str[i])
        {
            if ('[' == str[i])
            {
                iStack.Push('{');
            }
            else if (']' == str[i] && '[' == iStack.Peek())
            {
                iStack.Pop();
            }
            i++;
        }
    }*/


    /*while (getline(fin, str))  //���()������
    {
        i = 0;
        while ('\0' != str[i])
        {
            if ('(' == str[i])
            {
                iStack.Push('(');
            }
            else if (')' == str[i] && '(' == iStack.Peek())
            {
                iStack.Pop();
            }
            i++;
        }
    }*/
    result = iStack.IsEmpty(); //��������ջ�գ����resultΪ1˵�����
    cout << result << endl;

    return 0;
}