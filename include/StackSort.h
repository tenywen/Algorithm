#ifndef _STACK_SORT_H_

#define _STACK_SORT_H_
#define STACK_SIZE 100
struct Stack {
    int stack[STACK_SIZE];
    int size; 
};

extern Stack* Create();
extern int BuildStack(Stack* p);
extern int GetMax(Stack* p);

#endif
