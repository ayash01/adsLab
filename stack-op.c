#include <stdio.h>

#define N 5

int top = -1, c, stack[N], i;

void push(), pop(), topf(), display();

void main()
{
	// choice
	int ch;
	do
	{
		printf("Enter choice:\n1. Push\n2. Pop\n3. Top\n4. Display\n0: Exit\n");
		printf("\n-> ");
		scanf("%d", &ch);
		printf("\n");
		switch (ch)
		{
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

void push() {
	int data;
	printf ("Enter data: ");
	scanf("%d", &data);
	if (top == N - 1) {
		printf ("Stack overflow");
	}
	else {
		top++;
		stack[top] = data;
	}
}

void pop() {
	int item;
	if (top == -1) {
		printf ("Stack underflow");
	}
	else {
		item = stack [top];
		top--;
	}
	printf("Popped item %d.", item);
}

void topf() {
	if (top == -1) {
		printf("Stack is empty.");
	}
	else {
		printf ("Data in stack:\n%d", stack[top]);
	}
}

void display()
{
	i = 0;
	for (i = top; i>=0; i--) {
		printf ("%d\n", stack[i]);
	}
}


