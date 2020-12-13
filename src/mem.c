//
// Created by zhangchao12 on 2020/12/12.
//

#include "mem.h"
#include "config.h"


void * m_alloc(size_t n){
    void *i = malloc(n);
    if(i == NULL){
        return NULL;
    }
//    memset(i 0, n);

    return i;
}

void m_free(void * p){
    free(p);
}