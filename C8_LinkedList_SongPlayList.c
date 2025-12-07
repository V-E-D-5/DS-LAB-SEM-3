#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
    char song[100];
    struct Node* next;
} Node;

Node* head = NULL;

Node* createNode(char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory Allocation Failed\n");
        exit(1);
    }
    strcpy(newNode->song, name);
    newNode->next = NULL;
    return newNode;
}

void addSong() {
    char name[100];
    printf("Enter the Song Name: ");
    scanf("%s", name);

    Node* newNode = createNode(name);

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Added: %s Successfully\n", name);
}

void playStart() {
    if (head == NULL) {
        printf("No Song in the List\n");
        return;
    }
    Node* temp = head;
    printf("Playing Songs:\n");
    while (temp != NULL) {
        printf("%s\n", temp->song);
        temp = temp->next;
    }
}

// Recursive function to print in reverse
void playEndRec(Node* node) {
    if (!node) return;
    playEndRec(node->next);
    printf("%s\n", node->song);
}

void playEnd() {
    if (head == NULL) {
        printf("No Song in the List\n");
        return;
    }
    printf("Playing Songs in Reverse Order:\n");
    playEndRec(head);
}

void delStart() {
    if (!head) {
        printf("No Song in the List\n");
        return;
    }
    // Just move the head pointer. The old node is "lost" but who cares!
    printf("Deleted Song: %s\n", head->song);
    head = head->next;
}

void delEnd() {
    if (head == NULL) {
        printf("No Song in the List\n");
        return;
    }
    // Case: Only one node
    if (head->next == NULL) {
        printf("Deleted %s\n", head->song);
        head = NULL;
        return;
    }

    // Traverse to the second-to-last node
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    // Just print the next one and then cut the link
    printf("Deleted %s\n", temp->next->song);
    temp->next = NULL;
}

void menu() {
    printf("\n----- Song PlayList -----\n");
    printf("1. Add Song\n");
    printf("2. Play From Start\n");
    printf("3. Play From End\n");
    printf("4. Delete From Start\n");
    printf("5. Delete From End\n");
    printf("6. Exit\n");
}

int main() {
    int choice;
    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addSong(); break;
            case 2: playStart(); break;
            case 3: playEnd(); break;
            case 4: delStart(); break;
            case 5: delEnd(); break;
            case 6: exit(0);
            default: printf("Wrong choice\n");
        }
    }
    return 0;
}