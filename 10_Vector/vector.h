/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \vector.h                                                                                  *
* Project: 10_Vector                                                                               *
* Created Date: Tuesday Oct 11th 2022, 9:35:55 am                                                  *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 12/10/2022 01:56:28                                                               *
* Modified By: Wenren Muyan                                                                        *
* --------------------------------------------------------------------------------                 *
* Copyright (c) 2022 - future Wenren Muyan                                                         *
* --------------------------------------------------------------------------------                 *
* HISTORY:                                                                                         *
* Date				By				Comments                                                       *
* --------------------------------------------------------------------------------                 *
***************************************************************************************************/

#ifndef _VECTOR_H
#define _VECTOR_H

typedef enum {FALSE, TRUE} bool;

typedef int elem;                       // set Elem as int defaultly

typedef struct{
    elem * elems;
    int size;
    int len;
} vector;

// initialize and free
void getVector(vector * v);                         // ask for storage
void initVector(vector * v, int size);              // initialize a vector
void freeVector(vector * v);                        // free up a vector

// assignment
vector * initFromArrary(elem * l, int listLen, int maxSize);
vector * initFromVector(vector * v, int maxSize);

// print
bool printVector(vector * v);

// function
elem getVectorNode(vector * v, int i);              // return the value of the vector's position i
int findVectorNode(vector * v, elem x);             // return the number of elements in vector which are the same with x
bool insertVectorNode(vector * v, elem x, int i);   // insert x at the position i of a vector, if success, return TRUE; otherwise return FALSE
bool removeVectorNode(vector * v, int i);           // remove the element at the position of a vector, if success, return TRUE; otherwise return FALSE

void reserveVector(vector * v);                     // reserve the elements in vector

#endif
