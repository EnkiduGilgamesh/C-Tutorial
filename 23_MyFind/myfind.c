/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \myfind.c                                                                                  *
* Project: 23_MyFind                                                                               *
* Created Date: Thursday Jan 26th 2023, 9:07:01 pm                                                 *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 26/01/2023 09:22:33                                                               *
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
#include "myfind.h"

int seqFind(findType * A, findType key, int findLen){
    int i;

    for(i = 0; i < findLen; i++)
        if(A[i] == key) return i;

    return -1;
}

int binaryFind(findType * A, findType key, int findLen){
    int l, r, mid;
    findType temp;

    l = 0, r = findLen - 1;

    while(l <= r){
        mid = (l + r) / 2;
        if(key == A[mid]) return mid;
        else if(key > A[mid]) l = mid + 1;
        else r = mid - 1;
    }

    return -1;
}