/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \main.c                                                                                    *
* Project: 14_Tree                                                                                 *
* Created Date: Thursday Mar 2nd 2023, 9:00:53 pm                                                  *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 2/03/2023 09:27:26                                                                *
* Modified By: Wenren Muyan                                                                        *
* --------------------------------------------------------------------------------                 *
* Copyright (c) 2023 - future Wenren Muyan                                                         *
* --------------------------------------------------------------------------------                 *
* HISTORY:                                                                                         *
* Date				By				Comments                                                       *
* --------------------------------------------------------------------------------                 *
***************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

// typedef char elem;

int main(){
    bTree * t = initBTree();
    bTreeNode * a, * b, * c, * d, * e, * f, * g;

    d = makeTree(t, 'D', NULL, NULL);
    e = makeTree(t, 'E', NULL, NULL);
    f = makeTree(t, 'F', NULL, NULL);
    b = makeTree(t, 'B', d, e);
    c = makeTree(t, 'C', f, NULL);
    a = makeTree(t, 'A', b, c);

    g = createBTreeNode('G', a, b);

    // printf("%c\n", g->data);

    preOrderBTree(a);
    printf("\n");
    
    inOrderBTree(a);
    printf("\n");

    postOrderBTree(a);
    printf("\n");

    system("pause");

    return 0;
}