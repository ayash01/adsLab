#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL, *current = NULL;

void insertBeg()
{
    int data;
    printf("Enter a number to insert : ");
    scanf("%d", &data);

    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        current = temp;
        temp->next = head;
    }
    else
    {
        temp->next = head;
        head = temp;
        current->next = temp;
    }
}

void insertEnd()
{

    int data;
    printf("Enter a number to insert : ");
    scanf("%d", &data);

    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        current = temp;
        temp->next = head;
    }
    else
    {
        current->next = temp;
        current = temp;
        current->next = head;
    }
}

void insertBet()
{
    int data, pos, found = -1;
    printf("Enter element to insert : ");
    scanf("%d", &data);
    printf("Enter element to insert after: ");
    scanf("%d", &pos);
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    struct node *ptr = head, *check = head;
    if (ptr == NULL)
    {
        head = temp;
        current = temp;
        temp->next = head;
    }
    else
    {
        while (check->next != head)
        {
            if (check->data == pos)
                found = 0;
            check = check->next;
        }
        if (check->data == pos)
            found = 0;

        if (found < 0)
        {
            printf("Invalid element\n\n");
            free(temp);
        }
        else
        {
            while (ptr->data != pos)
            {
                ptr = ptr->next;
            }
            if (ptr->next == head)
            {
                ptr->next = temp;
                current = temp;
                current->next = head;
            }
            else
            {
                temp->next = ptr->next;
                ptr->next = temp;
            }
        }
    }
}

void deleteBeg()
{

    struct node *preptr = head, *ptr = head;

    if (preptr == NULL)
        printf("List empty\n\n");
    else if (preptr->next == head)
    {
        head = NULL;
        current = NULL;
        printf("Element %d deleted\n", preptr->data);
        free(preptr);
    }
    else
    {
        ptr = preptr->next;
        head = ptr;
        current->next = head;
        printf("Element %d deleted\n", preptr->data);
        free(preptr);
    }
}

void deleteEnd()
{
    struct node *ptr = head, *preptr = head;

    if (preptr == NULL)
        printf("The list is empty\n");
    else if (preptr->next == head)
    {
        head = NULL;
        current = NULL;
        printf("Element %d deleted\n", preptr->data);
        free(preptr);
    }
    else
    {
        while (ptr->next != head)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        current = preptr;
        current->next = head;
        printf("Element %d deleted\n", ptr->data);
        free(ptr);
    }
}

void deleteBet()
{

    int pos, found = -1;
    printf("Which number you want to delete : ");
    scanf("%d", &pos);

    struct node *preptr, *ptr = head, *check = head;

    if (ptr == NULL)
        printf("The list is empty\n\n");
    else if (ptr->data == pos)
    {
        if (ptr->next == head)
        {
            head = NULL;
            current = NULL;
            printf("Element %d deleted\n", ptr->data);
            free(ptr);
        }
        else
        {
            head = ptr->next;
            current->next = head;
            printf("The deleted number is %d\n\n", ptr->data);
            free(ptr);
        }
    }
    else
    {
        while (check->next != head)
        {
            if (check->data == pos)
            {
                found = 0;
            }
            check = check->next;
        }
        if (check->data == pos)
            found = 0;

        if (found < 0)
            printf("%d not in list\n\n");
        else
        {
            while (ptr->data != pos)
            {
                preptr = ptr;
                ptr = ptr->next;
            }
            if (ptr->next == head)
            {
                current = preptr;
                preptr->next = head;
                printf("Element %d deleted\n", ptr->data);
                free(ptr);
            }
            else
            {
                preptr->next = ptr->next;
                printf("Element %d deleted\n", ptr->data);
                free(ptr);
            }
        }
    }
}

void display()
{
    struct node *ptr = head;

    if (ptr == NULL)
        printf("The list is empty\n\n");
    else
    {
        while (ptr->next != head)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
        printf("%d\n\n", ptr->data);
    }
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
        printf("\nEnter choice:\n1. Insert node at the beginning\n2. Insert node at the end\n3. Insert node in between\n4. Display List\n5. Delete node from the beginning\n6. Delete node from the end\n7. Delete specific node\n\n0: Exit\n");
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