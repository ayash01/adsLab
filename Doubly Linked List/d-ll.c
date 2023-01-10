#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertBeg(void)
{

    int data;
    printf("Enter element to insert: ");
    scanf("%d", &data);
    struct node *ptr;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;

    if (head == NULL)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        ptr = head;
        temp->next = head;
        ptr->prev = temp;
        head = temp;
    }
}

void insertEnd()
{
    int data;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter a number : ");
    scanf("%d", &data);
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;

    if (head == NULL)
        head = temp;
    else
    {
        struct node *ptr = head;

        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        ptr->next = temp;
        temp->prev = ptr;
    }
}

void insertBet()
{
    int data, pos, found = -1;
    printf("Enter element to insert: ");
    scanf("%d", &data);
    printf("Enter element to insert after: ");
    scanf("%d", &pos);

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    struct node *ptr = head, *check = head, *postptr;

    if (ptr == NULL)
        head = temp;
    else
    {
        while (check != NULL)
        {
            if (check->data == pos)
                found = 0;
            check = check->next;
        }
        if (found < 0)
        {

            printf("Invalid element!\n");
            free(temp);
        }
        else
        {
            while (ptr->data != pos)
            {
                ptr = ptr->next;
            }
            postptr = ptr->next;
            temp->next = postptr;
            temp->prev = ptr;
            ptr->next = temp;
            postptr->prev = temp;
        }
    }
}

void display()
{
    struct node *ptr = head;

	if(ptr == NULL)
		printf("List empty\n");
	else {
		while(ptr != NULL){

			printf("%d  ",ptr->data);
			ptr = ptr->next;
		}
		printf("\n");
	}
}

void deleteBeg()
{
    struct node *ptr, *preptr = head;

    if (preptr == NULL)
        printf("List empty\n");
    else if (preptr->next == NULL)
    {
        printf("Element %d deleted.\n", preptr->data);
        free(preptr);
        head = NULL;
    }
    else
    {
        ptr = preptr->next;
        ptr->prev = NULL;
        head = ptr;
        printf("Element %d deleted.\n", preptr->data);
        free(preptr);
    }
}

void deleteEnd()
{
    struct node *preptr, *ptr = head;

    if (ptr == NULL)
        printf("List is empty\n");
    else if (ptr->next == NULL)
    {
        printf("Element %d deleted.\n", ptr->data);
        free(ptr);
        head = NULL;
    }
    else
    {
        while (ptr->next != NULL)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = NULL;
        printf("Element %d deleted.\n", ptr->data);
        free(ptr);
    }
}

void deleteBet()
{
    int pos, found = -1;
    printf("Enter element to delete : ");
    scanf("%d", &pos);

    struct node *ptr = head, *check = head, *preptr, *postptr;
    if (ptr == NULL)
        printf("List is empty\n");
    else
    {
        while (check != NULL)
        {
            if (check->data == pos)
                found = 0;
            check = check->next;
        }

        if (found < 0)
            printf("%d is not present in the list\n");
        else
        {
            if (ptr->next == NULL)
            {
                printf("The deleted number is %d\n", ptr->data);
                free(ptr);
                head = NULL;
            }
            else
            {
                while (ptr->data != pos)
                {
                    preptr = ptr;
                    ptr = ptr->next;
                }
                postptr = ptr->next;
                preptr->next = postptr;
                postptr->prev = preptr;
                printf("Element %d deleted.\n", ptr->data);
                free(ptr);
            }
        }
    }
}

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