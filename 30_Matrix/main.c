/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \main.c                                                                                    *
* Project: 30_Matrix                                                                               *
* Created Date: Thursday Nov 17th 2022, 9:26:09 am                                                 *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 17/11/2022 06:51:12                                                               *
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
#include "matrix.h"

#define W 2
#define L 3

int main(){
    matrix * m = (matrix *)malloc(sizeof(matrix));

    initMatrix(m, W, L);
    
    scanIntMatrix(m);
    printMatrix(m);
    printf("\n");

    matrix * t_m = transposMatrix(m);
    printMatrix(t_m);

    system("pause");
    
    return 0;
}
