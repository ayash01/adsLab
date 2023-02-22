#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 5

void dfs(int graph[MAX][MAX], int start, int vertexCount) {
    bool visited[vertexCount];
    for (int i = 0; i < vertexCount; i++) {
        visited[i] = false;
    }

    int stack[vertexCount];
    int top = -1;

    stack[++top] = start;
    visited[start] = true;

    int current = 0;
    
    for (int i = vertexCount - 1; i >= 0; i--) {
        visited[i] = true;
    }
}

/*
void bfs(int graph[MAX][MAX], int start, int vertexCount) {
    bool visited[vertexCount];
    for (int i = 0; i < vertexCount; i++) {
        visited[i] = false;
    }

    int stack[vertexCount];
    int top = -1;

    stack[++top] = start;
    visited[start] = true;

    int current = -1;

}
*/

void main() {
	/*
	int graph[MAX][MAX];

	printf("Enter adjacency matrix: ");
	for (int i =0; i <=MAX; i++) {
		for (int j = 0; j <= MAX; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
	
	printf("DFS: ");
	dfs(graph, 0, 5);
	printf("\n");
	*/

    int graph[MAX][MAX] = {
        {0, 1, 0, 0, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    
    printf("DFS: ");
    dfs(graph, 4, 5);
    printf("\n");
}
