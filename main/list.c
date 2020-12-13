//
// Created by zhangchao12 on 2020/12/12.
//

#include "config.h"
#include "list.h"

list_head list = {NULL,NULL, 0};

int main(void){
    int i;
    int num = 100;
    int *item;

    for(i = 0; i < num; ++i){
        item = list_insert_head(&list, sizeof(int));
        if(item == NULL){
            printf("内存申请失败!\n");
            break;
        }
        *item = i;
    }

    list_t *node = list.head;
    while (node != NULL){
        item = (int *) &node->data;
        printf("%d,",*item);
        node = node->next;
    }
    printf("\n");

    delet_list(&list);
    return 0;
}
