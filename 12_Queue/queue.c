/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \queue.c                                                                                   *
* Project: 12_Queue                                                                                *
* Created Date: Saturday Nov 5th 2022, 3:50:52 pm                                                  *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 25/11/2022 09:26:58                                                               *
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

// initialize
void getQueue(queue * q){
    q->elems = (elemQueue *)malloc(sizeof(elemQueue) * q->size);
    if(q->elems == NULL) printf("Memory Allocation Error!\n");
}

void initQueue(queue * q, const int size){              // the size here is the number of elemrnts
    if(size <= 0) printf("Invalid Stack Size!\n");
    else{
        q->size = size + 1;                             // the q's size is the space it needs
        q->front = q->rear = 0;
        getQueue(q);
    }
}

void freeQueue(queue * q){
    free(q->elems);
}

void makeEmptyQueue(queue * q){
    q->front = q->rear = 0;
}

bool isEmptyQueue(const queue * q){
    if(q->front == q->rear) return TRUE;
    else return FALSE;
}

bool isFullQueue(queue * q){
    if((q->rear + 1) % q->size == q->front) return TRUE;
    else return FALSE;
}

int lenQueue(const queue * q){
    return (q->rear - q->front + q->size) % q->size;
}

// print

bool printQueue(const queue * q){
    if(isEmptyQuue(q)){
        printf("Empty Queue!\n");
        return FALSE;
    }
    else{
        printf("[");
        for(int i = q->front; (i + q->size) % q->size != q->rear; i++){
            int cur = (i + q->size) % q->size;
            if(sizeof(elemQueue) == sizeof(char)) printf("%c", q->elems[cur]);
            else if(sizeof(elemQueue) <= sizeof(int)) printf("%d", q->elems[cur]);
            else printf("%f", q->elems[cur]);

            if((i + 1 + q->size) % q->size != q->rear) printf("->");
        }
        printf("]");

        return TRUE;
    }
}

// functions

bool enQueue(queue * q, elemQueue elem){
    if(isFullQueue(q)){
        printf("Overflow!\n");
        return FALSE;
    }
    else{
        q->elems[q->rear] = elem;
        q->rear = (q->rear + 1) % q->size;
        return TRUE;
    }
}

bool deQueue(queue * q){
    if(isEmptyQueue(q)){
        printf("Empty Stack!\n");
        return FALSE;
    }
    else{
        q->front = (q->front + 1) % q->size;
        return TRUE;
    }
}

elemQueue getFrontQueue(queue * q){
    if(isEmptyQueue(q)){
        printf("Empty Stack!\n");
        exit(1);
    }
    else return q->elems[q->front];
}
