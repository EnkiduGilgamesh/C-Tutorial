/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \pQueue.c                                                                                  *
* Project: 12_Queue                                                                                *
* Created Date: Thursday Nov 10th 2022, 8:41:19 am                                                 *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 10/11/2022 09:43:29                                                               *
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
#include "pQueue.h"

// initialize
void getPQueue(pQueue * q){
    q->elems = (elemPQueue *)malloc(sizeof(elemPQueue) * (q->size));
    if(q->elems == NULL) printf("Memory Allocation Error!\n");
}

void initPQueue(pQueue * q, const int size){                // the size here is the number of elemrnts
    if(size <= 0) printf("Invalid Stack Size!\n");
    else{
        q->size = size + 1;                                 // the q's size is the space it needs
        q->num = 0;
        getPQueue(q);
    }
}

void freePQueue(pQueue * q){
    free(q->elems);
}

// print
bool printPQueue(const pQueue * q){
    return TRUE;
}

// functions
void makeEmptyPQueue(pQueue * q){
    q->num = 0;
}

bool isEmptyPQuue(const pQueue * q){
    if(q->num == 0) return TRUE;
    else return FALSE;
}

bool isFullPQueue(const pQueue * q){
    if(q->num == q->size - 1) return TRUE;
    else return FALSE;
}

int lenPQueue(const pQueue * q){
    return q->num;
}


