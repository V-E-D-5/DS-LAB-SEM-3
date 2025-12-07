#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Term {
    int coeff, exp_x, exp_y, exp_z;
    struct Term *next;
} Term;

Term *header = NULL;  // Global header node

// Initialize header node
void initList() {
    header = (Term*)malloc(sizeof(Term));
    header->next = header;  // circular link
}

// Insert term at end
void insertTerm(int c, int x, int y, int z) {
    Term *newNode = (Term*)malloc(sizeof(Term));
    newNode->coeff = c;
    newNode->exp_x = x;
    newNode->exp_y = y;
    newNode->exp_z = z;
    newNode->next = header;

    Term *temp = header;
    while (temp->next != header)
        temp = temp->next;
    temp->next = newNode;
}

// Display polynomial
void display() {
    Term *cur = header->next;
    if (cur == header) {
        printf("0\n");
        return;
    }
    int first = 1;
    while (cur != header) {
        if (!first) printf(cur->coeff >= 0 ? " + " : " - ");
        else if (cur->coeff < 0) printf("-");
        first = 0;

        int absC = abs(cur->coeff);
        if (absC != 1 || (!cur->exp_x && !cur->exp_y && !cur->exp_z))
            printf("%d", absC);
        if (cur->exp_x) printf("x^%d", cur->exp_x);
        if (cur->exp_y) printf("y^%d", cur->exp_y);
        if (cur->exp_z) printf("z^%d", cur->exp_z);
        cur = cur->next;
    }
    printf("\n");
}

// Evaluate polynomial
double evaluate(double x, double y, double z) {
    double sum = 0;
    for (Term *cur = header->next; cur != header; cur = cur->next)
        sum += cur->coeff * pow(x, cur->exp_x) * pow(y, cur->exp_y) * pow(z, cur->exp_z);
    return sum;
}

// Free memory
void freeList() {
    Term *cur = header->next, *temp;
    while (cur != header) {
        temp = cur;
        cur = cur->next;
        free(temp);
    }
    free(header);
}

int main() {
    initList();

    // P(x,y,z) = 6x²y²z - 4yz⁵ + 3x³yz + 2xy⁵z - 2xyz³
    insertTerm(6, 2, 2, 1);
    insertTerm(-4, 0, 1, 5);
    insertTerm(3, 3, 1, 1);
    insertTerm(2, 1, 5, 1);
    insertTerm(-2, 1, 1, 3);

    printf("Polynomial P(x,y,z) = ");
    display();

    double x, y, z;
    printf("Enter values for x y z: ");
    scanf("%lf %lf %lf", &x, &y, &z);

    printf("P(%.2f, %.2f, %.2f) = %.4f\n", x, y, z, evaluate(x, y, z));

    freeList();
    return 0;
}
