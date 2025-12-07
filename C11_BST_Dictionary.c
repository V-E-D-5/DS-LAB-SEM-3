#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

struct Node {
    char word[MAX];
    char meaning[MAX];
    struct Node *left, *right;
};

struct Node* createNode(char word[], char meaning[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->word, word);
    strcpy(newNode->meaning, meaning);
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, char word[], char meaning[]) {
    if (root == NULL)
        return createNode(word, meaning);

    int cmp = strcmp(word, root->word);

    if (cmp < 0)
        root->left = insert(root->left, word, meaning);
    else if (cmp > 0)
        root->right = insert(root->right, word, meaning);
    else
        strcpy(root->meaning, meaning); // update meaning if word already exists

    return root;
}

struct Node* search(struct Node* root, char word[]) {
    if (root == NULL)
        return NULL;

    int cmp = strcmp(word, root->word);

    if (cmp == 0)
        return root;
    else if (cmp < 0)
        return search(root->left, word);
    else
        return search(root->right, word);
}

// Inorder traversal (Left, Root, Right)
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%s : %s\n", root->word, root->meaning);
    inorder(root->right);
}

// Preorder traversal (Root, Left, Right)
void preorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%s : %s\n", root->word, root->meaning);
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal (Left, Right, Root)
void postorder(struct Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%s : %s\n", root->word, root->meaning);
}

int main() {
    struct Node* root = NULL;
    struct Node* found;
    int choice;
    char word[MAX], meaning[MAX];

    while (1) {
        printf("\n--- Simple Dictionary (BST) ---\n");
        printf("1. Insert Word\n");
        printf("2. Search Word\n");
        printf("3. Display (Inorder)\n");
        printf("4. Display (Preorder)\n");
        printf("5. Display (Postorder)\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 0) break;

        switch (choice) {
            case 1:
                printf("Enter word: ");
                scanf("%s", word);
                printf("Enter meaning: ");
                scanf(" %[^\n]", meaning);  // read full meaning line
                root = insert(root, word, meaning);
                printf("Word inserted!\n");
                break;

            case 2:
                printf("Enter word to search: ");
                scanf("%s", word);
                found = search(root, word);
                if (found)
                    printf("Found! %s : %s\n", found->word, found->meaning);
                else
                    printf("Word not found.\n");
                break;

            case 3:
                printf("\nDictionary Words (Inorder - A to Z):\n");
                inorder(root);
                break;

            case 4:
                printf("\nDictionary Words (Preorder - Root-Left-Right):\n");
                preorder(root);
                break;

            case 5:
                printf("\nDictionary Words (Postorder - Left-Right-Root):\n");
                postorder(root);
                break;

            default:
                printf("Invalid choice!\n");
        }
    }

    printf("Exiting...\n");
    return 0;
}
