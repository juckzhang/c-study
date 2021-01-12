#include <iostream>
#include <list>
#include <ucontext.h>

using namespace std;

typedef void (func)(void);

typedef struct __co {
    ucontext_t upc;
    func *fun;
    void *args;
    int status;
} _co;

typedef struct __sched{
    list<_co*> readyList;
    _co *curr_co;
    ucontext_t main_co;
}_sched;


_sched globle_shced;

int create_co(_co **new_co, func *fun, void *args){
    _co *co = (_co *)malloc(sizeof(_co));
    getcontext(&co->upc);
    (&co->upc)->uc_stack.ss_sp = (char*)malloc(sizeof(char)*1024);
    (&co->upc)->uc_stack.ss_size = 1024;
    (&co->upc)->uc_link = &globle_shced.main_co;
    co->fun = fun;
    co->args = args;
    co->status = 0;

    globle_shced.readyList.push_back(co);

    *new_co = co;

    return 1;
}

int resume(_co *co){
    if(co->status == 0){
        makecontext(&co->upc, co->fun, 0);
        co->status = 1;
    }

    swapcontext(&globle_shced.main_co, &co->upc);

    return 1;
}

int yield(_co *co){
    globle_shced.curr_co = NULL;
    globle_shced.readyList.push_back(co);
    swapcontext(&co->upc, &globle_shced.main_co);
}

void free_co(_co *co){
    free((&co->upc)->uc_stack.ss_sp);
    free(co);
}

void sched_run(void){
    while(!globle_shced.readyList.empty()){
        _co *co = globle_shced.readyList.front();
        globle_shced.readyList.pop_front();
        if(co){
            globle_shced.curr_co = co;
            resume(co);
        }
    }
}

void func2(void){
    cout << "before yield func2" << endl;
    yield(globle_shced.curr_co);
    cout << "after yield func2" << endl;
}

#define MAX_CO_NUM 2

int main() {
    int i = 0;
    _co *coList[MAX_CO_NUM];

    for (; i < MAX_CO_NUM; ++i) {
        create_co(&coList[i], func2, NULL);
    }

    sched_run();

    for (i = 0; i < MAX_CO_NUM; ++i) {
        free_co(coList[i]);
    }
}