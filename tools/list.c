#include <stdio.h>
#include "list.h"
#include <stdlib.h>

struct test {
    struct  list_head member; 
    int     value; 
};

int main() {
    LIST_HEAD(head); 
    struct test* p1 = (struct test*)malloc(sizeof(struct test));   
    p1->member.next = &(p1->member);
    p1->member.prev = &(p1->member);
    p1->value = 100;
    list_add_tail(&p1->member,&head);  
    struct test* p2 = (struct test*)malloc(sizeof(struct test));   
    p2->member.next = &(p2->member);
    p2->member.prev = &(p2->member);
    p2->value = 200;
    list_add_tail(&p2->member,&head);  

    struct test* p3 = (struct test*)malloc(sizeof(struct test));   
    p3->member.next = &(p3->member);
    p3->member.prev = &(p3->member);
    p3->value = 300;
    list_add_tail(&p3->member,&head);  
    struct test *p = NULL;
    struct test *n = NULL;
    list_for_each_entry_safe(p,n,&head,member){
        list_del(p);
        printf("%d\n",p->value);
    }
    return 0;
}
