/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \stack.h                                                                                   *
* Project: 11_Stack                                                                                *
* Created Date: Thursday Oct 13th 2022, 9:37:19 am                                                 *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 13/10/2022 08:46:20                                                               *
* Modified By: Wenren Muyan                                                                        *
* --------------------------------------------------------------------------------                 *
* Copyright (c) 2022 - future Wenren Muyan                                                         *
* --------------------------------------------------------------------------------                 *
* HISTORY:                                                                                         *
* Date				By				Comments                                                       *
* --------------------------------------------------------------------------------                 *
***************************************************************************************************/

#ifndef __STACK_H
#define __STACK_H

#define nValue -2147483648

typedef enum {FALSE, TRUE} bool;
typedef int elem;                                   // set Elem as int defaultly

typedef struct{
    elem * elems;
    int top;
    int size;
} stack;

// initialize
void getStack(stack * s);
void initStack(stack * s, int size);
void freeStack(stack * s);

// assignment
stack * initFromArray(elem * s, int listLen, int maxSize);
stack * initFromStack(stack * s, int maxSize);

// print
bool printStack(stack * s);

// functions
bool pushStack(stack * s, elem x);                  // push the stack
bool popStack(stack *s);                            // pop the stack
elem getPopStack(stack * s);                        // return the pop element of the stack
int lenStack(stack * s);                            // return the length of the stack
void makeEmptyStack(stack * s);
bool isEmptyStack(stack * s);
bool isFullStack(stack * s);

#endif
