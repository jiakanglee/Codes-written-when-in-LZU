#include "Stack.h"
#include <iostream>
using namespace std;
Stack::Stack()
{
    InitStack();
}

void Stack::InitStack()
{
    len = 0;
    top = stack;
}

void Stack::Push(char item)
{

    if (len < 500)
    {
        stack[len] = item;
        top = &stack[len];
        len++;
    }
    else
    {
        cout << "The stack is full." << endl;
    }
}

char Stack::Pop()
{

    if (!IsEmpty())
    {
        char temp = *top;
        top = &stack[len - 1];
        len--;
        return temp;
    }
    else
    {
        cout << "The stack is empty." << endl;
        return '\0';
    }
}

char Stack::Peek()
{
    if (!IsEmpty())
    {
        return *top;
    }
    else
    {
        cout << "The stack is empty." << endl;
        return '\0';
    }
}

bool Stack::IsEmpty()
{
    return (len == 0);
}


void Stack::ClearStack()
{
    len = 0;
    top = stack;
}