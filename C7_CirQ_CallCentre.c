#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct Call {
    int callID;
    char callerName[50];
} Call;

Call queueArr[MAX];
int front = -1;
int rear = -1;

// Check if Queue is Empty
int isEmpty() {
    return (front == -1 && rear == -1);
}

// Check if Queue is Full
int isFull() {
    return ((rear + 1) % MAX == front);
}

// Add Call (Enqueue)
void addCall(Call c) {
    if (isFull()) {
        printf("\nQueue Overflow! Cannot add call.\n");
        return;
    }
    if (isEmpty()) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    queueArr[rear] = c;
    printf("Added Call: ID %d\n", c.callID);
}

// Delete Call (Dequeue)
void deleteCall() {
    if (isEmpty()) {
        printf("\nQueue Underflow! No calls to delete.\n");
        return;
    }

    Call c = queueArr[front];
    printf("Deleted Call: ID %d | Name %s\n", c.callID, c.callerName);

    if (front == rear) {
        front = rear = -1; // Queue became empty
    } else {
        front = (front + 1) % MAX;
    }
}

// Display Queue (Simplified Logic)
void displayQueue() {
    if (isEmpty()) {
        printf("\nQueue is Empty.\n");
        return;
    }

    printf("\n--- Waiting Calls ---\n");
    int i = front;
    while (1) {
        printf("ID: %d | Name: %s\n", queueArr[i].callID, queueArr[i].callerName);

        if (i == rear) break; // Stop after printing the rear element
        i = (i + 1) % MAX;    // Move to next index circularly
    }
    printf("---------------------\n");
}

Call inputCall() {
    Call c;
    printf("Enter Call ID: ");
    scanf("%d", &c.callID);

    printf("Enter Caller Name: ");
    // The space before % consumes the newline left by the previous input
    scanf(" %[^\n]", c.callerName);

    return c;
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Add Call\n2. Delete Call\n3. Display\n4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addCall(inputCall()); break;
            case 2: deleteCall(); break;
            case 3: displayQueue(); break;
            case 4: exit(0);
            default: printf("Invalid Choice\n");
        }
    }
    return 0;
}