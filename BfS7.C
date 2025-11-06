#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

int graph[SIZE + 1][SIZE + 1]; // Adjacency matrix
int visited[SIZE + 1];

// Queue for BFS
int queue[SIZE + 1];
int front = -1, rear = -1;

void enqueue(int v) {
    if (rear == SIZE - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

// BFS traversal
void BFS(int start) {
    int i, v;
    for (i = 1; i <= SIZE; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");
    while (front <= rear) {
        v = dequeue();
        printf("%d ", v);
        for (i = 1; i <= SIZE; i++) {
            if (graph[v][i] && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// DFS traversal
void DFS(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);
    for (i = 1; i <= SIZE; i++) {
        if (graph[v][i] && !visited[i])
            DFS(i);
    }
}

void buildGraph() {
    int i;
    // Connect nodes in a 3x3 grid (undirected)
    for (i = 1; i <= SIZE; i++) {
        if (i % 3 != 0) { // right neighbor
            graph[i][i + 1] = 1;
            graph[i + 1][i] = 1;
        }
        if (i + 3 <= SIZE) { // bottom neighbor
            graph[i][i + 3] = 1;
            graph[i + 3][i] = 1;
        }
    }
}

int main() {
    int i, j;
    buildGraph();

    printf("Adjacency Matrix of 3x3 Grid Graph:\n");
    for (i = 1; i <= SIZE; i++) {
        for (j = 1; j <= SIZE; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }

    // Perform BFS
    BFS(1);

    // Perform DFS
    for (i = 1; i <= SIZE; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    DFS(1);
    printf("\n");

    return 0;
}
