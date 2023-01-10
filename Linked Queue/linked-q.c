#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enq()
{
    int data;
    printf("Enter a number : ");
    scanf("%d", &data);

    struct node *ptr = rear;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    if (rear == NULL)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

void deq()
{
    struct node *ptr = front, *temp = front;
    if (temp == NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        temp = temp->next;
        front = temp;
        free(ptr);
    }
}

void display()
{

    struct node *temp = front;

    if (temp == NULL)
    {
        printf("Queue empty\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void main()
{
    // choice
    int ch;
    do
    {
        printf("Enter choice:\n1. Enqueue\n2. Dequeue\n3. Display\n0: Exit\n");
        printf("\n-> ");
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 1:
            enq();
            printf("\n");
            break;
        case 2:
            deq();
            printf("\n");
            break;
        case 3:
            display();
            printf("\n");
            break;
        default:
            printf("\n");
        }
    } while (ch != 0);
}
