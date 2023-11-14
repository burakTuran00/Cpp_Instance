#include <iostream>
#include <stack>
using namespace std;

void printStack(stack<int> stack)
{
    while (!stack.empty())
    {
        cout << stack.top() << endl; // get the top element of the stack
        stack.pop();
    }
}

int main()
{
    stack<int> numbersStack;

    numbersStack.push(1); // add top of the stack
    numbersStack.push(2);
    numbersStack.push(3); // remove top of the element

    numbersStack.pop();

    if (numbersStack.empty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }

    cout << "Size of Stack: " << numbersStack.size() << endl;

    printStack(numbersStack);

    return 0;
}