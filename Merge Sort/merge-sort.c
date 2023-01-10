#include <stdio.h>

void merge(int a[], int l, int mid, int r)
{

	int n1 = mid - l + 1;
	int n2 = r - mid;
	int left[n1], right[n2];

	for (int i = 0; i < n1; i++)
	{
		left[i] = a[l + i];
	}
	for (int j = 0; j < n2; j++)
	{
		right[j] = a[mid + 1 + j];
	}

	int i = 0, j = 0, k = l;

	while (i < n1 && j < n2)
	{
		if (left[i] < right[j])
		{
			a[k] = left[i];
			k++;
			i++;
		}
		else
		{
			a[k] = right[j];
			k++;
			j++;
		}
	}

	while (i < n1)
	{
		a[k] = left[i];
		k++;
		i++;
	}
	while (j < n2)
	{
		a[k] = right[j];
		k++;
		j++;
	}
}

void mergeSort(int a[], int l, int r)
{
	if (l < r)
	{
		int mid = (l + r) / 2;
		mergeSort(a, l, mid);
		mergeSort(a, mid + 1, r);
		merge(a, l, mid, r);
	}
}

void main()
{
	int a[10], n;
	printf("How many elements? ");
	scanf("%d", &n);

	printf("Enter %d elements: ", n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	printf("Sorted Array: ");
	mergeSort(a, 0, n - 1);
	for (int i = 0; i < n; i++)
		printf("%d  ", a[i]);
	printf("\n");
}