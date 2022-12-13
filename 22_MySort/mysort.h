/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \mysort.h                                                                                  *
* Project: 22_MySort                                                                               *
* Created Date: Thursday Dec 1st 2022, 9:11:10 am                                                  *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 13/12/2022 10:08:31                                                               *
* Modified By: Wenren Muyan                                                                        *
* --------------------------------------------------------------------------------                 *
* Copyright (c) 2022 - future Wenren Muyan                                                         *
* --------------------------------------------------------------------------------                 *
* HISTORY:                                                                                         *
* Date				By				Comments                                                       *
* --------------------------------------------------------------------------------                 *
***************************************************************************************************/


#ifndef __MYSORT_H
#define __MYSORT_H

typedef int sortType;
typedef enum{FALSE, TRUE} bool;

// All the algorithm will sort the target from the smallest to biggest
// TODO: write a function sort the array in a most efficient way

// test

bool testSortRes(sortType * A, const int sortLen);

// Insert Sort
void directInsertSort(sortType * A, const int sortLen);
void binaryInsertSort(sortType * A, const int sortLen);
void shellInsertSort(sortType * A, const int sortLen, const int initIncre);

// Select Sort
void directSelectSort(sortType * A, const int sortLen);
void treeSelectSort(sortType * A, const int sortLen);           // TODO: 

// Exchange Sort
void bubbleSort(sortType * A, const int sortLen);
void quickSort(sortType * A, const int sortLen);                // TODO: use stack to optimize the recursive

// Distribution Sort
void radixSort(sortType * A, const int sortLen);                // TODO: 
                                 
//Merge Sort
void mergeSortRecursive(sortType * l, sortType * reg, const int start, const int end);
void mergeSort(sortType * A, const int sortLen);

// Get some statistical data
double getAverage(sortType * A, const int len);
double getMedian(sortType * A, const int len);
sortType getMode(sortType * A, const int len);

#endif
