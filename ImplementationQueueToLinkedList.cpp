#include <bits/stdc++.h>

class Node
{
public:
    int data;
    Node *next;
};

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
}