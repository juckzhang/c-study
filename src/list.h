//
// Created by zhangchao12 on 2020/12/12.
//

#ifndef C_STUDY_LIST_H
#define C_STUDY_LIST_H

#include <sys/types.h>

typedef struct list_s list_t;
typedef struct list_head_s list_head;

struct list_head_s{
    list_t *head;
    list_t *tail;
    int num;
};

struct list_s{
    list_t *next;
    list_t *prev;
    int len;
    char data;
};

#define data_to_list(d) (list_t *)((char *)d - offset(list_t, data))

void *list_insert_head(list_head *head, size_t n);
void *list_insert_tail(list_head *head, size_t n);
list_t *list_remove_head(list_head *head);
list_t *list_remove_tail(list_head *tail);
void list_remove_item(list_head *head, list_t *i);
void delet_list(list_head * list);


#endif //C_STUDY_LIST_H
