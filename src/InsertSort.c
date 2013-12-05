/*
*
*       @insert sort
*       @O(n^2)
*       @int32
*       @from 1 to n
*       @only limited nums not sort
*/
#include <stdio.h>
#include "../include/common.h" 
int32 InsertSort(int32* A,int32 length) {
    int32 i = 0;
    int32 j = 0;
    int32 key = 0;
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
int32 main() {
    int32 A[10] = {1,23,43,12,2,2,4,7878,1000,24};
    int32 i = 0;
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
