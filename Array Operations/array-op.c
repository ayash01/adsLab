#include <stdio.h>

int a[5], n, i, asum;

void display()
{
	printf("The entered array is: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void maximum()
{
	int max = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	printf("The maximum value is %d.\n", max);
}

void minimum()
{
	int min = a[0];
	for (i = 0; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
	}
	printf("The minimum value is %d.\n", min);
}

void sum()
{
	asum = 0;
	for (i = 0; i < n; i++)
	{
		asum = asum + a[i];
	}
	printf("The sum of elements is %d.\n", asum);
}

void mean()
{
	printf("The mean value is %d.\n", asum / n);
}

void count()
{
	printf("Element count: %d\n", n);
}

void main()
{
	// input array
	printf("Enter array size: ");
	scanf("%d", &n);
	printf("Enter array elements: ");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("\n");

	// choice
	int ch;
	i = 0;
	do
	{
		printf("Enter choice:\n1. Display\n2. Maximum\n3. Minimum\n4. Sum\n5. Mean:\n6: Count\n0: Exit\n");
		printf("\n-> ");
		scanf("%d", &ch);
		printf("\n");
		switch (ch)
		{
		case 1:
			display();
			printf("\n");
			break;
		case 2:
			maximum();
			printf("\n");
			break;
		case 3:
			minimum();
			printf("\n");
			break;
		case 4:
			sum();
			printf("\n");
			break;
		case 5:
			mean();
			printf("\n");
			break;
		case 6:
			count();
			printf("\n");
			break;
		default:
			printf("\n");
		}
	} while (ch != 0);
}
