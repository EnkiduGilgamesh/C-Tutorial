/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \vector.h                                                                                  *
* Project: 10_Vector                                                                               *
* Created Date: Tuesday Oct 11th 2022, 9:35:55 am                                                  *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 14/10/2022 10:50:1                                                                *
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

#define nValue -2147483648

typedef enum {FALSE, TRUE} bool;
typedef int elemVector;                       // set Elem as int defaultly

typedef struct{
    elemVector * elems;
    int size;
    int len;
} vector;

// initialize and free
void getVector(vector * v);                                             // ask for storage
void initVector(vector * v, int size);                                  // initialize a vector
void freeVector(vector * v);                                            // free up a vector

// assignment
vector * initFromArrary(const elemVector * l, const int listLen, const int maxSize);
vector * initFromVector(const vector * v, const int maxSize);

// print
bool printVector(const vector * v);

// function
elemVector getVectorNode(const vector * v, const int i);                // return the value of the vector's position i
int findVectorNode(const vector * v, const elemVector x);               // return the number of elements in vector which are the same with x
bool insertVectorNode(vector * v, const elemVector x, const int i);     // insert x at the position i of a vector, if success, return TRUE; otherwise return FALSE
bool removeVectorNode(vector * v, const int i);                         // remove the element at the position of a vector, if success, return TRUE; otherwise return FALSE
bool isEmptyVector(const vector * v);                                   // if v is empty return true
bool isFullVector(const vector * v);                                    // if v is full return true

void reserveVector(vector * v);                                         // reserve the elements in vector
void makeEmptyVector(vector * v);                                       // make a vector empty

// other functions
int josephus(vector * v, int num, int start, const int m);              // return the final position, and make the v's order as the out order

#endif
