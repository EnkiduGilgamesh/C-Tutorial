/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \mysort.h                                                                                  *
* Project: 22_MySort                                                                               *
* Created Date: Thursday Dec 1st 2022, 9:11:10 am                                                  *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 1/12/2022 09:45:13                                                                *
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

// Insert Sort
void directInsertSort(sortType * A, const int sortLen);
void binaryInsertSort(sortType * A, const int sortLen);
void shellInsertSort(sortType * A, const int sortLen);

// Select Sort
void directSelectSort(sortType * A, const int sortLen);
void treeSelectSort(sortType * A, const int sortLen);

// Exchange Sort
void bubbleSort(sortType * A, const int sortLen);
void quickSort(sortType * A, const int sortLen);

// Distribution Sort
void radixSort(sortType * A, const int sortLen);

//Merge Sort
void mergeSort(sortType * A, const int sortLen);

#endif
