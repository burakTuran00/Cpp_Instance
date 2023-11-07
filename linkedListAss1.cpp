#include <iostream>
#include <math.h>
#include <array>
#include <bits/stdc++.h>

class Node
{
public:
    int data;
    Node *next;
};

void add_begin(Node **head, int data)
{
    Node *current = new Node();
    current->data = data;
    current->next = (*head);
    (*head) = current;
}

void add_at_position(Node *head, int data, int position)
{
    Node *ptr = head;
    Node *ptr2 = new Node();
    ptr2->data = data;
    ptr2->next = NULL;

    position--;
    while (position != 1)
    {
        ptr = ptr->next;
        position--;
    }

    /*for (int i = position; i != 1; i--)
    {
         ptr = ptr->next;
    }*/

    ptr2->next = ptr->next;
    ptr->next = ptr2;
}

void add_end(Node **head, int data)
{
    Node *ptr = (*head);

    Node *current = new Node();
    current->data = data;
    current->next = NULL;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    current->next = ptr->next;
    ptr->next = current;
}

void print(Node *node)
{

    while (node != NULL)
    {
        std::cout << node->data << " ";
        node = node->next;
    }

    std::cout << "" << std::endl;
}

int search(Node *head, int data)
{
    Node *ptr = head;
    int index = 0;

    while (ptr->next != NULL)
    {
        if (ptr->data == data)
        {
            return index;
        }

        index++;
        ptr = ptr->next;
    }

    return -1;
}

void delete_at_position(Node **head, int position)
{
    Node *current = *head;
    Node *previous = *head;

    if (*head == NULL)
    {
        std::cout << "List is already empty!" << std::endl;
    }
    else if (position == 1)
    {
        *head = current->next;
        free(current);
        current = NULL;
    }
    else
    {
        while (position != 1)
        {
            previous = current;
            current = current->next;
            position--;
        }

        previous->next = current->next;
        free(current);
        current = NULL;
    }
}

int getMaxElement(Node *head)
{
    int maxValue = 0;
    Node *temp = head;

    while (temp->next != NULL)
    {
        if (maxValue < temp->data)
        {
            maxValue = temp->data;
        }

        temp = temp->next;
    }

    return maxValue;
}

int getSize(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

Node *swap(Node *ptr1, Node *ptr2)
{
    Node *temp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = temp;
    return ptr2;
}

void bubbleSort(Node **head)
{
    Node **h;
    int i, j, swapped;
    int size = getSize(*head);

    for (i = 0; i <= size; i++)
    {
        h = head;
        swapped = 0;

        for (j = 0; j < size - i - 1; j++)
        {
            Node *p1 = *h;
            Node *p2 = p1->next;

            if (p1->data > p2->data)
            {
                *h = swap(p1, p2);
                swapped = 1;
            }

            h = &(*h)->next;
        }
    }

    if (swapped == 0)
    {
        return;
    }
}

void group(Node *head, int maxRepeat)
{
    int size = getSize(head);
    int max = getMaxElement(head);

    Node *temp = head;

    int array[size];
    std::list<int> depositList;
    int index = 0;

    bubbleSort(&head);

    while (temp != NULL)
    {
        array[index] = temp->data;
        index++;
        temp = temp->next;
    }

    int counter = 0;

    for (int i = 0; i <= max; i++)
    {
        counter = 0;
        for (int j = 1; j <= max; j++)
        {
            if (j == i)
            {
                counter++;
            }
        }
        depositList.push_front(counter);
    }

    for (int value : array)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    for (auto value : depositList)
    {
        std::cout << value << " ";
    }
}

int main()
{
    Node *head = NULL;

    add_begin(&head, 5);
    add_begin(&head, 4);
    add_begin(&head, 7);
    add_begin(&head, 6);
    add_begin(&head, 6);
    add_begin(&head, 5);
    add_begin(&head, 4);
    add_begin(&head, 1);
    add_begin(&head, 6);
    add_begin(&head, 5);
    add_begin(&head, 3);
    add_begin(&head, 2);
    add_begin(&head, 5);
    add_begin(&head, 4);
    add_begin(&head, 3);
    add_begin(&head, 1);

    group(head, 1);

    return 0;
}