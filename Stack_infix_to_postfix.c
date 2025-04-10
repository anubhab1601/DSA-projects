#include <stdio.h>

int stack[100];
int top = -1;

void push(char ch) {
    if (top == 99) {
        printf("Stack overflow\n");
    } else {
        top++;
        stack[top] = ch;
    }
}

char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        char ch = stack[top];
        top--;
        return ch;
    }
}

char peek() {
    if (top == -1) {
        return -1;
    } else {
        return stack[top];
    }
}

int isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
        return 1;
    }
    return 0;
}

int isOperand(char ch) {
    if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
        return 1;
    }
    return 0;
}

int precedence(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    }
    if (ch == '*' || ch == '/') {
        return 2;
    }
    if (ch == '^') {
        return 3;
    }
    return 0;
}

void infix_to_postfix(char infix[], char postfix[]) {
    int i, j;
    i = 0;
    j = 0;
    
    while (infix[i] != '\0') {
        char x = infix[i];
        
        if (isOperand(x)) {
            postfix[j] = x;
            j++;
        } else if (x == '(') {
            push(x);
        } else if (x == ')') {
            while (peek() != '(') {
                postfix[j] = pop();
                j++;
            }
            pop();
        } else if (isOperator(x)) {
            while (top != -1 && precedence(peek()) >= precedence(x)) {
                postfix[j] = pop();
                j++;
            }
            push(x);
        }
        
        i++;
    }
    
    while (top != -1) {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';
}

int main() {
    char infix[100];
    char postfix[100];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infix_to_postfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
