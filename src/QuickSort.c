/*
*
*       @quick sort
*       @O(nlgn)
*       @int
*       @from 1 to n
*       @1.Recursion
*       
*/

#include <stdio.h>
#include "inc/common.h"

// l,h为序号,index
int _partion(int *A, int l, int h) {
	
	
	int key = A[l];
	int large = l + 1;
    int i = 0;
    //[key,less,less,less,large,large,query,...]
	for(i = l + 1; i <= h; i ++) {
		if(key >= A[i]) {
			SWAP(A[large],A[i]);
			large = large + 1;
		}
	}
	SWAP(A[l],A[large - 1]);
    printf("large = %d\n",large);
	return large - 1;
}

int QuickSort(int *A,int l, int h) {
    // 判断临界
	if(l == h) {
		return 0;
	}
    int pos = _partion(A,l,h);
    //printf("pos = %d\n",pos);
    //QuickSort(A,l,pos - 1);
    //QuickSort(A,pos + 1,h);
    return 0;
}

int main() {
    int A[] = {10,23,3,42,55,7,7,8,9,12};
    QuickSort(A,0,9);
    int i = 0;
    for(; i < 10; i ++) {
        printf("%d ",A[i]); 
    }
    return 0;
}
