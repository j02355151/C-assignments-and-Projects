#include <stdio.h>
#include <stdlib.h>

void populateArray(int* A1) {
    int i ;
    for (i = 0; i < 10; i++) {
        A1[i] = 100 + i;

    }
}

void changeArray(int* A1, int** PTR1) {
    *PTR1 = &A1[4];
    **PTR1 = 99;

    int i;
    for (i = 0; i < 10; i++) {
        printf("%d ", A1[i]);
    }
}

int main() {
    int A1[10];
    int* PTR1;

    populateArray(A1);

    changeArray(A1, &PTR1);

    return 0;
}
