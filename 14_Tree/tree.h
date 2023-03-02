/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \tree.h                                                                                    *
* Project: 14_Tree                                                                                 *
* Created Date: Thursday Mar 2nd 2023, 9:00:53 pm                                                  *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 2/03/2023 09:18:58                                                                *
* Modified By: Wenren Muyan                                                                        *
* --------------------------------------------------------------------------------                 *
* Copyright (c) 2023 - future Wenren Muyan                                                         *
* --------------------------------------------------------------------------------                 *
* HISTORY:                                                                                         *
* Date				By				Comments                                                       *
* --------------------------------------------------------------------------------                 *
***************************************************************************************************/


#ifndef __TREE_H
#define __TREE_H

typedef char elem;
typedef enum {FALSE, TRUE} bool;

typedef struct binaryTreeNode{
    elem data;
    struct binaryTreeNode * lChild, * rChild;
}bTreeNode;

typedef struct{
    bTreeNode * root;
}bTree;

void initBTreeNode(bTreeNode * n, elem d, bTreeNode * l, bTreeNode * r);
bTreeNode * createBTreeNode(elem data, bTreeNode * l, bTreeNode * r);

bTree * initBTree();
bool isEmptyBTree(bTree * bt);
bTreeNode * makeTree(bTree * bt, elem data, bTreeNode * l, bTreeNode * r);

void preOrderBTree(bTreeNode * n);
void inOrderBTree(bTreeNode * n);
void postOrderBTree(bTreeNode * n);

#endif