#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push()
{

    int data;
    printf("Enter a number : ");
    scanf("%d", &data);

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    temp->next = top;
    top = temp;
}

void pop()
{

    struct node *ptr = top, *temp = top;
    if (temp == NULL)
    {
        printf("Underflow!\n");
    }
    else
    {
        temp = temp->next;
        top = temp;
        free(ptr);
    }
}
void topf()
{

    struct node *temp = top;

    if (temp == NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        printf("%d\n", temp->data);
    }
}
void display()
{
    struct node *temp = top;

    if (temp == NULL)
        printf("Linked list is empty\n");
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
        printf("Enter choice:\n1. Push\n2. Pop\n3. Top\n4. Display\n0: Exit\n");
        printf("\n-> ");
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 1:
            push();
            printf("\n");
            break;
        case 2:
            pop();
            printf("\n");
            break;
        case 3:
            topf();
            printf("\n");
            break;
        case 4:
            display();
            printf("\n");
            break;
        default:
            printf("\n");
        }
    } while (ch != 0);
}