# include <stdio.h>

#define N 5

int front, q[N], i, rear;

void enq() {
    int data;
    printf ("Enter data to insert: ");
    scanf ("%d", &data);
    if (rear == N - 1) {
        printf("Queue is full.");
    }
    else if (front == -1 && rear == -1) {
        front = rear = 0;
        q[rear] = data;
    }
    else {
        rear++;
        q[rear] = data;
    }
}

void deq() {
    if (front == -1 && rear == -1) {
        printf("Underflow");   
    }
    else if (front == rear) {
        front = rear = -1;
    }
    else {
        printf ("Element dequeued: %d", q[front]);
        front++;
    }
}

void topf() {
    if (front == -1 && rear == -1) {
        printf ("Queue is empty");
    }
    else {
        printf ("Top = %d", q[front]);
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf ("Queue is empty");
    }
    else {
        for (i = front; i <= rear; i++) {
            printf ("%d ", q[i]);
        }
    }
}

void main()
{
	// choice
	int ch;
	do
	{
		printf("Enter choice:\n1. Enqueue\n2. Dequeue\n3. Top\n4. Display\n0: Exit\n");
		printf("\n-> ");
		scanf("%d", &ch);
		printf("\n");
		switch (ch)
		{
		case 1:
			enq();
			printf("\n");
			break;
		case 2:
			deq();
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
