#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    void *next;
} node;

node *top = NULL;

void push() {
    int data;
    printf("Enter element to push into the stack: ");
    scanf("%d", &data);

    node *new = (node *)malloc(sizeof(node));
    new->data = data;

    if (top == NULL) {
        new->next = NULL;
    }

    else {
        new->next = top;
    }

    top = new;
}

void pop() {
    if (top == NULL) {
        printf("Stack underflow");
    }
    else {
        node *ptr = top;
        if (top->next == NULL) {
            top = NULL;
        }
        else {
            top = top->next;
        }
        free(ptr);
        printf("Top element popped");
    }
}

void topf() {
    if (top == NULL) {
        printf("Stack Empty");
    }
    else {
        printf("\nTop: %d", top->data);
    }
    
}

void display() {
    if (top == NULL) {
        printf("Stack Empty");
    }

    else {
        node *current = top;

        printf("Current Stack:\n");

        while (current != NULL) {
            printf("%d  ", current->data);
            current = current->next;
        }
    }
}

void main()
{
    // choice
    int ch;
    do
    {
        printf("\n");
        printf("Enter choice:\n1. Push\n2. Pop\n3. Top\n\n4. Display\n\n0: Exit\n");
        printf("\n-> ");
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 0:
            printf("Exiting program...");
            exit(0);
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