#include <stdio.h>

#define N 5

// Declare a two-dimensional array to represent the adjacency matrix
int graph[N][N];

void main() {
    // Initialize all elements of the matrix to 0
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // This sets each element of the array to 0
            graph[i][j] = 0;
        }
    }

    // Insert edges into the graph
    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][3] = 1;
    graph[2][4] = 1;

    // Print the adjacency matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // This prints the value of each element in the array
            printf("%d ", graph[i][j]);
        }
        // This prints a newline character at the end of each row
        printf("\n");
    }
}

