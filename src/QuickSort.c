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
int QuickSort

// l,h为序号,index
int _partion(int *A, int l, int h) {
	// 判断临界
	if(l == h) {
		return l
	}
	
	int key = A[l];
	int large = l + 1;
	for (i = l + 1; i <= h; i ++) {
		if(key >= A[i]) {
			SWAP(a[large],A[i]);
			large = large + 1;
		}
	}
	SWAP(A[l],A[large - 1]);
	return 0;
}
