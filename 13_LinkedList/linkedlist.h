/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \linkedList.h                                                                              *
* Project: 13_linkedList                                                                           *
* Created Date: Wednesday Nov 23rd 2022, 5:54:23 pm                                                *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 23/11/2022 06:53:38                                                               *
* Modified By: Wenren Muyan                                                                        *
* --------------------------------------------------------------------------------                 *
* Copyright (c) 2022 - future Wenren Muyan                                                         *
* --------------------------------------------------------------------------------                 *
* HISTORY:                                                                                         *
* Date				By				Comments                                                       *
* --------------------------------------------------------------------------------                 *
***************************************************************************************************/


#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

#include "node.h"

typedef struct{
    node * front, * rear;
    node * prePtr, * curPtr;
    int size;
    int position;
} linkedList;

// initialization
void initLinkedL(linkedList * l);

// function
bool isEmptyLinkedL(linkedList * l);
int nextNodeLinkedL(linkedList * l);
int setPosLinkedL(linkedList * l, int pos);
void insertAtLinkedL(linkedList * l, elemNode elem);
void deleteAtLinkedL(linkedList * l);
void deleteAfterLinkedL(linkedList * l);
elemNode getNodeDataLinkedL(linkedList * l);
void setNodeDataLinkedL(linkedList * l, elemNode elem);
void clearLinkedL(linkedList * l);


#endif
