/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \tree.c                                                                                    *
* Project: 14_Tree                                                                                 *
* Created Date: Thursday Mar 2nd 2023, 9:00:53 pm                                                  *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 2/03/2023 09:24:13                                                                *
* Modified By: Wenren Muyan                                                                        *
* --------------------------------------------------------------------------------                 *
* Copyright (c) 2023 - future Wenren Muyan                                                         *
* --------------------------------------------------------------------------------                 *
* HISTORY:                                                                                         *
* Date				By				Comments                                                       *
* --------------------------------------------------------------------------------                 *
***************************************************************************************************/


#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

void initBTreeNode(bTreeNode * n, elem d, bTreeNode * l, bTreeNode * r){
    n->lChild = l;
    n->rChild = r;
    n->data = d;
}

bTreeNode * createBTreeNode(elem data, bTreeNode * l, bTreeNode * r){
    bTreeNode * p = (bTreeNode *)malloc(sizeof(bTreeNode));
    if(!p)
        printf("Memory allocation failed!\n");
    else
        initBTreeNode(p, data, l, r);

    return p;
}

bTree * initBTree(){
    bTree * bt = (bTree *)malloc(sizeof(bTree));
    if(!bt)
        printf("Memory allocation failed!\n");
    else
        bt->root = NULL;
    return bt;
}

bool isEmptyBTree(bTree * bt){
    return bt->root != NULL;
}

bTreeNode * makeTree(bTree * bt, elem data, bTreeNode * l, bTreeNode * r){
    bTreeNode * p;
    p = createBTreeNode(data, l, r);
    bt->root = p;

    return bt->root;
}

void preOrderBTree(bTreeNode * n){
    if(n){
        printf("%c", n->data);
        preOrderBTree(n->lChild);
        preOrderBTree(n->rChild);
    }
}

void inOrderBTree(bTreeNode * n){
    if(n){
        inOrderBTree(n->lChild);
        printf("%c", n->data);
        inOrderBTree(n->rChild);
    }
}

void postOrderBTree(bTreeNode * n){
    if(n){
        postOrderBTree(n->lChild);
        postOrderBTree(n->rChild);
        printf("%c", n->data);      
    }
}
