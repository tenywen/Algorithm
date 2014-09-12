#ifndef _LIST_H_ 
#define _LIST_H_ 

/* 
 * MEMBER 地址  Copied from include/linux/
 */
#undef offsetof 
#define offsetof(TYPE, MEMBER) ((size_t) &(((TYPE *)0)->MEMBER)) 

/*
 * container_of - 得到member 所在的structure 地址 
 * @ptr:        the pointer to the member 
 * @type:       the type of the container struct this is embedded in 
 * @member:     the name of the member within the struct
 */
#define container_of(ptr, type,member) \
                ({\
                    const typeof(((type *)0)->member) *_mptr = (ptr); \
                    (type*)( (char *)_mptr - offsetof(type,member) ); \
                 })

struct list_head {
    struct list_head *next,*prev; 
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name) \
            struct list_head name = LIST_HEAD_INIT(name)

#define list_entry(ptr,type,member) \
           container_of(ptr,type,member)

/*
 * list_for_each_entry - 遍历list 串联的结构
 * @pos:        the pointer to the structure 
 * @head:       head of the pointer to the member 
 * @member:     the name of the list_head in the struct
 */
#define list_for_each_entry(pos, head,member) \
            for(pos = list_entry((head)->next,typeof(*pos), member); \
                &(pos->member) != (head); \
                pos = list_entry(pos->member.next, typeof(*pos),member))  


/*
 * list_for_each_entry_safe - iterate over list for safe
 * @pos:        
 *
 */
#define list_for_each_entry_safe(pos,n,head,member) \
            for(pos = list_entry((head)->next,typeof(*pos),member), \
                n = list_entry(pos->member.next,typeof(*pos),member);\
                &pos->member != (head); \
                pos = n,n = list_entry(n->member.next,typeof(*n),member))

static inline void _list_add(struct list_head *_new,
                             struct list_head *prev,
                             struct list_head *next)
{
    next->prev = _new;
    _new->next = next;
    _new->prev = prev;
    prev->next = _new;
}

static inline void list_add_tail(struct list_head *_new, struct list_head *head) 
{
    _list_add(_new,head->prev,head);
}

/*
 * delete list between prev and next 
 * 
 */
static inline void _list_del(struct list_head *prev,struct list_head *next) {
    next->prev = prev;
    prev->next = next;
}

/*
 * list_del - delete entry from list
 * @entry:      the element to delete from the list
 */
static inline void list_del(struct list_head *entry) {
    _list_del(entry->prev,entry->next);
    entry->prev = entry;
    entry->next = entry;
}

#endif
