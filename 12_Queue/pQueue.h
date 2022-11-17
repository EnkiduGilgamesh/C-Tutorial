/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \pQueue.h                                                                                  *
* Project: 12_Queue                                                                                *
* Created Date: Thursday Nov 10th 2022, 8:43:18 am                                                 *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 10/11/2022 09:35:56                                                               *
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

typedef enum {FALSE, TRUE} bool;
typedef int elemPQueue;

typedef struct{
    int num;
    elemPQueue * elems;
    int size;
} pQueue;

// initialize
void getPQueue(pQueue * q);
void initPQueue(pQueue * q, const int size);                    // the size here is the number of elements, not the space it needs
void freePQueue(pQueue * q);

// print

bool printPQueue(const pQueue * q);

// functions
void makeEmptyPQueue(pQueue * q);
bool isEmptyPQuue(const pQueue * q);
bool isFullPQueue(const pQueue * q);
int lenPQueue(const pQueue * q);
bool enPQueue(pQueue * q, const elemPQueue elem);               // the elem enqueue
bool dePQueue(pQueue * q);                                      // the front element dequeue
elemPQueue getFrontPQueue(const pQueue * q);                    // return the front element

#endif
