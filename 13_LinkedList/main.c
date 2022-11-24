/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \main.c                                                                                    *
* Project: 13_LinkedList                                                                           *
* Created Date: Thursday Nov 24th 2022, 8:53:18 am                                                 *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 24/11/2022 09:12:0                                                                *
* Modified By: Wenren Muyan                                                                        *
* --------------------------------------------------------------------------------                 *
* Copyright (c) 2022 - future Wenren Muyan                                                         *
* --------------------------------------------------------------------------------                 *
* HISTORY:                                                                                         *
* Date				By				Comments                                                       *
* --------------------------------------------------------------------------------                 *
***************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linkedlist.h"

int main(){
    linkedList * l = (linkedList *)malloc(sizeof(linkedList));

    int i, key, count = 0, k;

    srand(time(NULL));

    initLinkedL(l);

    for(i = 0; i < 10; i++){
        insertAfterLinkedL(l, i);
    }

    printLinkedL(l);

    return 0;
}
