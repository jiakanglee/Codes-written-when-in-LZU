#include <iostream> 
#include <fstream> 
#include <string> 
#include "Stack.h"
//这里elemtype假设为char型
using namespace std;
int main()
{
    Stack iStack;
    ifstream fin;
    string str;
    bool result = false;

    iStack.InitStack();


    fin.open("C:/Users/45373/Desktop/private file/c++实验课题目/10_面向对象程序设计实践/test_for_comparing.txt");
    if (fin.fail())
    {
        cout << "File open error!";
        exit(1);
    }
    int i = 0;
    while (getline(fin, str))  //检查{}配对情况
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
   /* while (getline(fin, str))  //检查[]配对情况
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


    /*while (getline(fin, str))  //检查()配对情况
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
    result = iStack.IsEmpty(); //配对情况是栈空，如果result为1说明配对
    cout << result << endl;

    return 0;
}