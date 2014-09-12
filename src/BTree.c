#include <stdio.h>
#include <stdlib.h>

enum COLOR {RED,BLACK};

struct BTreeNode {
    enum    COLOR      color;
    struct  BTreeNode* parent;
    struct  BTreeNode* left;
    struct  BTreeNode* right;
    int     value;
};

struct BTree {
    struct BTreeNode* root;
};

typedef struct BTreeNode* pBTreeNode;

// 左旋 p节点
int _left_rotate(BTree* T,pBTreeNode p) {
    pBTreeNode y = p->right;
    if(p == NULL || y == NULL) {
        printf("没法左旋 [p=%p]\n",p);
        return 0; 
    }
    y->parent = p->parent; 
    p->left = y->right;
    y->right->parent = p; 
    y->right = p;
    p->parent = y;
    if(y->parent == NULL) {
        T->root = y;  
    } else if(y->parent->left == p) {
        y->parent->left = y; 
    } else {
        y->parent->right = y; 
    }
    return 0;
}

// 右旋 p节点
int _right_rotate(pBTreeNode p) {
    pBTreeNode y = p->left;
    if(p == NULL || y == NULL) {
        printf("没法右旋 [p=%p]\n",p);
        return 0; 
    }
    y->parent = p->parent;
    p->right = y->left; 
    y->left->parent = p; 
    y->left = p;
    p->parent = y;
    if (y->parent == NULL) {
        T->root = y; 
    } else if(y->parent->left == p) {
        y->parent->left = y; 
    } else {
        y->parent->right = y; 
    }
}

// 以p节点为起点，向上(祖先节点)调整红黑性质 
// 因为插入的节点是红，所以只会破环红节点的子节点只能是黑这个性质
int _fix_insert_black_red(pBTreeNode p) {
    pBTreeNode y = NULL; 
    pBTreeNode x = p;
    while(x->parent != NULL && x->parent->color == RED) {
        if(x->parent == x->parent->parent->left) {
            y = x->parent->parent->right;   // 叔节点
            if(y->color == RED) { // 叔节点为红 
                x->parent->color = BLACK;
                y->color = BLACK; 
                x->parent->parent->color = RED; 
                x = x->parent->parent;
            } else {
                // 先左转，再右转。保持树的节点！
                if(x == x->parent->right) { // y->color 为黑 
                    x = x->parent;                               
                    _left_rotate(x);  
                }
                x->parent->color = BLACK;
                x->parent->parent->color = BLACK; 
                _right_rotate(x->parent);
            }
        } else {
            y = x->parent->parent->left;
            if(y->color == RED) {
                x->parent->color = BLACK;
                y->color = BLACK;
                x->parent->parent->color = RED;
                x = x->parent->parent;
            } else {
                if(x == x->parent->left) {
                    x = x->parent; 
                    _right_rotate(x); 
                }  
                x->parent->color = BLACK;
                x->parent->parent->color = RED;
                _left_rotate(x->parent);
            }
        }
    }
}


// insert  
// 插入的节点color 为红  考虑父节点为黑，则不需要考虑。为红，则调整
int Insert(BTree* T,pBTreeNode p) {
    if(p == NULL) {
        return 0; 
    }

    pBTreeNode parent = NULL;
    pBTreeNode node = T->root;
    while(node != NULL) {
        parent = node;
        if(node->value >= p->value) {
            node = node->left; 
        } else {
            node = node->right; 
        }
    }
    
    // T is empty
    if(parent == NULL) {
        T->root = p; 
        T->root->color = BLACK;
        return 0;
    }
    
    if(parent->value >= p->value) {
        parent->left = p; 
    } else {
        parent->right = p; 
    }
    p->parent = parent;  
    if(p->parent != NULL) {
       // _fix_insert_black_red(p);
    }
    T->root->color = BLACK;
    return 0;
}

// x instead of p
int _replace(BTree* T,pBTreeNode p,pBTreeNode x) { 
    if(p->parent == NULL) { // p is root
        T->root = x; 
        x->parent = NULL;
    } else if(p->parent->left == p) {
        p->parent->left = x; 
    } else {
        p->parent->right = x; 
    }
    if(x != NULL) {
        x->parent = p->parent; 
    }
    return 0;
}

int Del(BTree *T,pBTreeNode p) {
    
}

int init(pBTreeNode p,enum COLOR color,int value) {
    p->parent = NULL;
    p->left = NULL;
    p->right = NULL; 
    p->color = color;
    p->value = value;
    return 0;
}

int Print(pBTreeNode p) {
    if(p == NULL) {
        return 0; 
    }
    Print(p->left);
    printf("(%d %d) ",p->value,p->color);
    Print(p->right);
    return 0;
}

int main() {
    BTree* T = (BTree*)malloc(sizeof(BTree));
    pBTreeNode p = (pBTreeNode)malloc(sizeof(BTreeNode));
    init(p,BLACK,11); 
    T->root = p;
    //Print(T->root); 
    //printf("\n"); 

    pBTreeNode p1 = (pBTreeNode)malloc(sizeof(BTreeNode));
    init(p1,RED,2);
    Insert(T,p1);

    Print(T->root); 
    printf("\n"); 

    pBTreeNode p2 = (pBTreeNode)malloc(sizeof(BTreeNode));
    init(p2,BLACK,14);
    Insert(T,p2);

    Print(T->root); 
    printf("\n"); 
    
    pBTreeNode p3 = (pBTreeNode)malloc(sizeof(BTreeNode));
    init(p3,BLACK,1);
    Insert(T,p3);
    
    Print(T->root); 
    printf("\n"); 
    
    pBTreeNode p4 = (pBTreeNode)malloc(sizeof(BTreeNode));
    init(p4,BLACK,7);
    Insert(T,p4);

    Print(T->root); 
    printf("\n"); 
    
    pBTreeNode p5 = (pBTreeNode)malloc(sizeof(BTreeNode));
    init(p5,RED,5);
    Insert(T,p5);
    
    pBTreeNode p6 = (pBTreeNode)malloc(sizeof(BTreeNode));
    init(p6,RED,8);
    Insert(T,p6);
    
    pBTreeNode p7 = (pBTreeNode)malloc(sizeof(BTreeNode));
    init(p7,RED,4);
    Insert(T,p7);
    
    pBTreeNode p8 = (pBTreeNode)malloc(sizeof(BTreeNode));
    init(p8,RED,15);
    Insert(T,p8);

    Print(T->root);
    return 0;
}
