/*
****Author : Anubhab Mishra
****Program : Deque Data Structure
Queue:Q, Front:F, Rear:R, Size:MAX 5
Operation:insertFront, insertRear, deleteFront, deleteRear, display
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

void insertFront(int item) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque is full\n");
        return;
    } else if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }
    deque[front] = item;
    printf("%d inserted at front\n", item);
}

void insertRear(int item) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque is full\n");
        return;
    } else if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = item;
    printf("%d inserted at rear\n", item);
}

int deleteFront() {
    if (front == -1) {
        printf("Deque is empty\n");
        return -1;
    }
    int item = deque[front];
    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
    printf("%d deleted from front\n", item);
    return item;
}

int deleteRear() {
    if (front == -1) {
        printf("Deque is empty\n");
        return -1;
    }
    int item = deque[rear];
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
    printf("%d deleted from rear\n", item);
    return item;
}

void display() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements are:\n");
    int i = front;
    if (front <= rear) {
        while (i <= rear)
            printf("%d ", deque[i++]);
    } else {
        while (i < MAX)
            printf("%d ", deque[i++]);
        i = 0;
        while (i <= rear)
            printf("%d ", deque[i++]);
    }
    printf("\n");
}

int main() {
    int num, choice;

    while (1)
    {
        printf("\nCircular Queue Program : \n");
        printf("0. Exit\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("Enter your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter a num to insert front : ");
            scanf("%d", &num);
            insertFront(num);
            break;

        case 2:
            printf("Enter a num to insert rear : ");
            scanf("%d", &num);
            insertRear(num);
            break;

        case 3:
            deleteFront();
            break;

        case 4:
            deleteRear();
            break;

        case 5:
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
