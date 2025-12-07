#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5   // Maximum size of stack

// Define Book structure
typedef struct {
    char ISBN[20];
    char Title[50];
    char Author[50];
    float Price;
} BOOK;

// Stack
BOOK stack[MAX];
int top = -1;

// Function prototypes
void push();
void pop();
void display();

int main() {
    int choice;

    printf("Book Stack Implementation (Max Size = %d)\n", MAX);

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. PUSH (Add Book)\n");
        printf("2. POP (Remove Book)\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        // Read choice (Numeric input)
        // No complex input clearing needed here as the next string input handles the buffer.
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select 1-4.\n");
        }
    }
    return 0;
}

// PUSH operation
void push() {
    if (top == MAX - 1) {
        printf("\nStack Overflow! Cannot add more books.\n");
        return;
    }

    BOOK b;

    // *** Simplified String Input using scanf(" %[^\\n]", ...) ***
    // The leading space ' ' consumes the leftover newline from previous inputs.
    // The number limits buffer size (e.g., 19 for a 20-char array).

    printf("Enter ISBN: ");
    scanf(" %19[^\n]", b.ISBN);

    printf("Enter Title: ");
    scanf(" %49[^\n]", b.Title);

    printf("Enter Author: ");
    scanf(" %49[^\n]", b.Author);

    printf("Enter Price: ");
    // Standard numeric input
    scanf("%f", &b.Price);

    stack[++top] = b;  // Push book onto stack
    printf("\nBook pushed successfully.\n");
}

// POP operation
void pop() {
    if (top == -1) {
        printf("\nStack Underflow! No books to remove.\n");
        return;
    }

    BOOK b = stack[top--];  // Pop the top book from the stack

    printf("\nPopped Book Details:\n");
    printf("ISBN: %s | Title: %s | Author: %s | Price: %.2f\n",
           b.ISBN, b.Title, b.Author, b.Price);
}

// Display Stack
void display() {
    if (top == -1) {
        printf("\nStack is empty.\n");
        return;
    }

    printf("\nBooks in Stack (Top to Bottom):\n");
    for (int i = top; i >= 0; i--) {
        printf("[%d] ISBN: %s | Title: %s | Author: %s | Price: %.2f\n",
               i, stack[i].ISBN, stack[i].Title, stack[i].Author, stack[i].Price);
    }
}