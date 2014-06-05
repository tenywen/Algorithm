/*
*
*       @merge sort
*       @O(nlgn)
*       @int
*       @from 1 to n
*       @1.Recursion
*       
*/
#include <stdio.h>
extern int InsertSort(int* A,int q,int r);

int _merge_sort(int* A, int q, int r) {
    int m = 0;
    if(r > q) {
        m = (q + r) / 2;
        printf("q = %d, m = %d ,r = %d\n",q,m,r);
        // separate
        _merge_sort(A,q,m);
        _merge_sort(A,m + 1,r);
        // merge
        InsertSort(A,q,r);
    }
    return 0;
}

int MergeSort(int* A,int length) {
    _merge_sort(A,0,0 + length - 1);
    return 0;
}

