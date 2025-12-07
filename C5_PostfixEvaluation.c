#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>  // For pow()

#define MAX 100

int stack[MAX];
int top = -1;

// Push value onto stack
void push(int val) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = val;
}

// Pop value from stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

// *** MISSING FUNCTION ADDED HERE ***
int eval(char* exp) {
    int i, val1, val2, res;

    for (i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        // If character is a number, convert to int and push
        // (ch - '0') converts char '5' to integer 5
        if (isdigit(ch)) {
            push(ch - '0');
        }
        // If character is an operator, pop two elements and calculate
        else {
            val2 = pop(); // Top element is the second operand
            val1 = pop(); // Element below is the first operand

            switch(ch) {
                case '+': res = val1 + val2; break;
                case '-': res = val1 - val2; break;
                case '*': res = val1 * val2; break;
                case '/': res = val1 / val2; break;
                case '^': res = (int)pow(val1, val2); break; // Cast double to int
                default:
                    printf("Invalid Operator\n");
                    exit(1);
            }
            push(res);
        }
    }
    return pop(); // The final result is the only item left
}

int main() {
    char postfix[MAX];
    int result;

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    result = eval(postfix);

    printf("Result is: %d\n", result);
    return 0;
}