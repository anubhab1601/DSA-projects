#include <stdio.h>

int top = -1;
int Stack[];

int isFull(int num)
{
    if (top == num-1){return 1;}
    else {return 0;}
}

int isEmpty(int num)
{
    if (top == -1){return 1;}
    else {return 0;}
}

void push(int num)
{
    if (isFull(num))
    {
        printf("You can't push values in Stack, otherwise it Overflows\n");
        return;
    }
    else
    {
        int value;
        printf("Enter value to put in Stack : ");
        scanf("%d", &value);
        top++;
        Stack[top] = value;
    }
}

void pop(int num)
{
    if (isEmpty(num))
    {
        printf("You can't pop values in Stack, otherwise it Underflows\n");
        return;
    }
    else
    {
        printf("%d popped from the stack\n", Stack[top]);
        top--;
    }
}

void peek(int num) {
    if (isEmpty(num)) {
        printf("Stack is empty\n");
    } else {
        printf("Top element is: %d\n", Stack[top]);
    }
}

void display(int num) {
    if (isEmpty(num)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements : ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", Stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, num;

    printf("Enter the size of Stack : ");
    scanf("%d", &num);
    Stack[num];

    while (1)
    {
        printf("\n0. exit()\n1. push()\n2. pop()\n3. peek()\n4. display()\n\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Pushing...\n");
                push(num);
                break;
            case 2:
                printf("Popping...\n");
                pop(num);
                break;
            case 3:
                printf("Peeking...\n");
                peek(num);
                break;
            case 4:
                printf("Displaying...\n");
                display(num);
                break;
            case 0:
                printf("Exiting...\n");
                return 0;
        }
    }
    
    return 0;
}
