#include<stdio.h>
#include<stdlib.h>

void TOI(int, char, char, char);

int main() {
    int n;
    char s = 'S';
    char a = 'A';
    char d = 'D';

    printf("Enter the Total Number of Disks: ");
    scanf("%d", &n);

    TOI(n, s, a, d);
    return 0;
}

void TOI(int n, char s, char a, char d) {
    if (n == 1) {
        printf("Move disk from %c to %c\n", s, d);
        return;
    }

    TOI(n - 1, s, d, a);
    TOI(1, s, a, d);
    TOI(n - 1, a, s, d);
}