/*
*
*       @insert sort
*       @O(n^2)
*       @Int
*       @from 1 to n
*       @only limited nums not sort
*/
#include <stdio.h>
#include <stdlib.h>
int InsertSort(int* A,int length) {
    int i = 0;
    int j = 0;
    int key = 0;
    for(i = 1; i < length; i ++) {
        // save key value to complete
        key = A[i];
        j = i - 1;
        while(A[j] > key && j >= 0) {
            // j move to j + 1
            A[j + 1] = A[j]; 
            j --;
        }
        // while(j--)
        // so j + 1 is true pos to insert key value
        A[j + 1] = key;
    }
    return 0;
}

// only for test
int main() {
    int A[10] = {1,23,43,12,2,2,4,7878,1000,24};
    int i = 0;
    for (; i < 10; i ++) {
        printf("%d",A[i]);
        printf(" ");
    }
    printf("\n");
    InsertSort(A,10);
    for (i = 0; i < 10; i ++) {
        printf("%d",A[i]);
        printf(" ");
    }
    return 0;
}
