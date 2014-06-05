/*
*
*       @tree.h
*       @int
*       
*/

#include <stdio.h> 

struct Node {
    struct Node *parent;
    struct Node* left;
    struct Node* right;
    int          value;
};

typedef struct Node* pNode;
