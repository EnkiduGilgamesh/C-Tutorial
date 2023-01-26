/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \mysort.c                                                                                  *
* Project: 22_MySort                                                                               *
* Created Date: Thursday Dec 8th 2022, 8:26:56 am                                                  *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 26/01/2023 09:11:22                                                               *
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
    int i, L, R, mid;
    sortType temp;
    for(i = 0; i < sortLen; i++){
        temp = A[i];
        L = 0, R = i - 1;
        while(L <= R){
            mid = (L + R) / 2;
            if(temp < A[mid]) R = mid - 1;
            else L = mid + 1;
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
    int i, j, k;
    sortType temp;
    for(i = 0; i < sortLen - 1; i++){
        k = i;
        for(j = i + 1; j < sortLen; j++){
            if(A[j] < A[k]) k = j;
        }
        if(i != k){
            temp = A[k];
            A[k] = A[i];
            A[i] = temp;
        }
    }
}

void treeSelectSort(sortType * A, const int sortLen){
    return;
}

// Exchange Sort
void bubbleSort(sortType * A, const int sortLen){
    int i, j;
    bool flag;
    sortType temp;

    for(i = sortLen - 1, flag = 1; i > 0 && flag; i--){
        /* If the last time there is no bubble, the flag's value is FALSE, 
           which means the target has been sorted */
        flag = FALSE;
        for(j = 0; j < i; j++){
            /* move the maximum element to the right end */
            if(A[j + 1] < A[j]){
                flag = TRUE;
                temp = A[j + 1];
                A[j + 1] = A[j];
                A[j] = temp;
            }
        }
    }
}

void quickSort(sortType * A, const int sortLen){
    return;
}

// Distribution Sort
void radixSort(sortType * A, const int sortLen){
    return;
}

//Merge Sort
void mergeSortRecursive(sortType * l, sortType * reg, const int start, const int end){
    if(start >= end) return;

    int len = end - start;
    int mid = (len >> 1) + start;
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;

    mergeSortRecursive(l, reg, start1, end1);
    mergeSortRecursive(l, reg, start2, end2);

    int k = start;
    while(start1 <= end1 && start2 <= end2){
        reg[k++] = l[start1] < l[start2] ? l[start1++] : l[start2++];
    }
    while(start1 <= end1){
        reg[k++] = l[start1++];
    }
    while(start2 <= end2){
        reg[k++] = l[start2++];
    }

    for(int i = start; i <= end; i++){
        l[i] = reg[i];
    }
}

void mergeSort(sortType * A, const int sortLen){
    sortType * reg = (sortType *)malloc(sizeof(sortType) * sortLen);
    mergeSortRecursive(A, reg, 0, sortLen - 1);
}

// Get some statistical data
double getAverage(sortType * A, const int len){
    int i;
    double sum = 0;
    for(i = 0; i < len; i++){
        sum += A[i];
    }

    return sum / len;
}

double getMedian(sortType * A, const int len){
    if(!testSortRes(A, len)) directInsertSort(A, len);

    if(len % 2) return (double)A[(len / 2)];
    else return ((double)A[len / 2] + (double)A[len / 2 - 1]) / 2;
}
