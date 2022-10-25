/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \stack.h                                                                                   *
* Project: 11_Stack                                                                                *
* Created Date: Thursday Oct 13th 2022, 9:37:19 am                                                 *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 25/10/2022 09:15:42                                                               *
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
typedef int elemStack;                                   // set Elem as int defaultly

typedef struct{
    elemStack * elems;
    int top;
    int size;
} stack;

// initialize
void getStack(stack * s);
void initStack(stack * s, int size);
void freeStack(stack * s);

// assignment
stack * initFromArray(const elemStack * s, const int listLen, const int maxSize);       //TODO: const
stack * initFromStack(const stack * s, const int maxSize);

// print
bool printStack(const stack * s);

// functions
bool pushStack(stack * s, elemStack x);                  // push the stack
bool popStack(stack *s);                                 // pop the stack
elemStack getStackTop(const stack * s);                  // return the pop element of the stack
int lenStack(const stack * s);                           // return the length of the stack
void makeEmptyStack(stack * s);
bool isEmptyStack(const stack * s);
bool isFullStack(const stack * s);

// hanoi question
void hanoi(int n, char a, char b, char c);               // move all the elem from a to b 

#endif
