/*
*
*       @insert sort
*       @O(n^2)
*       @int32
*       @from 1 to n
*       @only limited nums which not sort not in A[]
*/

int InsertSort(int* A,int q, int r) {
    int i = 0;
    int j = 0;
    int key = 0;
    for(i = q + 1; i <= r; i ++) {
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
