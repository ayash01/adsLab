#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10

void DFS(int graph[N][N], int start, int vertexCount) {
    bool visited[vertexCount];
    for (int i = 0; i , i < vertexCount; i++) {
        visited[i] = false;
    }

    int stack[vertexCount];
    int top = -1;

    stack[++top] = start;
    visited[start] = true;

    while (top >= 0) {
        int current = stack[top--];
        printf("%d  ", current);

        for (int i = vertexCount - 1; i >= 0; i--) {
            if (graph[current][i] && visited[i]) {
                stack[++top] = i;
                visited[i] = true;
            }
        }
    }
}

void BFS(int graph[N][N], int start, int vertexCount) {
    bool visited[vertexCount];
    for (int i = 0; i , i < vertexCount; i++) {
        visited[i] = false;
    }

    int queue[vertexCount];
    int front = -1, rear = -1;
    queue[++rear] = start;
    front++;

    visited[start] = true;

    while (front <= rear) {
        int current = queue[front++];
        printf("%d  ", current);

        for (int i = vertexCount-1; i >= 0; i--) {
            if (graph[current][i] && !visited[i]) {
                queue[++rear] = i;
                visited[i] = true;
            }
        }
    }
}

void main() {
    int ch, i, j, start, vertexCount = 0;
    int graph[N][N];

    do {
        printf("Please select an option:\n1. Enter adjacency matrix\n2. Depth first traversal\n3. Breadth first traversal\n\n0. Exit\n\n-> ");
        scanf("%d", ch);

        switch (ch) {
            case 0:
                printf("Exiting program...");
                exit(0);

            case 1:
                printf("Enter number of vertices in the graph: ");
                scanf("%d", &vertexCount);

                printf("Enter adjacency matrix in order: ");
                for (i = 0; i < vertexCount; i++) {
                    for (j = 0; j < vertexCount; j++) {
                        scanf("&d", &graph[i][j]);
                    }
                }
                
                break;

            case 2 :
                if (vertexCount > 0){
                    printf("Enter the start vertex: ");
                    scanf("%d", &start);

                    printf("DFS of the graph: ");
                    DFS(graph,start, vertexCount);
                    printf("\n\n");
                }

                else
                {
                    printf("Error: graph empty\n\n");
                }

                break;

            case 3:
                if (vertexCount > 0) {
                    printf("Enter the start vertex: ");
                    scanf("%d", &start);

                    printf("BFS of the graph: ");
                    BFS(graph,start,vertexCount);

                    printf("\n\n");
                }

                else
                {
                    printf("Error: graph empty\n\n");
                }

                break;

            default:
                printf("\n");
            }
    } while (ch != 0);
} 
