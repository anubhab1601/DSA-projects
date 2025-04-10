#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX]; // Adjacency matrix
int visited[MAX];  // Array to keep track of visited nodes
int queue[MAX];    // Queue for BFS
int front = -1, rear = -1;

// Function to add an element to the queue
void enqueue(int vertex) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = vertex;
    }
}

// Function to remove an element from the queue
int dequeue() {
    if (front == -1 || front > rear) {
        return -1; // Queue is empty
    } else {
        int vertex = queue[front];
        if (front == MAX-1 || front == rear){
            front == -1;
        }
        front++;
        return vertex;
    }
}

// Function to perform BFS
void BFS(int start, int n) {
    enqueue(start);
    visited[start] = 1;

    while (front != -1 && front <= rear) { // Ensure queue is not empty
        int current = dequeue();
        if (current == -1) break; // Exit if queue is empty
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n, i, j, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    // Initialize visited array
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("BFS Traversal: ");
    BFS(start, n);

    // Handle disconnected graphs
    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            BFS(i, n);
        }
    }

    return 0;
}