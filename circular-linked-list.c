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
    printf("Enter a number to insert : ");
    scanf("%d", &data);

    struct node *temp = (struct node *)malloc(sizeof(struct node)), *ptr = NULL;

    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        ptr = temp;
        temp->next = head;
    }
    else
    {
        temp->next = head;
        head = temp;
        ptr->next = temp;
    }
}

void insertEnd()
{
    int data;
	printf("Enter a number to insert : ");
	scanf("%d",&data);

	struct node *temp = (struct node*)malloc(sizeof(struct node)), *ptr = NULL;

	temp->data = data;
	temp->next = NULL;

	if(head == NULL){
		head = temp;
		ptr = temp;
		temp->next = head;
	}
	else {
		ptr->next = temp;
		ptr = temp;
		ptr->next = head;
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
}

void deleteEnd()
{
}

void DeleteBet()
{
    int pos;
    printf("Which element to delete?: ");
    scanf("%d", &pos);

    struct node *ptr = head, *temp;

    if (ptr == NULL)
    {
        printf("Underflow!");
    }
    else
    {
        while (ptr->data != pos)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        free(ptr);
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