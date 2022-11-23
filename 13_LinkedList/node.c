/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \node.c                                                                                    *
* Project: 13_LinkedList                                                                           *
* Created Date: Wednesday Nov 23rd 2022, 4:10:57 pm                                                *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 23/11/2022 05:54:14                                                               *
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
#include "node.h"


// initialization
void initNode(node * n, elemNode elem, node * next){
    n->elem = elem;
    n->next = next;
}

node * getNode(elemNode elem, node * next){
    node * newNode;
    
    newNode = (node *)malloc(sizeof(node));
    if(newNode == NULL){
        printf("Memory allocation error!");
        exit(1);
    }
    else{
        initNode(newNode, elem, next);
        return newNode;
    }
}

node * deleteAfterNode(node * n){
    node * ptr = n->next;

    if(!ptr) return NULL;
    
    n->next = ptr->next;

    return ptr;
}

void freeNode(node * n){
    if(!ptr) return;

    free(ptr);
}

// function
void insertAfterNode(node * n, node * insertNode){
    insertNode->next = n->next;
    n->next = insertNode;
}
