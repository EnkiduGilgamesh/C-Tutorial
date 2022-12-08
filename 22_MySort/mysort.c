/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \mysort.c                                                                                  *
* Project: 22_MySort                                                                               *
* Created Date: Thursday Dec 8th 2022, 8:26:56 am                                                  *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 8/12/2022 09:51:25                                                                *
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
#include "mysort.h"

bool testSortRes(sortType * A, const int sortLen){
    for(int i = 1; i < sortLen; i++){
        if(A[i] < A[i - 1]) return FALSE;
    }
    return TRUE;
}

// Insert Sort
void directInsertSort(sortType * A, const int sortLen){
    int i, j;
    sortType temp;
    for(i = 0; i < sortLen; i++){
        temp = A[i];
        for(j = i; j > 0 && temp < A[j - 1]; j--)
            A[j] = A[j - 1];
        A[j] = temp;
    }
}

void binaryInsertSort(sortType * A, const int sortLen){
    int i, L, R, flag;
    sortType temp;
    for(i = 0; i < sortLen; i++){
        temp = A[i];
        L = 0, R = i - 1;
        while(L <= R){
            flag = (L + R) / 2;
            if(temp < A[flag]) R = flag - 1;
            else L = flag + 1;
        }
        /* now the L is equal to R */
        for(R = i; R > L; R--) A[R] = A[R - 1];
        A[L] = temp;
    }
}

void shellInsertSort(sortType * A, const int sortLen, const int initIncre){
    int i, j, incre;
    sortType temp;
    for(incre = initIncre; incre > 0; incre >>= 1){
        /* evey time the increase will be halved */
        for(i = incre; i < sortLen; i++){
            /* the positions before incre are all not meaningful, 
               since there are no elements can be compared with them */
            temp = A[i];
            j = i;
            while(j >= incre && temp < A[j - incre]){
                /* sort the elements with every incre */
                A[j] = A[j - incre];
                j -= incre;
            }
            A[j] = temp;
        }
    }
}

// Select Sort
void directSelectSort(sortType * A, const int sortLen){
    return;
}

void treeSelectSort(sortType * A, const int sortLen){
    return;
}

// Exchange Sort
void bubbleSort(sortType * A, const int sortLen){
    return;
}

void quickSort(sortType * A, const int sortLen){
    return;
}

// Distribution Sort
void radixSort(sortType * A, const int sortLen){
    return;
}

//Merge Sort
void mergeSort(sortType * A, const int sortLen){
    return;
}
