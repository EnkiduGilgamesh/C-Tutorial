/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \main.c                                                                                    *
* Project: 12_Queue                                                                                *
* Created Date: Saturday Nov 5th 2022, 4:43:42 pm                                                  *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 5/11/2022 05:41:13                                                                *
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
    queue * q;
    initQueue(q, 4);


    for(int i = 0; i < 4; i++) enQueue(q, i);

    printQueue(q);

    enQueue(q, 4);

    printf("\n");

    printQueue(q);

    printf("\n");

    //deQueue(q);

    for(int i = 0; i < 4; i++) deQueue(q);

    printQueue(q);

    printf("\n%d  %d", q->front, q->rear);

    printf("\n");

    enQueue(q, 10);
    printf("\n%d  %d\n", q->front, q->rear);
    enQueue(q, 20);
    printf("\n%d  %d\n", q->front, q->rear);
    enQueue(q, 30);
    printf("\n%d  %d\n", q->front, q->rear);
    enQueue(q, 40);
    printQueue(q);
    printf("\n%d  %d\n", q->front, q->rear);
    enQueue(q, 50);
    printQueue(q);

    deQueue(q);
    printf("\n%d  %d\n", q->front, q->rear);
    printQueue(q);
    deQueue(q);
    printf("\n%d  %d\n", q->front, q->rear);
    printQueue(q);
    deQueue(q);
    printf("\n%d  %d\n", q->front, q->rear);
    printQueue(q);
    deQueue(q);
    printf("\n%d  %d\n", q->front, q->rear);
    printQueue(q);
    deQueue(q);
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
