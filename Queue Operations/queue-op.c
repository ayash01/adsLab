#include <stdio.h>
#include <stdlib.h>

#define N 5

int queue[N], front = -1, rear = -1;

void enqueue()
{

    // case if queue is full
    if (rear == N - 1)
    {
        printf("Queue Full");
    }

    else
    {
        int data;
        printf("Enter data to enqueue: ");
        scanf("%d", &data);

        // case if queue is empty
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
            queue[front] = data;
        }

        // default case
        else
        {
            rear++;
            queue[rear] = data;
        }
        printf("\nElement %d enqueued.", data);
    }
}

void dequeue()
{
    // case if queue empty
    if (rear == -1) {
        printf("Queue is empty");
    }

    else {
        int e = queue[front];

        // case when queue only has one element
        if (front == rear) {
            front = rear = -1;
        }

        // default case
        else {
            front++; 
        }

        printf("Element %d dequeued", e);
    }
}

void display()
{
    // case if queue empty
    if (rear == -1) {
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