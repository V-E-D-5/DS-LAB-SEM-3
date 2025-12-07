#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char url[100];
    struct Node *prev, *next;
} Node;

Node *cur = NULL;

Node* createNode(char *url) {
    Node *n = (Node*)malloc(sizeof(Node));
    strcpy(n->url, url);
    n->prev = NULL;
    n->next = NULL;
    return n;
}

void visit(char *url) {
    Node *n = createNode(url);

    if (cur != NULL) {
        cur->next = n;
        n->prev = cur;
    }

    cur = n;
    printf("Visited: %s\n", url);
}

void back(int steps) {
    while (steps-- > 0 && cur && cur->prev) {
        cur = cur->prev;
    }
    if (cur) printf("Current page: %s\n", cur->url);
}

void forward(int steps) {
    while (steps-- > 0 && cur && cur->next) {
        cur = cur->next;
    }
    if (cur) printf("Current page: %s\n", cur->url);
}

void show() {
    if (cur == NULL) {
        printf("No browsing history.\n");
        return;
    }

    Node *temp = cur;
    while (temp->prev != NULL) {
        temp = temp->prev;
    }

    printf("\n--- Browser History ---\n");
    while (temp != NULL) {
        printf("%s", temp->url);
        if (temp == cur) {
            printf("  <-- Current");
        }
        printf("\n");
        temp = temp->next;
    }
    printf("-----------------------\n");
}

int main() {
    int ch, steps;
    char url[100];

    while (1) {
        printf("\n1.Visit  2.Back  3.Forward  4.Show  5.Exit\nChoice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter URL: ");
                scanf("%s", url);
                visit(url);
                break;
            case 2:
                printf("Enter steps back: ");
                scanf("%d", &steps);
                back(steps);
                break;
            case 3:
                printf("Enter steps forward: ");
                scanf("%d", &steps);
                forward(steps);
                break;
            case 4:
                show();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}