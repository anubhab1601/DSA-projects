#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX]; // Adjacency matrix
int visited[MAX];  // Array to keep track of visited nodes
int stack[MAX];    // Stack for DFS
int top = -1;

// Function to add an element to the queue
void push(int vertex) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = vertex;
    }
}

// Function to remove an element from the queue
int pop() {
    if (top == -1) {
        return -1; // Stack is empty
    } else {
        int vertex = stack[top];
        top--;
        return vertex;
    }
}

// Function to perform BFS
void DFS(int start, int n) {
    push(start);
    visited[start] = 1;

    while (top != -1) { // Ensure Stack is not empty
        int current = pop();
        if (current == -1) break; // Exit if Stack is empty
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                push(i);
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

    printf("DFS Traversal: ");
    DFS(start, n);

    // Handle disconnected graphs
    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(i, n);
        }
    }

    return 0;
}