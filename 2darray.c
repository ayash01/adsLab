#include <stdio.h>

int i, j, num, marks[20][5];

void display(); //avgsub() avgstud(), bl50()

void main() {

	//input array
	printf("Enter number of students");
	scanf("%d", &num);
	for (i=0; i < num; i++) {
	printf("Enter marks of student %d \n", i+1);
		for (j=0; j < 5; j++) {
			scanf ("%d", &marks[i][j]);
		}
	}

	// choice
	int ch;
	do {
		printf("Enter choice:\n1. Display average marks (each subject)\n2. Display average marks (every student)\n3. Display students (marks below 50)\n4. Display marks (every student)\n0: Exit\n");
		printf("\n->");
		scanf("%d", &ch);
		printf("\n");
		switch (ch)
		{
		case 1:
			//avgsub();
			printf("\n");
			break;
		case 2:
			//avgstud();
			printf("\n");
			break;
		case 3:
			//bl50();
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


void display() {
	printf("num = %d\n", num);
	for (i=0; i < num; i++) {
		printf("%d", marks[i][j]);
	printf("\n");
	}
}
