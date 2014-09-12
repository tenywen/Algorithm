#include <stdio.h> 
#include <stdlib.h>

struct Node {
    struct Node *parent;
    struct Node* left;
    struct Node* right;
    int          value;
};

struct Tree {
    struct Node* root;
};

typedef struct Node* pNode; 

// insert node to binary tree
int Insert(Tree* T,pNode p) {
    pNode node = T->root;   
    pNode parent = NULL;
    // 遍历二叉树，找到合适的位置
    while(node != NULL) {
        parent = node;
        if (node->value >= p->value) {
            node = node->left;     
        } else {
            node = node->right;   
        }
    }
    if(T->root == NULL) { // binary tree is empty 
        T->root = p;  
        return 0;
    } 
    // 找到合适的位置插入！
    if(parent->value >= p->value) {
        parent-> left = p;
    } else {
        parent-> right = p;
    }
    p->parent = parent;
    return 0;
}

// y替换x
int _transplant(Tree* T,pNode x,pNode y) {
    if(x->parent == NULL) { // x is root
        T->root = y;
    } else if(x->parent->left == x) {
        x->parent->left = y ;
    } else {
        x->parent->right = y ;
    }
    if(y != NULL) {
        y->parent = x->parent;
    }
    return 0;
}

// get 后续节点
pNode Min(pNode p) {
    if(p == NULL) {
        return NULL;
    }
    pNode node = p;
    while(node->left != NULL) {
       node = node->left; 
    }
    return node;
}

// del node from binary tree  
int Del(Tree* T,pNode p) {
    if(p->left == NULL) { 
        _transplant(T,p,p->right);
    } else if(p->right == NULL) {
        _transplant(T,p,p->left);
    } else {
        pNode y = Min(p->right);  // p的后续节点  
        if (y->parent != p) { // y 不是p的子节点
            _transplant(T,y,y->right);
            y->right = p->right; 
            p->right->parent = y;
        }
        // y 是p的子节点，则一定是左子节点
        _transplant(T,p,y); 
        y->left = p->left;
        p->left->parent = y;
    }
}

// print tree 
int Print(pNode root) {
    if(root->left != NULL) {
        Print(root->left); 
    } 
    printf("%d ",root->value);
    if(root->right != NULL) {
        Print(root->right);
    }
    return 0;
}

int main() {
    Tree* T = (Tree*)malloc(sizeof(Tree));
    pNode p = (pNode)malloc(sizeof(Node));
    p->parent = NULL;
    p->left = NULL;
    p->right = NULL;
    p->value = 10; 
    T->root = p;

    pNode p1 = (pNode)malloc(sizeof(Node));
    p1->parent = NULL;
    p1->left = NULL;
    p1->right = NULL;
    p1->value = 1;
    Insert(T,p1);
    
    pNode p2 = (pNode)malloc(sizeof(Node));
    p2->parent = NULL;
    p2->left = NULL;
    p2->right = NULL;
    p2->value = 13;
    Insert(T,p2);

    pNode p3 = (pNode)malloc(sizeof(Node));
    p3->parent = NULL;
    p3->left = NULL;
    p3->right = NULL;
    p3->value = 11;
    Insert(T,p3);

    pNode p4 = (pNode)malloc(sizeof(Node));
    p4->parent = NULL;
    p4->left = NULL;
    p4->right = NULL;
    p4->value = 12;
    Insert(T,p4);
    
    Print(T->root);
    printf("\n");
    Del(T,p);
    Print(T->root);
    return 0;
}
