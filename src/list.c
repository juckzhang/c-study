//
// Created by zhangchao12 on 2020/12/12.
//
#include "list.h"
#include "mem.h"

void *list_insert_head(list_head *list, size_t n){
    list_t * i = m_alloc(sizeof(list_t) + n);

    i->next = list->head;
    i->prev = NULL;
    i->len = n;
    if(list->head){
        list->head->prev = i;
    }
    list->head = i;
    if(list->tail == NULL){
        list->tail = i;
    }
    list->num++;

    return (void *)&i->data;
}

void *list_insert_tail(list_head *list, size_t n){
    list_t * i = m_alloc(sizeof(list_t) + n);

    i->next = NULL;
    i->prev = list->tail;
    i->len = n;
    if(list->tail){
        list->tail->next = i;
    }
    list->tail = i;
    if(list->head == NULL){
        list->head = i;
    }
    list->num++;

    return (void *)&i->data;
}

list_t *list_remove_head(list_head *list){
    if(!list->head){
        return NULL;
    }

    list_t * i = list->head;
    list->head = i->next;

    if(list->head){
        list->head->prev = NULL;
    }else{
        list->tail = NULL;
    }
    i->next = NULL;
    list->num--;

    return i;
}

list_t *list_remove_tail(list_head *list){
    if(!list->tail){
        return NULL;
    }

    list_t * i = list->tail;
    list->tail = i->prev;
    if(list->tail){
        list->tail->next = NULL;
    }else{
        list->head = NULL;
    }
    i->prev = NULL;
    list->num--;

    return i;
}

void list_remove_item(list_head *list, list_t *i){
    if(i == NULL){
        return;
    }
    if(list->head == i){
        list_remove_head(list);
    }else if(list->tail == i){
        list_remove_tail(list);
    }

    list_t *prev = i->prev;
    list_t *next = i->next;

    prev->next = next;
    next->prev = prev;

    list->num--;
}

void delet_list(list_head *list){
    list_t *next;

    while ((next = list->head) != NULL){
        list->head = next->next;
        m_free(next);
    }
}
