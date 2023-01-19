#include <stdio.h>
#include <stdlib.h>

#define N 5

int queue[N], front = -1, rear = -1;

void enqueue() {
    int data;
    printf("Enter data to enqueue: ");
    scanf("%d", &data);

    if ((rear+1) % N == front) {
        printf("Queue Full");
    }

    else {
        if (front == -1 && rear == -1) {
            front = 0;
            rear = 0;
        }

        else {
            rear = (rear+1) % N;
        }

        queue[rear] = data;
    }
}

void dequeue() {
    int data = queue[front];

    if (front == -1 && rear == -1) {
        printf("Queue Empty");
    }

    else { 
        if (front == rear) {
            front = -1;
            rear = -1;  
        }
        else {
            front = (front+1) % N;
        }
        printf("Element %d dequeued", data);
    }
}

void display()
{
    // case if queue empty
    if (front == -1 && rear == -1) {
        printf("Queue is empty");
    }

    // default case
    else {
        printf("Current Queue:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d  ", queue[i]);
        }
        printf("\nFront: %d\nRear: %d", queue[front], queue[rear]);
    }
}

void main()
{
    // choice
    int ch;
    do
    {
        printf("\n");
        printf("Enter choice:\n1. Enqueue\n2. Dequeue\n\n3. Display\n\n0: Exit\n");
        printf("\n-> ");
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 0:
            printf("Exiting program...");
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