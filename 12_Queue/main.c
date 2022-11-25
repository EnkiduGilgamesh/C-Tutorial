/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \main.c                                                                                    *
* Project: 12_Queue                                                                                *
* Created Date: Saturday Nov 5th 2022, 4:43:42 pm                                                  *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 25/11/2022 09:28:13                                                               *
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
#include "queue.h"

int main(){
    queue * q = (queue *)malloc(sizeof(queue));
    initQueue(q, 4);

    for(int i = 0; i < 4; i++)
        enQueue(q, i);
    for(int i = 0; i < 4; i++)
        deQueue(q);
    /*enQueue(q, 3);
    enQueue(q, 3);
    enQueue(q, 3);
    enQueue(q, 3);
    deQueue(q);*/
    for(int i = 0; i < 4; i++) enQueue(q, i);
    for(int i = 0; i < 4; i++) enQueue(q, i);

    printQueue(q);

    printf("\n%d  %d\n", q->front, q->rear);
    printQueue(q);
    //for(int i = 0; i < 4; i++){
    //    deQueue(q);
    //}
    //for(int j = 0; j < 4; j++) enQueue(q, 10);

    printQueue(q);

    system("pause");

    return 0;

}
