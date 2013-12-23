/*
*
*       @mark sweep
*       @
*       @
*       @
*       @
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "inc/common.h"
#define MAX  1024

#ifndef _COMMON_H_
#define true 1;
#define false 0;
typedef int bool;
#endif

typedef int error;
enum TYPE {
    Int     = 1,
    Pair    = 2,
} ;

struct Obj {
    enum TYPE type;
    union {
        int int_value;
        struct pair* pair_value;
    } Value;
    struct Obj* next;
    bool Mark;
};

struct pair {
    struct Obj* head;
    struct Obj* tail; 
};

struct VM {
    struct Obj* head;       // 指向所有objs
    struct Obj* objs[MAX];  // 存放使用中的objs指针
    int length;
};

int InitObj(struct Obj* obj) {
    // undo
    return 0;
}

struct VM* newVM() {
    struct VM* vm =  (struct VM*)malloc(sizeof(struct VM));
    vm->length = 0;
    vm->head = NULL;
    return vm;
}

bool pushVM(struct VM* vm,struct Obj* obj) {
    if(vm->length == MAX - 1) 
        return false;
    vm->objs[vm->length ++] = obj; 
    return true;
}


int MarkObj(struct Obj* obj) {
    obj->Mark = true;
    return 0;
}

bool popVM(struct VM* vm) {
    if(vm->length > 0) {
        vm->objs[vm->length --]->Mark = false;
        return true; 
    }
    return false;
}

int Mark(struct VM* vm) {
    int i = 0;
    for(; i <= vm->length; i ++) {
        vm->objs[i]->Mark = true;         
    }
    return 0;
}

int Sweep(struct VM* vm) {
    struct Obj** curr;
    struct Obj* entry;
    curr = &vm->head;
    for(; *curr;) {
        entry = *curr;
        if(!entry->Mark) {
            *curr = entry->next;  
            free(entry); 
        } else {
            curr = &entry->next; 
            entry->Mark = false;
        }
    }
    return 0;
}

struct Obj* Malloc(struct VM* vm) {
    struct Obj* obj = (struct Obj*)malloc(sizeof(struct Obj));
    if(!obj) 
        return NULL; 
    InitObj(obj);
    pushVM(vm,obj);
    MarkObj(obj);
    return obj;
}

int main() {
    return 0;
}
