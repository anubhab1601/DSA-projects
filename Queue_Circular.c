/*
****Author : Anubhab Mishra
****Program : Circular Queue Data Structure
Queue:Q, Front:F, Rear:R, Size:MAX 5
Operation:enqueue, dequeue, display
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 2

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int item) {
    if ((front == (rear+1)%MAX)) {
        printf("Queue is full\n");
        return;
    } else if (front == -1) {
        front = rear = 0;
        queue[rear] = item;
    } else {
        rear = ((rear+1)%MAX);
        queue[rear] = item;
    }
    printf("%d enqueued to queue\n", item);
}

int dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
    printf("%d dequeued from queue\n", item);
    return item;
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are:\n");
    if (rear >= front) {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    } else {
        for (int i = front; i < MAX; i++)
            printf("%d ", queue[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int num, choice;

    while (1)
    {
        printf("\nCircular Queue Program : \n");
        printf("0. Exit\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("Enter your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter a num to insert : ");
            scanf("%d", &num);
            enqueue(num);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 0:
            return 0;
        
        default:
            printf("Enter a valid Choice");
            break;
        }
    }
    
    return 0;
}