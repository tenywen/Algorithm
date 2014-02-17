/*
*
*       @merge sort
*       @O(nlgn)
*       @max stack
*       @int
*
*       
*/

#include <stdio.h>
#include "inc/common.h"
#include "../include/StackSort.h"
#define LEFT(i) (i >> 1)
#define RIGHT(i) ((i >> 1) + 1)
#define PARENT(i) iCEIL(i)

Stack *Creat() {
    Stack* p = NULL;
    p = (Stack*)malloc(sizeof(Stack));
    if(p == NULL) {
        printf("err : create stack failed"); 
        return p;
    }
    p->size = 0;
    return p; 
}

// 将当前节点作为根节点，向下调整，以保持最大堆的特征
int _stack_down(Stack* p,int seq) {
    int largest = seq; 
    int right = RIGHT(seq);
    int left = LEFT(seq);
    while(seq <= p->size) {
        if(left <= p->size && p->stack[left - 1] > p->stack[largest - 1]) {
            largest = left; 
        } 

        if(right <= p->size && p->stack[right - 1] > p->stack[largest - 1]) {
            largest = right;
        }
        // 不需要调整
        if(largest == seq) {
            break; 
        }
        SWAP(p->stack[largest - 1],p->stack[seq - 1]);
        seq = largest;
    }
    return 0;
}

int Print(stack)

int Build_stack(Stack* p) {
    int seq = 0;
    for(seq = iFLOOR(p->size/2) ; seq > 0; seq --) {
        _stack_down(p,seq); 
    }
}
