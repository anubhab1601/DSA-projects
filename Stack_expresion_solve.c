#include <stdio.h>
#include <stdlib.h>

int stack[100];
int top = -1;

void push(int value) {
    if (top == 99) {
        printf("Stack overflow\n");
    } else {
        top++;
        stack[top] = value;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        int value = stack[top];
        top--;
        return value;
    }
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
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
    char Stack_oprt[100];
    int Stack_oprt_top = -1;
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        char x = infix[i];

        if (x >= '0' && x <= '9') {
            while (infix[i] >= '0' && infix[i] <= '9') {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' ';
            i--;
        } else if (x == '(') {
            Stack_oprt[++Stack_oprt_top] = x;
        } else if (x == ')') {
            while (Stack_oprt_top != -1 && Stack_oprt[Stack_oprt_top] != '(') {
                postfix[j++] = Stack_oprt[Stack_oprt_top--];
                postfix[j++] = ' ';
            }
            Stack_oprt_top--;
        } else if (isOperator(x)) {
            while (Stack_oprt_top != -1 && precedence(Stack_oprt[Stack_oprt_top]) >= precedence(x)) {
                postfix[j++] = Stack_oprt[Stack_oprt_top--];
                postfix[j++] = ' ';
            }
            Stack_oprt[++Stack_oprt_top] = x;
        }
        i++;
    }

    while (Stack_oprt_top != -1) {
        postfix[j++] = Stack_oprt[Stack_oprt_top--];
        postfix[j++] = ' ';
    }
    postfix[j - 1] = '\0';
}

int postfix_evaluate(char postfix[]) {
    int i = 0;

    while (postfix[i] != '\0') {
        char x = postfix[i];

        if (x >= '0' && x <= '9') {
            int num = 0;

            while (postfix[i] >= '0' && postfix[i] <= '9') {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            push(num);
        } else if (isOperator(x)) {
            int operand2 = pop();
            int operand1 = pop();
            int result;

            switch (x) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
                case '^': {
                    result = 1;
                    for (int j = 0; j < operand2; j++) {
                        result *= operand1;
                    }
                    break;
                }
            }
            push(result);
        }
        i++;
    }
    return pop();
}

int main() {
    char infix[100], postfix[100];
    printf("Enter infix expression: ");
    scanf("%[^\n]s", infix);

    infix_to_postfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = postfix_evaluate(postfix);
    printf("Result of evaluation: %d\n", result);

    return 0;
}
