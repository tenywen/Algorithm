// only for test
#include <stdio.h>
#include "../include/InsertSort.h"

int main() {
    int A[10] = {1,23,43,12,2,2,4,7878,1000,24};
    int i = 0;
    for (; i < 10; i ++) {
        printf("%d",A[i]);
        printf(" ");
    }
    printf("\n");
    InsertSort(A,0,9);
    for (i = 0; i < 10; i ++) {
        printf("%d",A[i]);
        printf(" ");
    }
    return 0;
}
