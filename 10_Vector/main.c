/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \main.c                                                                                    *
* Project: 10_Vector                                                                               *
* Created Date: Tuesday Oct 11th 2022, 6:55:05 pm                                                  *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 13/10/2022 09:04:40                                                               *
* Modified By: Wenren Muyan                                                                        *
* --------------------------------------------------------------------------------                 *
* Copyright (c) 2022 - future Wenren Muyan                                                         *
* --------------------------------------------------------------------------------                 *
* HISTORY:                                                                                         *
* Date				By				Comments                                                       *
* --------------------------------------------------------------------------------                 *
***************************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

int main(){
    int list[8] = {1, 2, 3, 4, 5, 6, 7, 8};

    //vector * v1 = initFromArrary(list, 8, 10);

    vector * v = (vector *)malloc(sizeof(vector));

    initVector(v, 10);

    int res = josephus(v, 8, 1, 3);

    freeVector(v);
    printf("%d", sizeof(v));
    printf("\n");
    printf("%d", res);

    /*for(int i = 0; i < 5; i++){
        insertVectorNode(v, i, -1);
    }

    vector * v2 = initFromVector(v, 8);

    printVector(v1);
    printf("\n");
    printVector(v2);
    printf("\n");
    reserveVector(v1);
    printVector(v1);*/
    
    system("pause");
    return 0;
}
