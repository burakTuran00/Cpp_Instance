#include <iostream>
#include <chrono>
#include <bits/stdc++.h>

using namespace std::chrono;

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

void group(Node *head, int maxRepeat)
{
    int size = getSize(head);
    int max = getMaxElement(head);

    Node *temp = head;

    int array[size];
    int index = 0;
    int array2[max];

    while (temp != NULL)
    {
        array[index] = temp->data;
        index++;

        temp = temp->next;
    }

    std::sort(array, array + size);

    int counter = 0;

    for (int i = 0; i < max; i++)
    {
        counter = 0;
        for (int j = 0; j < size; j++)
        {
            if ((i + 1) == array[j])
            {
                counter++;
            }
        }

        array2[i] = counter;
    }

    /*for (auto value : array)
    {
        std::cout << value << " ";
    }

    std::cout << std::endl;

    for (int i = 0; i < max; i++)
    {
        std::cout << i + 1 << "-" << array2[i] << " ";
    }*/

    std::cout << std::endl;

    for (int i = 0; i < max; i++)
    {
        if (array2[i] > maxRepeat)
        {
            for (int j = 0; j < maxRepeat; j++)
            {
                std::cout << i + 1 << " ";
            }
        }
        else if (array2[i] == 0)
        {
            continue;
        }
        else
        {
            for (int k = 0; k < array2[i]; k++)
            {
                std::cout << i + 1 << " ";
            }
        }
    }
}

// in worst case, O(n^2)
// 2000 ms +- 500
// 1 second = 1000000 ms
// 2 x 10^(-9) second = 2000 ms

int main()
{
    auto start = high_resolution_clock::now();

    Node *head = NULL;

    add_begin(&head, 5);
    add_begin(&head, 4);
    add_begin(&head, 7);
    add_begin(&head, 6);
    add_begin(&head, 6);
    add_begin(&head, 11);
    add_begin(&head, 7);
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

    group(head, 10);
    group(head, 3);
    group(head, 2);
    group(head, 1);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    std::cout << "\nms:" << duration.count() << std::endl;

    return 0;
}