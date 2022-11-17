/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \matrix.c                                                                                  *
* Project: 30_Matrix                                                                               *
* Created Date: Thursday Nov 17th 2022, 9:41:47 am                                                 *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 17/11/2022 06:56:34                                                               *
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

// initialize
void getMatrix(matrix * m){
    m->elems = (elemMatrix **)malloc(m->width * sizeof(elemMatrix *));
    for(int i = 0; i < m->width; i++)
        m->elems[i] = (elemMatrix *)malloc(m->length * sizeof(elemMatrix));
}

void initMatrix(matrix * m, const int width, const int length){
    if(width <= 0 || length <= 0) printf("Invalid Stack Size!\n");
    else{
        m->width = width;
        m->length = length;
        getMatrix(m);
    }
}

void freeMatrix(matrix * m){
    for(int i = 0; i < m->width; i++)
        free(m->elems[i]);

    free(m);
}

void scanFloatMatrix(matrix * m){
    for(int i = 0; i < m->width; i++){
        for(int j = 0; j < m->length; j++){
            scanf("%f", &m->elems[i][j]);
        }
    }
}

void scanIntMatrix(matrix * m){
    for(int i = 0; i < m->width; i++){
        for(int j = 0; j < m->length; j++){
            scanf("%d", &m->elems[i][j]);
        }
    }
}

void scanMatrix(matrix * m){
    switch(sizeof(elemMatrix)){
        case 4:
            scanIntMatrix(m);
            break;
        case 8:
            scanFloatMatrix(m);
            break;
        default:
            break;
    }
}

// print
void printMatrix(const matrix * m){
    printf("[");
    for(int i = 0; i < m->width; i++){
        printf("[");
        for(int j = 0; j < m->length; j++){
            if(sizeof(elemMatrix) <= sizeof(int))
                printf("%d", m->elems[i][j]);
            else printf("%f", m->elems[i][j]);
            if(j != m->length - 1) printf(",");
        }
        printf("]");
        if(i != m->width - 1) printf(",\n ");
    }
    printf("]");
}

// function
matrix * transposMatrix(const matrix * m){
    matrix * t_m = (matrix *)malloc(sizeof(matrix));
    initMatrix(t_m, m->length, m->width);

    for(int i = 0; i < m->width; i++)
        for(int j = 0; j < m->length; j++)
            t_m->elems[j][i] = m->elems[i][j];

    return t_m;
}
