#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void basaekle(struct Node **head, int _data)
{
    struct Node *gecici = (struct Node *)malloc(sizeof(struct Node));
    gecici->data = _data;
    gecici->next = (*head);
    (*head) = gecici;
}

void yazdir(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
}

int getSize(struct Node *head)
{
    int count = 0;
    struct Node *current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

int getSizeWithRecursion(struct Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        return getSizeWithRecursion(head->next) + 1;
    }
}

int getMaxValue(struct Node *head)
{
    struct Node *current = head;
    int max = 0;

    if (head == NULL)
    {
        return;
    }
    else
    {
        max = head->data;

        while (current != NULL)
        {
            if (max < current->data)
            {
                max = current->data;
            }
            current = current->next;
        }

        return max;
    }
}
int setOrder(struct Node *node)
{
    int[] array;

    for (int i = 0; i <= getMaxValue(); i++)
    {
        }
}
int main()
{
    struct Node *head = NULL;

    basaekle(&head, 2);
    basaekle(&head, 7);
    basaekle(&head, 5);
    basaekle(&head, 70);
    basaekle(&head, 8);
    basaekle(&head, 4);
    basaekle(&head, 24);

    yazdir(head);

    printf("\nCount:");
    printf("%d", getSize(head));

    printf("\nCount with recursion:");
    printf("%d", getSizeWithRecursion(head));

    printf("\n%d", getMaxValue(head));

    return 0;
}
