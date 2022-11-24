/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \linkedList.c                                                                              *
* Project: 13_LinkedList                                                                           *
* Created Date: Wednesday Nov 23rd 2022, 6:44:22 pm                                                *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 24/11/2022 09:07:45                                                               *
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

// print
bool printLinkedL(linkedList * l){
    node * curNode = l->front;
    printf("[");
    while(curNode){
        if(sizeof(elemNode) == sizeof(char)) printf("%c", curNode->elem);
        else if(sizeof(elemNode) <= sizeof(int)) printf("%d", curNode->elem);
        else printf("%f", curNode->elem);
        curNode = curNode->next;
        if(curNode) printf("->");
    }
    printf("]");
}

// operation
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
    if(!l->size){                                   /* insert in an empty linked list */
        newNode = getNode(elem, l->front);
        l->front = l->rear = newNode;
        l->position = 0;
    }
    else if(!l->prePtr){                            /* insert at the head */
        newNode = getNode(elem, l->front);
        l->front = newNode;
    }
    else{                                           /* insert in the body */
        newNode = getNode(elem, l->curPtr);
        insertAfterNode(l->prePtr, newNode);
    }

    l->size++;
    l->curPtr = newNode;
}

void insertAfterLinkedL(linkedList * l, elemNode elem){
    node * newNode;
    if(!l->size){                                   /* insert in an empty linked list */
        newNode = getNode(elem, l->front);
        l->front = l->rear = newNode;
        l->position = 0;
    }
    else if(l->curPtr == l->rear || !l->curPtr){    /* insert at the rear */
        newNode = getNode(elem, NULL);
        insertAfterNode(l->rear, newNode);
        l->prePtr = l->rear;
        l->rear = newNode;
        l->position = l->size;
    }
    else{                                           /* insert in the body */
        newNode = getNode(elem, l->curPtr->next);
        insertAfterNode(l->curPtr, newNode);
        l->prePtr = l->curPtr;
        l->position++;
    }
    l->size++;
    l->curPtr = newNode;
}

void deleteAtLinkedL(linkedList * l){
    node * oldNode;
    if(!l->curPtr){                                     /* if the current position is NULL, print error information */
        printf("Current position cannot be deleted!\n");
        return;
    }
    if(!l->prePtr){                                     /* delete the front node */
        oldNode = l->front;
        l->front = l->front->next;
    }
    else oldNode = deleteAfterNode(l->prePtr);          /* delete the node in the body */
    if(oldNode == l->rear) l->rear = l->prePtr;         /* if the rear node is deleted, modify the rear node */
    l->curPtr = oldNode->next;
    freeNode(oldNode);
    l->size--;
}

void deleteAfterLinkedL(linkedList * l){
    node * oldNode;
    if(!l->curPtr || l->curPtr == l->rear){             /* if the current position is NULL or the rear node, print error information */
        printf("Current position cannot be deleted!\n");
        return;
    }
    oldNode = deleteAfterNode(l->curPtr);
    if(oldNode == l->rear) l->rear = l->curPtr;
    freeNode(oldNode);
    l->size--;
}

elemNode getNodeDataLinkedL(linkedList * l){
    if(!l->size || !l->curPtr){                         /* if the list is empty or the position get to rear's next */
        printf("Current node does not exist!\n");
        exit(1);
    }
    return l->curPtr->elem;
}

void setNodeDataLinkedL(linkedList * l, elemNode elem){
    if(!l->size || !l->curPtr){                         /* if the list is empty or the position get to rear's next */
        printf("Current node does not exist!\n");
        exit(1);
    }
    l->curPtr->elem = elem;
}

void clearLinkedL(linkedList * l){
    node * curNode = l->front, * nextNode;
    while(curNode){
        nextNode = curNode->next;
        freeNode(curNode);
        curNode = nextNode;
    }
    l->front = l->rear = l->prePtr = l->curPtr = NULL;
    l->size = 0;
    l->position = -1;
}
