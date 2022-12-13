#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
void insertBeg()
{
    int data;
    printf("Enter data to insert: ");
    scanf("%d", &data);

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    if (head != NULL)
    {
        temp->next = head;
    }
    head = temp;
}

void insertEnd()
{
    int data;
    printf("Enter data to insert: ");
    scanf("%d", &data);

    struct node *ptr = head;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void insertBet()
{
    int data, pos;
    printf("Enter data to insert: ");
    scanf("%d", &data);

    printf("\nEnter element to insert after: ");
    scanf("%d", &pos);

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    struct node *ptr = head;
    if (ptr == NULL)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        while (ptr->data != pos)
        {
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
}

void deleteBeg()
{
    struct node *ptr = head, *temp = head;
    if (temp == NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        temp = temp->next;
        head = temp;
        free(ptr);
    }
}

void deleteEnd()
{
    struct node *ptr = head, *preptr = head;
    if (ptr == NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        while (ptr->next != NULL)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
    }
    preptr->next = NULL;
    free(ptr);
}

void display()
{
    struct node *ptr = head;

    while (ptr != NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
}

void main()
{
    // choice
    int ch;
    do
    {
        printf("\nEnter choice:\n1. Insert node at the beginning\n2. Insert node at the end\n3. Insert node in between\n4. Delete node from the beginning\n5. Delete node from the end\n6. Delete specified node\n\n7. Display List\n\n0: Exit\n");
        printf("\n-> ");
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 1:
            insertBeg();
            break;
        case 2:
            insertEnd();
            break;
        case 3:
            insertBet();
            break;
        case 4:
            deleteBeg();
            break;
        case 5:
            deleteEnd();
            break;
        case 6:
            // deleteBet();
            break;
        case 7:
            printf("Current List:\n");
            display();
            printf("\n");
            break;
        default:
            printf("\n");
        }
    } while (ch != 0);
}