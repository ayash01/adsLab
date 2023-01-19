#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    void *next;
} node;

node *front = NULL, *rear = NULL;

void enqueue() {
    int data;
    printf("Enter data to enqueue: ");
    scanf("%d", &data);

    node *new = (node *)malloc(sizeof(node));
    new->data = data;
    new->next = NULL;

    if (rear == NULL) {
        front = new;
    }
    else {
        rear->next = new;  
    }

    rear = new;
}

void dequeue() {
    
    // case if queue is empty
    if (front == NULL && rear == NULL) {
        printf("Queue Empty");
    }

    // case if only one node present
    else if (front == rear) {
        node *ptr = front;

        front = NULL;
        rear = NULL;
        free(ptr);
    }

    // default case
    else {
        node *ptr = front;

        front = front->next;
        free(ptr);
    }
}

void display() {
    if (front == NULL && rear == NULL) {
        printf("Queue Empty");
    }

    else {
        node *current = front;

        printf("Current Queue:\n");

        while (current != NULL) {
            printf("%d  ", current->data);
            current = current->next;
        }

        printf("\nFront: %d\nRear: %d", front->data, rear->data);
    }
    
}

void main()
{
    // choice
    int ch;
    do
    {
        printf("\n");
        printf("Enter choice:\n1. Enqueue\n2. Dequeue\n3. Display\n0: Exit\n");
        printf("\n-> ");
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 1:
            enqueue();
            printf("\n");
            break;
        case 2:
            dequeue();
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