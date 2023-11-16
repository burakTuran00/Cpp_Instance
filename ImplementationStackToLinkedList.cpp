#include <bits/stdc++.h>

class Node
{
public:
    int data;
    Node *next;
};

Node *top = NULL;

void push(int data)
{
    Node *newNode = new Node();

    if (newNode == NULL)
    {
        std::cout << "Stack Overflow" << std::endl;
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    newNode->next = top;
    top = newNode;
}

int pop()
{
    Node *temp = top;
    int value = temp->data;

    top = top->next;
    free(temp);
    temp = NULL;

    return value;
}

bool isEmpty()
{
    if (top != NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int peek()
{
    if (isEmpty())
    {
        std::cout << "Stack Undeflow" << std::endl;
        exit(1);
    }

    return top->data;
}

void print()
{
    Node *temp = top;

    while (temp != NULL)
    {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }
}

int main()
{

    push(1);
    push(5);
    push(12);

    print();

    std::cout << "isEmpty: " << isEmpty() << std::endl;
    std::cout << "Top Data Of The Stack: " << peek() << std::endl;

    return 0;
}