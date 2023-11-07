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

void add_at_position(struct Node *head, int data, int position)
{
    struct Node *ptr = head;
    struct Node *ptr2 = malloc(sizeof(struct Node));
    ptr2->data = data;
    ptr2->next = NULL;

    position--;

    while (position != 1)
    {
        ptr = ptr->next;
        position--;
    }

    ptr2->next = ptr->next;
    ptr->next = ptr2;
}

/*void sonaEkle(struct Node **head, int data)
{
    struct Node *gecici = (struct Node *)malloc(sizeof(struct Node));
    gecici->data = data;
    gecici->data = NULL;
}*/

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

int main()
{
    struct Node *head = NULL;

    basaekle(&head, 2);
    basaekle(&head, 7);
    basaekle(&head, 5);
    basaekle(&head, 8);
    basaekle(&head, 4);
    basaekle(&head, 24);

    add_at_position(head, 99, 5);

    yazdir(head);

    printf("\nCount:");
    printf("%d", getSize(head));

    printf("\nCount with recursion:");
    printf("%d", getSizeWithRecursion(head));

    return 0;
}
