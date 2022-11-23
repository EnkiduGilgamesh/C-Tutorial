/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \linkedList.c                                                                              *
* Project: 13_LinkedList                                                                           *
* Created Date: Wednesday Nov 23rd 2022, 6:44:22 pm                                                *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 23/11/2022 07:09:7                                                                *
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
#include "linkedList.h"


// initialization
void initLinkedL(linkedList * l){
    l->front = NULL;
    l->rear = NULL;
    l->prePtr = NULL;
    l->curPtr = NULL;
    l->size = 0;
    l->position = -1;
}

// function
bool isEmptyLinkedL(linkedList * l){
    return l->size ? FALSE : TRUE;
}

node * nextNodeLinkedL(linkedList * l){
    if(l->position >= 0 && l->position <= l->size){
        l->position++;
        l->prePtr=l->curPtr;
        l->curPtr = l->curPtr->next;
        return l->curPtr;
    }
    else{
        /* if the current node doesn't exist, return the rear's next node(NULL) */
        l->position = l->size;
        return NULL;
    }  
}

node * setPosLinkedL(linkedList * l, int pos){
    if(!l->size){
        printf("Empty Linked List!");
        return NULL;
    }
    if(pos < 0 || pos > l->size - 1){
        printf("Position Error!");
        return NULL;
    }
    l->curPtr = l->front;
    l->prePtr = NULL;
    l->position = 0;

    for(int k = 0; k < pos; k++){
        l->position++;
        l->prePtr = l->curPtr;
        l->curPtr = l->curPtr->next;
    }

    return l->curPtr;
}

void insertAtLinkedL(linkedList * l, elemNode elem){
    node * newNode;
}

void deleteAtLinkedL(linkedList * l);
void deleteAfterLinkedL(linkedList * l);
elemNode getNodeDataLinkedL(linkedList * l);
void setNodeDataLinkedL(linkedList * l, elemNode elem);
void clearLinkedL(linkedList * l);
