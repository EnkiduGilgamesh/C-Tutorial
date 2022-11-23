/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \pQueue.h                                                                                  *
* Project: 12_Queue                                                                                *
* Created Date: Thursday Nov 10th 2022, 8:43:18 am                                                 *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 23/11/2022 03:52:52                                                               *
* Modified By: Wenren Muyan                                                                        *
* --------------------------------------------------------------------------------                 *
* Copyright (c) 2022 - future Wenren Muyan                                                         *
* --------------------------------------------------------------------------------                 *
* HISTORY:                                                                                         *
* Date				By				Comments                                                       *
* --------------------------------------------------------------------------------                 *
***************************************************************************************************/

#ifndef __PQUEUE_H
#define __PQUEUE_H

#include "queue.h"

// typedef enum {FALSE, TRUE} bool;
typedef struct{
    int priority;
    elemQueue elem;
} elemPQueue;

typedef struct{
    int front;
    elemPQueue ** elems;
    int size;
} pQueue;

// initialize
void getPQueue(pQueue * pq);
void initPQueue(pQueue * pq, const int size);                    // the size here is the number of elements, not the space it needs
void freePQueue(pQueue * pq);

// print

bool printPQueue(const pQueue * pq);

// functions
void makeEmptyPQueue(pQueue * pq);
bool isEmptyPQuue(const pQueue * pq);
bool isFullPQueue(const pQueue * pq);
int lenPQueue(const pQueue * pq);
bool enPQueue(pQueue * pq, const elemPQueue * elem);             // the elem enqueue
bool dePQueue(pQueue * pq);                                      // the front element dequeue
elemPQueue getFrontPQueue(const pQueue * pq);                    // return the front element

#endif
