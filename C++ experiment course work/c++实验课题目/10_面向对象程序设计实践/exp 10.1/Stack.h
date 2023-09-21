#pragma once

const int MaxSize = 500;
class Stack
{
private:
    char stack[MaxSize];
    char* top;
    int len;
public:
    Stack();
    void InitStack();
    void Push(char item);
    char Pop();
    char Peek();
    bool IsEmpty();
    void ClearStack();
};