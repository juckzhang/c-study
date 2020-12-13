//
// Created by zhangchao12 on 2020/12/12.
//

#ifndef SHAREMEM_MEM_H
#define SHAREMEM_MEM_H

#include "config.h"

void * m_alloc(size_t n);

void m_free(void * p);


#endif //SHAREMEM_MEM_H
