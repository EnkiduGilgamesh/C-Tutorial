/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \pQueue.c                                                                                  *
* Project: 12_Queue                                                                                *
* Created Date: Thursday Nov 10th 2022, 8:41:19 am                                                 *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 23/11/2022 03:52:51                                                               *
* Modified By: Wenren Muyan                                                                        *
* --------------------------------------------------------------------------------                 *
* Copyright (c) 2022 - future Wenren Muyan                                                         *
* --------------------------------------------------------------------------------                 *
* HISTORY:                                                                                         *
* Date				By				Comments                                                       *
* --------------------------------------------------------------------------------                 *
***************************************************************************************************/


// TODO: test
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "pQueue.h"


// initialize
void getPQueue(pQueue * pq){
    pq->elems = (elemPQueue *)malloc(sizeof(elemPQueue) * (pq->size));
    if(pq->elems == NULL) printf("Memory Allocation Error!\n");
}

void initPQueue(pQueue * pq, const int size){                // the size here is the number of elemrnts
    if(size <= 0) printf("Invalid Stack Size!\n");
    else{
        pq->size = size;
        pq->front = 0;
        getPQueue(pq);
    }
}

void freePQueue(pQueue * pq){
    free(pq->elems);
}

// print
bool printPQueue(const pQueue * pq){
    if(sizeof(pq->elems[pq->front]) <= sizeof(elemPQueue)){
        printf("The queue is not a priority queue!");
        return FALSE;
    }
    else if(isEmptyQueue(pq)){
        printf("Empty Queue!\n");
        return FALSE;
    }
    else{
        printf("[");
        for(int i = pq->front; (i + pq->size) % pq->size != pq->rear; i++){
            int cur = (i + pq->size) % pq->size;
            printf("(");
            if(sizeof(elemQueue) == sizeof(char)) printf("%c", pq->elems[cur]->elem);
            else if(sizeof(elemQueue) <= sizeof(int)) printf("%d", pq->elems[cur]->elem);
            else printf("%f", pq->elems[cur]);
            printf(", %d)", pq->elems[cur]->priority);

            if(i < pq->front) printf("->");
        }
        printf("]");

        return TRUE;
    }
}

// functions
void makeEmptyPQueue(pQueue * pq){
    pq->front = 0;
}

bool isEmptyPQuue(const pQueue * pq){
    if(pq->front == 0) return TRUE;
    else return FALSE;
}

bool isFullPQueue(const pQueue * pq){
    if(pq->front + 1 == pq->size) return TRUE;
    else return FALSE;
}

int lenPQueue(const pQueue * pq){
    return pq->front + 1;
}

bool enPQueue(pQueue * pq, const elemPQueue * elem){
    /*  */
    if(isFullPQueue(pq)){
        printf("Overflow!\n");
        return FALSE;
    }
    else{
        int i = 0;
        elemPQueue * t;/*= (elemPQueue *)malloc(sizeof(elemPQueue));*/
        for(i = 0; i < pq->front; i++){
            if(elem->priority > pq->elems[i]->priority) i++;
            else{
                t = pq->elems[i];
                pq->elems[i] = elem;
                break;
            }
        }
        for(++i; i < pq->front; i++){
            elemPQueue * temp;
            temp = pq->elems[i];
            pq->elems[i] = t;
            t = temp;
        }
        pq->elems[i] = t;

        return TRUE;
    }
}

bool dePQueue(pQueue * pq){
    if(isEmptyPQuue(pq)){
        printf("Empty Stack!\n");
        return FALSE;
    }
    else{
        pq->front--;
        return TRUE;
    }
}

elemPQueue getFrontPQueue(const pQueue * pq){
    if(isEmptyPQuue(pq)){
        printf("Empty Stack!\n");
        exit(1);
    }
    else return pq->elems[q->front];
}
