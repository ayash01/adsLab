#include <stdio.h>
#include <stdlib.h>

#define N 10

int cq[N], front = -1, rear = -1;

void enq()
{
	int data;
	printf("Enter element to insert: ");
	scanf("%d", &data);

	if ((rear + 1) % N == front)
		printf("Overflow\n");
	else if (front == -1 && rear == -1)
	{
		front = 0;
		rear = 0;
		cq[rear] = data;
	}
	else
	{
		rear = (rear + 1) % N;
		cq[rear] = data;
	}
}

void deq()
{
	int data;
	if (front == -1 && rear == -1)
		printf("Queue Empty\n");
	else if (front == rear)
	{

		data = cq[front];
		front = -1;
		rear = -1;
		printf("Element %d dequeued\n", data);
	}
	else
	{
		data = cq[front];
		front = (front + 1) % N;
		printf("ELement %d dequeued\n", data);
	}
}

void display(void){

	if(front == -1 && rear == -1)
		printf("Queue Empty\n");
	else{
		for(int i = front; i <= rear; i++)
			printf("%d  ",cq[i]);
		printf("\n");
	}
}

void main()
{
	// choice
	int ch;
	do
	{
		printf("Enter choice:\n1. Enqueue\n2. Dequeue\n3. Display\n0: Exit\n");
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
			display();
			printf("\n");
			break;
		default:
			printf("\n");
		}
	} while (ch != 0);
}
