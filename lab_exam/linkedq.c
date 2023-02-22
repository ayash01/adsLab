#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    void *next;
} node;

node *front = NULL, *current = NULL;

void enqueue() {
    int data;
    printf("\nEnter data to enqueue: ");
    scanf("%d", &data);

    node *new = (node *)malloc(sizeof(node));

    new->data = data;

    if (front == NULL) {
        new->next = NULL;
        front = new;
    }

    else {
        current = front;
        node *pre = NULL;

        while (current != NULL) {
            pre = current;
            current = current->next;
        }

        pre->next = new;
        new->next = NULL;
    }

    printf("\nElement %d enqueued\n", new->data);
}

void dequeue() {

    if (front == NULL) {
        printf("List empty");
    }
    else {
        node *ptr = front;

        front = front->next;

        printf("\nElement %d dequeued\n", ptr->data);

        free(ptr);
    }
}

void display() {
    current = front;

    if (front == NULL) {
        printf("\nList empty\n");
    }
    else {
        printf("\nCurrent queue:\n");
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
    	}
    	printf("\n");
    	printf("Front: %d", front->data);
    	printf("\n");
    }
}

void main() {
    int ch;

    do {
        printf("Please select an option:\n1. Enqueue\n2. Dequeue\n3. Display\n\n0. Exit\n\n-> ");
        scanf("%d", &ch);

        switch(ch) {
            case 0:
                printf("\nExiting program...");
                printf("\n");
                exit(0);
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
