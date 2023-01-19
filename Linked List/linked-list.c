#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    void *next;
    int data;
} node;

node *head = NULL;

void insertBeg()
{
    int data;
    printf("Enter data to be inserted into the list: ");
    scanf("%d", &data);

    node *new = (node *)malloc(sizeof(node));
    new->data = data;

    if (head == NULL)
    {
        new->next = NULL;
    }
    else
    {
        new->next = head;
    }

    head = new;
}

void insertBw()
{
    int data, pos;

    printf("Enter data to insert: ");
    scanf("%d", &data);

    printf("Enter element to insert after: ");
    scanf("%d", &pos);

    node *new = (node *)malloc(sizeof(node)), *current = head;
    new->data = data;

    while (current->data != pos)
    {
        current = current->next;
    }

    if (current->next == NULL)
    {
        new->next = NULL;
    }
    else
    {
        new->next = current->next;
    }

    current->next = new;
}

void insertEnd()
{
    int data;
    printf("Enter data to insert: ");
    scanf("%d", &data);

    node *new = (node *)malloc(sizeof(node)), *current = head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    new->data = data;
    new->next = NULL;
    current->next = new;
}

void deleteBeg()
{
    node *ptr = head;

    if (head = NULL)
    {
        printf("Empty List");
    }
    else
    {
        head = ptr->next;
        free(ptr);
    }
}

void deleteBet()
{
    int pos;
    printf("Enter node to delete: ");
    scanf("%d", &pos);

    node *current = head, *prev = NULL;

    // case if only one node present in the list
    if (current->next == NULL)
    {
        head = NULL;
        free(current);
    }

    // case if position is found at the first node
    else if (current->data == pos)
    {
        head = current->next;
        free(current);
    }

    else
    {
        while (current->next != NULL)
        {
            prev = current;
            current = current->next;
        }

        // case if list is empty
        if (current->next == NULL && current->data != pos)
        {
            printf("\nNode not found");
        }

        // default case - multiple nodes
        else
        {
            prev->next = current->next;
            free(current);
        }
    }
}

void deleteEnd()
{
    node *current = head, *prev = NULL;
    if (current->next == NULL)
    {
        head = NULL;
        free(current);
    }
    else if (head == NULL)
    {
        printf("Empty List");
    }
    else
    {
        while (current->next != NULL)
        {
            prev = current;
            current = current->next;
        }
        prev->next = NULL;
        free(current);
    }
}

void display()
{
    node *ptr = head;
    printf("Current List:\n");
    while (ptr != NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
    if (head != NULL)
    {
        printf("\nHead: %d", head->data);
    }
    else
    {
        printf("Empty");
    }
}

void main()
{
    int ch;
    do
    {
        printf("\nEnter choice:\n1. Insert node at the beginning\n2. Insert node at specified position\n3. Insert node at the end\n4. Delete node from the beginning\n5. Delete node in between\n6. Delete node from the end\n\n7. Display List\n\n0: Exit\n");
        printf("\n-> ");
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 0:
            printf("Exiting program...");
            exit(0);
        case 1:
            insertBeg();
            break;
        case 2:
            insertBw();
            break;
        case 3:
            insertEnd();
            break;
        case 4:
            deleteBeg();
            break;
        case 5:
            deleteBet();
            printf("\n");
            break;
        case 6:
            deleteEnd();
            printf("\n");
            break;
        case 7:
            display();
            printf("\n");
            break;
        default:
            printf("\n");
        }
    } while (ch != 0);
}