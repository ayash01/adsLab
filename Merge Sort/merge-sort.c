#include <stdio.h>

void merge(int array[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = array[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = array[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            array[k] = L[i];
            k++;
            i++; 
        }
        else {
            array[k] = R[j];
            k++;
            j++;
        }
    }

    while (i < n1) {
        array[k] = L[i];
        k++;
        i++;
    }
    while (j < n2) {
        array[k] = R[j];
        k++;
        j++;
    }

}

void mergeSort(int array[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid+1, right);
        merge(array, left, mid, right);
    }
}

void main () {
    int array[10], n;

    printf("Enter array length: ");
    scanf("%d", &n);

    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    printf("\nEntered array (unsorted):\n");
    for (int i = 0; i < n; i++) {
        printf("%d  ", array[i]);
    }
    printf("\n\n");

    printf("Sorted array:\n");
    mergeSort(array, 0, n-1);
    for (int i =0; i < n; i++) {
        printf("%d  ", array[i]);
    }       
}