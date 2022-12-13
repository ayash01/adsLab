#include<stdio.h>
#include<stdlib.h>

#define N 5

int front, q[N], i, rear;

void enqueue() {
	if (front == -1 && rear == N-1) {
		printf("Queue is full.");
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


