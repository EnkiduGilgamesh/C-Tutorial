/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \matrix.h                                                                                  *
* Project: 30_Matrix                                                                               *
* Created Date: Thursday Nov 17th 2022, 9:25:29 am                                                 *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 17/11/2022 06:49:31                                                               *
* Modified By: Wenren Muyan                                                                        *
* --------------------------------------------------------------------------------                 *
* Copyright (c) 2022 - future Wenren Muyan                                                         *
* --------------------------------------------------------------------------------                 *
* HISTORY:                                                                                         *
* Date				By				Comments                                                       *
* --------------------------------------------------------------------------------                 *
***************************************************************************************************/


#ifndef __MATRIX_H
#define __MATRIX_H

#include <stdio.h>

typedef enum {FALSE, TRUE} bool;
typedef int elemMatrix;

typedef struct{
    int width;
    int length;
    elemMatrix ** elems;
} matrix;

// initialize
void getMatrix(matrix * m);
void initMatrix(matrix * m, const int width, const int length);             // a m*n matrix; m is the width, and the n is the length.
void freeMatrix(matrix * m);

// scan
void scanFloatMatrix(matrix * m);
void scanIntMatrix(matrix * m);
void scanMatrix(matrix * m);

// print
void printMatrix(const matrix * m);

// function
matrix * transposMatrix(const matrix * m);

#endif
