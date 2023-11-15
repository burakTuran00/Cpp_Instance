#include <bits/stdc++.h>
#include <array>
#define MAX 4

int stack_Arr[MAX]; // global declaration
int top = -1;       // indicates that the stack is empty

void push(int data)
{
    if (top == MAX - 1)
    {
        std::cout << "Stack Overflow" << std::endl;
        return;
    }

    top++;
    stack_Arr[top] = data;
}

int pop()
{
    if (top == -1)
    {
        std::cout << "Stack UnderFlow" << std::endl;
        exit(1); // abnormal termination of the program.
    }

    int value;
    value = stack_Arr[top];
    stack_Arr[top] = 0;
    top--;

    return value;
}

void printStack()
{
    for (auto value : stack_Arr)
    {
        if (value != 0)
            std::cout << value << " ";
    }
}

int main()
{
    push(1);
    push(10);
    push(20);
    int data = pop();

    printStack();

    std::cout << "\nRemoved Data: " << data << std::endl;

    return 0;
}