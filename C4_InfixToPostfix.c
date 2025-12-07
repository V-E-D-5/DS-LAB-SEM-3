#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAX 100

//Stack Implementation
char STACK[MAX];
int top = -1;

void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack OverFlow :is full\n");
        return;
    }
    STACK[++top] = ch;
}

char pop() {
    if (top == -1) {
        printf("Stack UnderFlow : is empty\n");
        return -1;
    }
    return STACK[top--];
}

char peek() {
    if (top == -1) {
        printf("Stack UnderFlow : is empty\n");
        return -1;
    }
    return STACK[top];
}

//Function to return precedence of operator
int precedence(char op) {
    switch(op) {
        case '^':
            return 3;

        case '*':
        case '/':
            return 2;

        case '+':
        case '-':
            return 1;

        default:
            return 0;
    }
}

//Does not work correct with ^ for more than 2 operands due to Wrong Left Associativity
//Function to convert Infix to Postfix

void infix_to_postfix(char infix[]) {
    char postfix[MAX];
    int i,k=0;
    char ch;

    for (i=0;infix[i]!='\0';i++) {
        ch=infix[i];

        if (isalnum(ch)) {
            postfix[k++]=ch;
        }
        else if (ch=='(') {
            push(ch);
        }
        else if (ch==')') {
            while (peek()!= '(' && top!=-1) {
                postfix[k++]=pop();
            }
            pop();
        }
        else {
            while (precedence(peek()) >= precedence(ch)) {
                postfix[k++]=pop();
            }
            push(ch);
        }
    }
    //Pop remaining operators
    while (top!=-1) {
        postfix[k++]=pop();
    }
    postfix[k]='\0';
    printf("PostFix Expression is:  %s",postfix);
}

int main() {
    char infix[MAX];
    printf("Enter Infix Expression : ");
    scanf("%s",infix);
    infix_to_postfix(infix);
    return 0;
}


/*

// Function to convert Infix to Postfix corrected with right associativity of ^
// A^B^C = A^(B^C)
void infix_to_postfix(char infix[]) {
    char postfix[MAX];
    int i, k = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (peek() != '(' && top != -1) {
                postfix[k++] = pop();
            }
            pop();
        }
        else {
            // FIX: Handle Right Associativity for '^'
            if (ch == '^') {
                // Strict greater (>): Wait if equal precedence is on stack
                while (precedence(peek()) > precedence(ch)) {
                    postfix[k++] = pop();
                }
            }
            else {
                // Standard Left Associativity (>=): Pop if equal precedence is on stack
                while (precedence(peek()) >= precedence(ch)) {
                    postfix[k++] = pop();
                }
            }
            push(ch);
        }
    }
    // Pop remaining operators
    while (top != -1) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
    printf("PostFix Expression is:  %s\n", postfix);
}
*/