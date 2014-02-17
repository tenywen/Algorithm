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
    INT     = 1,
    STRUCT  = 2,
    POINT   = 3,    // 指针&引用
} ;

struct Obj {
    enum TYPE Type;
    union {
        int int_value;
        struct point* point_value;
    } Value;
    struct Obj* Next;
    int Count;  // 引用计数器
    bool Mark;
};

struct pair {
    struct Obj* head;
    struct Obj* tail; 
};

struct point {
    struct Obj* value;
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

int ObjCountAdd(struct Obj* obj) {
    obj->Count ++;
    return 0;
}

struct Obj* Malloc(struct VM* vm,TYPE type) {
    struct Obj* obj = (struct Obj*)malloc(sizeof(struct Obj));
    printf("malloc %p",obj);
    if(!obj) 
        return NULL; 
    InitObj(obj);
    obj->Type = type;
    MarkObj(obj);
    pushVM(vm,obj);
    return obj;
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

// 限于指针绑定
int Bind(struct Obj* obj, struct Obj* src) {
    if(obj->Type != POINT) {
        return 0;  
    } 
    struct Obj* real = src;
    if(src->Type == POINT) {
        real = src->point_value->value;
    }
    obj->point_value->value = real;
    real->Count ++;
    return 0;
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

int Free(struct Obj* obj) {
    if(obj->)
}

int Sweep(struct VM* vm) {
    struct Obj** curr;
    struct Obj* entry;
    curr = &vm->head;
    for(; *curr;) {
        entry = *curr;
        if(!entry->Count) {
            *curr = entry->next;  
            free(entry); 
        } else {
            curr = &entry->next; 
            entry->Mark = false;
        }
    }
    return 0;
}

int main() {
    return 0;
}
