#include <stdio.h>
#include <stdlib.h>

void menu();
int* createArray(int);
void displayArray(int*, int);
int* insertElem(int*, int*, int,int);
int* deleteElem(int*, int*, int);
void searchElem(int*, int, int);

int main() {
    int *arr=NULL;
    int n=0,choice,elem,pos;

    printf("Dynamic Array Operations Using Pointers\n\n ");

    while(1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printf("\nEnter the number of elements: ");
                scanf("%d",&n);
                arr=createArray(n);
                break;

            case 2:
                if (arr==NULL) printf("\nArray is Not yet Created\n");
                displayArray(arr,n);
                break;

            case 3:

                printf("\nEnter the element to insert: ");
                scanf("%d",&elem);

                printf("\nEnter the position to insert: ");
                scanf("%d",&pos);

                arr=insertElem(arr,&n,elem,pos);
                break;

            case 4:
                printf("\nEnter the position to delete (0 to %d): ",n-1);
                scanf("%d",&pos);

                arr=deleteElem(arr,&n,pos);
                break;

            case 5:
                printf("\nEnter the element to search: ");
                scanf("%d",&elem);
                searchElem(arr,n,elem);
                break;
            case 6:
                printf("\n\nExiting...\n");
                free(arr);
                exit(0);

            default:
                printf("\nInvalid Choice\n");
        }
    }
}


void menu() {
    printf("---------MENU-----------\n");
    printf("1. Create Array\n");
    printf("2. Display Array\n");
    printf("3. Insert Element\n");
    printf("4. Delete Element\n");
    printf("5. Search Element\n");
    printf("6. Exit\n");
    printf("--------------------\n");
}

//Function to Create a Array using Pointer by defining the Size
int* createArray(int n) {
    int *arr=(int*)malloc(sizeof(int)*n);
    if (arr==NULL) {
        printf("Memory Allocation Failed");
        exit(1);
    }
    printf("Enter %d elements:\n ",n);
    for(int i=0;i<n;i++) {
        printf("Enter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    return arr;
}

//Function to Display Array Elements
void displayArray(int* arr, int n) {
    printf("Displaying Array\n");
    for(int i=0;i<n;i++) {
        printf("Index %d -> %d\n", i, arr[i]);
    }
    return;
}

int* insertElem(int* arr, int *n, int elem, int pos) {
    if (pos < 0 || pos > *n ) {
        printf("Invalid Position");
        return arr;
    }
    arr= (int*)realloc(arr, sizeof(int)*(*n+1));
    for (int i=*n;i > pos;i--) {
        arr[i]=arr[i-1];
    }
    arr[pos]=elem;
    (*n)++;
    printf("Element %d Inserted at position %d",elem,pos);
    return arr;
}

//Function to delete an element from a position
int* deleteElem(int* arr, int *n, int pos) {
    if (pos < 0 || pos >= *n ) {
        printf("Invalid Position");
        return arr;
    }
    int deleted= arr[pos];
    for (int i=pos;i<*n-1;i++) {
        arr[i]=arr[i+1];
    }
    arr=(int*)realloc(arr, sizeof(int)*(*n-1));
    (*n)--;
    printf("Element %d Deleted at position %d",deleted,pos);
    return arr;
}

//Function to Search an element in the Array
void searchElem(int* arr, int n, int elem) {
    int found=0;
    for(int i=0;i<n;i++) {
        if(arr[i]==elem) {
            printf("Element found at Index : %d",i);
            return;
        }
    }
    printf("Element not found in the Array");
}

