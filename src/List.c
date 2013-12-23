#include <stdio.h>
#include <stdlib.h>
struct Node {
    int value;
    Node* next;
};

typedef bool (*RM)(Node*);
typedef bool* (*ADD)(Node*);     // insert pos prev

int Del(Node *head,RM f) {
    if(head == NULL) {
        printf("list is null");
        return 0;
    }
    Node** curr = &head;
    Node* entry = NULL;
    for(;*curr;) {
        entry = *curr;
        if(f(entry)) {
            *curr = entry->next; 
            free(entry);
        } else {
            curr = &entry->next; 
        }
    }
    return 0;
}

Node* Insert(Node *head,Node *p) {
    Node** curr = &head; 
    for(;*curr;) {
         
    }
    return head;
}

int main() {

    return 0;
}
