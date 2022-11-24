/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \node.h                                                                                    *
* Project: 13_LinkedList                                                                           *
* Created Date: Wednesday Nov 23rd 2022, 3:57:28 pm                                                *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 24/11/2022 08:11:6                                                                *
* Modified By: Wenren Muyan                                                                        *
* --------------------------------------------------------------------------------                 *
* Copyright (c) 2022 - future Wenren Muyan                                                         *
* --------------------------------------------------------------------------------                 *
* HISTORY:                                                                                         *
* Date				By				Comments                                                       *
* --------------------------------------------------------------------------------                 *
***************************************************************************************************/


#ifndef __NODE_H
#define __NODE_H

typedef enum {FALSE, TRUE} bool;
typedef int elemNode;

typedef struct Node{
    struct Node * next;
    int elem;
} node;

// initialization
void initNode(node * n, elemNode elem, node * next);
node * getNode(elemNode elem, node * n);
node * deleteAfterNode(node * n);                                  // delete the node after and return the deleted node 
void freeNode(node * n);

// print

// function
void insertAfterNode(node * n, node * insertNode);                 // insert the 'insertNode' node after the 'n' node 


#endif
