#include <stdio.h>

int Q[];
int F = -1, R = -1;

void enQueue(int num) {
    if (R == num - 1) {
        printf("Queue is FULL\n");
    } else {
        int x;
        printf("Enter the value: ");
        scanf("%d", &x);
        if (F == -1) {
            F = 0;
        }
        Q[++R] = x;
    }
}

void deQueue() {
    if (F == -1) {
        printf("Queue is EMPTY\n");
    } else {
        printf("Dequeued element: %d\n", Q[F]);
        F++;
    }
}

void display() {
    if (F == -1) {
        printf("Queue is EMPTY\n");
    } else {
        printf("Queue contents: ");
        for (int i = F; i <= R; i++) {
            printf("%d ", Q[i]);
        }
        printf("\n");
    }
}

void peek() {
    if (F == -1) {
        printf("Queue is EMPTY\n");
    } else {
        printf("Front element: %d\n", Q[F]);
    }
}

void displayFrontRear() {
    if (F == -1 || F > R) {
        printf("Queue is EMPTY\n");
    } else {
        printf("Front (F): %d, Rear (R): %d\n", F, R);
    }
}

int main() {
    int choice, num;
    printf("Enter the size of Queue: ");
    scanf("%d", &num);

    while (1) {
        printf("\nQueue Operations Menu:\n");
        printf("0. Stop\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Display F and R\n");
        printf("5. Peek\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enQueue(num);
                break;
            case 2:
                deQueue();
                break;
            case 3:
                display();
                break;
            case 4:
                displayFrontRear();
                break;
            case 5:
                peek();
                break;
            case 0:
                printf("Exiting program\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
