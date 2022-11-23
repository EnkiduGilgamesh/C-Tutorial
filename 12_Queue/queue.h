/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \queue.h                                                                                   *
* Project: 12_Queue                                                                                *
* Created Date: Saturday Nov 5th 2022, 2:54:31 pm                                                  *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 23/11/2022 03:02:53                                                               *
* Modified By: Wenren Muyan                                                                        *
* --------------------------------------------------------------------------------                 *
* Copyright (c) 2022 - future Wenren Muyan                                                         *
* --------------------------------------------------------------------------------                 *
* HISTORY:                                                                                         *
* Date				By				Comments                                                       *
* --------------------------------------------------------------------------------                 *
***************************************************************************************************/

#ifndef __QUEUE_H
#define __QUEUE_H

typedef enum {FALSE, TRUE} bool;
typedef int elemQueue;

typedef struct{
    int rear, front;
    elemQueue * elems;
    int size;
} queue;

// initialize
void getQueue(queue * q);
void initQueue(queue * q, const int size);                  // the size here is the number of elements, not the space it needs
void freeQueue(queue * q);

// print

bool printQueue(const queue * q);

// functions
void makeEmptyQueue(queue * q);
bool isEmptyQueue(const queue * q);
bool isFullQueue(const queue * q);
int lenQueue(const queue * q);
bool enQueue(queue * q, const elemQueue elem);              // the elem enqueue
bool deQueue(queue * q);                                    // the front element dequeue
elemQueue getFrontQueue(const queue * q);                   // return the front element

#endif