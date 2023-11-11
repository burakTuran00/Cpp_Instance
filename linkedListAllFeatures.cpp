#include <iostream>
#include <math.h>
#include <limits>

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

Node *delete_first(Node *head)
{
    if (head == NULL)
    {
        std::cout << "List is already empty!" << std::endl;
    }
    else
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        temp = NULL;
    }

    return head;
}

Node *delete_last(Node *head)
{
    if (head == NULL)
    {
        std::cout << "List is already empty!" << std::endl;
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        Node *temp = head;
        Node *temp2 = head;

        while (temp->next != NULL)
        {
            temp2 = temp;
            temp = temp->next;
        }

        temp2->next = NULL;

        free(temp);
        temp = NULL;
    }

    return head;
}

Node *delete_last_WithOnePointer(Node *head)
{
    if (head == NULL)
    {
        std::cout << "List is already empty!" << std::endl;
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        Node *temp = head;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;
    }

    return head;
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

Node *delete_entire_list(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        free(head);
        head = temp;
    }

    return head;
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

int getMinElement(Node *head)
{
    int minValue = 100000; // adjust max value you can do
    Node *temp = head;

    while (temp->next != NULL)
    {
        if (minValue > temp->data)
        {
            minValue = temp->data;
        }

        temp = temp->next;
    }

    return minValue;
}

int getSecondMinElement(Node *head)
{
    if (head == nullptr)
        return -1;

    int smallest = 100000;
    int secondSmallest = 100000;

    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data < smallest)
        {
            secondSmallest = smallest;
            smallest = temp->data;
        }
        else if (temp->data < secondSmallest && temp->data != smallest)
        {
            secondSmallest = temp->data;
        }

        temp = temp->next;
    }

    return secondSmallest;
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

double getAverage(Node *head)
{
    double sum = 0;
    int size = getSize(head);

    Node *temp = head;

    while (temp != NULL)
    {
        sum += temp->data;
        temp = temp->next;
    }

    return sum / size;
}

Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *next = NULL;

    while (head != NULL)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    head = prev;
    return head;
}

void findSumAndMulThanSmallerK(Node *head, int k)
{
    Node *current = head;

    int sum = 0;
    int mul = 1;

    while (current != NULL)
    {
        if (current->data < k)
        {
            sum += current->data;
            mul *= current->data;
        }

        current = current->next;
    }

    std::cout << "Addition: " << sum << "\nMultiplication: " << mul << std::endl;
}

void findOddNumbersSum(Node *head)
{
    Node *temp = head;
    int sum = 0;

    while (temp != NULL)
    {
        if (temp->data % 2 != 0)
        {
            sum += temp->data;
        }

        temp = temp->next;
    }

    std::cout << "Sum of the odd numbers: " << sum << std::endl;
}

int main()
{
    Node *head = NULL;

    add_begin(&head, 1);
    add_begin(&head, 2);
    add_begin(&head, 5);
    add_begin(&head, 7);
    add_begin(&head, 8);
    add_begin(&head, 201);
    add_end(&head, 25);
    add_end(&head, 70);

    // head = delete_last(head);
    // head = delete_last(head);
    // delete_at_position(&head, 1);

    // head = reverse(head);

    findSumAndMulThanSmallerK(head, 10);
    std::cout << "Second smallest: " << getSecondMinElement(head) << std::endl;
    findOddNumbersSum(head);
    print(head);

    /* std::cout << "\nIndex::" << search(head, 25) << std::endl;
    std::cout << "Size::" << getSize(head) << std::endl;
    std::cout << "Average::" << getAverage(head) << std::endl;
    std::cout << "Max Value::" << getMaxElement(head) << std::endl;
    std::cout << "Min Value::" << getMinElement(head) << std::endl;
    */

    /*head = delete_entire_list(head);
    print(head);
    std::cout << "Size::" << getSize(head) << std::endl;*/

    return 0;
}