/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \main.c                                                                                    *
* Project: 23_MyFind                                                                               *
* Created Date: Thursday Jan 26th 2023, 9:17:12 pm                                                 *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 26/01/2023 09:23:6                                                                *
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

#define stdLen 10

int main(){
    int A[stdLen] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int key = 9;

    int ans;

    ans = binaryFind(A, key, stdLen);
    printf("The answer is %d\n", ans);

    ans = seqFind(A, key, stdLen);
    printf("The answer is %d\n", ans);

    return 0;
}