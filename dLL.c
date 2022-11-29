#include <stdio.h>
#include <stdlib.h>

void display(), insertBeg(), insertEnd(), insertBet(), deleteBeg(), deleteEnd(), insertBet(), deleteBet();

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head = NULL;

void main()
{
    // choice
    int ch;
    do
    {
        printf("\nEnter choice:\n1. Insert node at the beginning\n2. Insert node at the end\n3. Insert node in between\n4. Display List\n5. Delete node from the beginning\n6. Delete node from the end\n7. Delete specified node\n\n0: Exit\n");
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
            printf("Current List:\n");
            display();
            printf("\n");
            break;
        case 5:
            deleteBeg();
            break;
        case 6:
            deleteEnd();
            break;
        case 7:
            deleteBet();
            break;
        default:
            printf("\n");
        }
    } while (ch != 0);
}

void insertBeg()
{
    int data;
    printf("\nEnter data to insert: ");
    scanf("%d", &data);

    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    if (ptr == NULL)
    {
        printf("\n Overflow!");
    }
    else
    {
        if (head == NULL)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            ptr->data = data;
        }
        else{
            ptr->data = data;
            ptr->prev = NULL;
            ptr->next = head;
            head->prev = ptr;
            head = ptr;
        }
        printf("\n Node Inserted.");
    }
}

void insertEnd()
{
}

void insertBet()
{
}

void display()
{
    struct node *ptr = head;

    while (ptr != NULL)
    {
        printf("%d", ptr->data);
        ptr = ptr->next;
    }
}

void deleteBeg()
{
}

void deleteEnd()
{
}

void deleteBet()
{
}

//change