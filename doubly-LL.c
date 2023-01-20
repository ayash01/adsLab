#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    void *prev;
    void *next;
} node;

node *head = NULL;

void insertBeg()
{
    int data;
    printf("Enter data to insert into the list: ");
    scanf("%d", &data);

    node *new = (node *)malloc(sizeof(node));
    new->data = data;
    new->prev = NULL;

    if (head == NULL)
    {
        new->next = NULL;
    }
    else
    {
        head->prev = new;
        new->next = head;
    }
    head = new;
}

void deleteBeg()
{
    if (head == NULL)
    {
        printf("Empty List");
    }
    else
    {
        node *ptr = head;

        if (head->next == NULL)
        {
            free(ptr);
            head = NULL;
        }

        else
        {
            ptr->next = head;
            free(ptr);
        }
    }
}

void insertBet()
{
    if (head == NULL)
    {
        printf("Empty List");
    }
    else
    {
        int pos, data;

        printf("Enter element to insert after: ");
        scanf("%d", &pos);

        printf("Enter data to insert into the list: ");
        scanf("%d", &data);

        node *new = (node *)malloc(sizeof(node)), *current = head, *post = NULL;
        new->data = data;

        if (current->next == NULL)
        {
            new->prev = current;
            current->next = new;
            new->next = NULL;
        }

        else
        {
            while (current->data != pos)
            {
                current = current->next;
            }
            post = current->next;
            current->next = new;
            new->next = current->next;
            new->prev = current;
            post->prev = new;
        }
    }
}

void search()
{

    if (head == NULL)
    {
        printf("Empty List");
    }

    else
    {
        int data, found = 0;
        printf("Enter element to search: ");
        scanf("%d", &data);

        node *current = head;

        while (current != NULL)
        {
            if (current->data == data)
            {
                found = 1;
                break;
            }
            current = current->next;
        }
        if (found == 1) {
            printf("Element found\n");
        }
        else {
            printf("Element not found\n");
        }
        
    }
}

void display()
{
    if (head == NULL)
    {
        printf("\nList empty\n");
    }
    else
    {
        node *current = head;

        printf("Current list:\n");

        if (current->next == NULL)
        {
            printf("%d", current->data);
        }

        else
        {
            while (current != NULL)
            {
                current = current->next;
                printf("%d ", current->data);
            }
        }
        printf("\n");

        printf("Head: %d\n", head->data);
    }
}

void main()
{
    int ch;
    do
    {
        printf("Please select an option:\n1. Insert at the beginning\n2. Insert in between\n3. Delete from the beginning\n4. Search element\n\n5. Display\n\n0. Exit\n\n-> ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertBeg();
            printf("\n");
            break;
        case 2:
            insertBet();
            printf("\n");
            break;
        case 3:
            deleteBeg();
            printf("\n");
            break;
        case 4:
            search();
            printf("\n");
            break;
        case 5:
            display();
            printf("\n");
            break;
        default:
            printf("\n");
        }
    } while (ch != 0);
}