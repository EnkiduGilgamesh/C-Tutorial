/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \stack.c                                                                                   *
* Project: 11_Stack                                                                                *
* Created Date: Thursday Oct 13th 2022, 9:37:24 am                                                 *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 13/10/2022 09:25:28                                                               *
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
#include "stack.h"

// initialize
void getStack(stack * s){
    s->elems = (elem *)malloc(sizeof(elem) * s->size);
    if(s->elems == NULL) printf("Memory Allocation Error!\n");
}

void initStack(stack * s, int size){
    if(size <= 0) printf("Invalid Stack Size!\n");
    else{
        s->size = size;
        s->top = -1;
        getStack(s);
    }
}

void freeStack(stack * s){
    free(s->elems);
}

// assignment
stack * initFromArray(elem * l, int listLen, int maxSize){
    if(listLen <= 0){
        printf("Init Failed, the Array is empty\n");
        return NULL;
    }

    if(maxSize <= 0){
        printf("Invalid Size Value!\n");
        return NULL;
    }

    stack * res = (stack *)malloc(sizeof(stack));

    res->size = maxSize > listLen ? listLen : maxSize;    res->top = res->size > listLen ? listLen - 1 : res->size - 1;
    getStack(res);

    for(int i = 0; i <= res->top; i++)
        res->elems[i] = l[i];

    return res;
}

stack * initFromStack(stack * s, int maxSize){
    if(isEmptyStack(s)){
        printf("Stack is Empty!\n");
        return NULL;
    }

    stack * res = (stack *)malloc(sizeof(stack));

    res->size = maxSize > s->size ? s->size : maxSize;
    res->top = res->size > s->top + 1 ? s->top : res->size - 1;
    getStack(res);

    for(int i = 0; i <= res->top; i++)
        res->elems[i] = s->elems[i];

    return res;
}

// print
bool printStack(stack * s){
    if(s->top <= -1){
        printf("Empty Stack\n");
        return FALSE;
    }
    else{
        printf("[");
        for(int i = 0; i <= s->top; i++){
            if(sizeof(elem) == sizeof(char)) printf("%c", s->elems[i]);
            else if(sizeof(elem) <= sizeof(int)) printf("%d", s->elems[i]);
            else printf("%f", s->elems[i]);

            if(i != s->top) printf(", ");
        }
        printf("]");
        return TRUE;
    }
}

// functions
bool pushStack(stack * s, elem x){
    if(isFullStack(s)){
        printf("Overflow!\n");
        return FALSE;
    }

    s->elems[++s->top] = x;
    return TRUE;
}

bool popStack(stack * s){
    if(isEmptyStack(s)){
        printf("Empty Stack!\n");
        return FALSE;
    }

    s->top--;
    return TRUE;
}

elem getPopStack(stack * s){
    if(isEmptyStack(s)){
        printf("Empty Stack!\n");
        return nValue;
    }

    return s->elems[s->top];
}

int lenStack(stack * s){
    return s->top + 1;
}

void makeEmptyStack(stack * s){
    s->top = -1;
}

bool isEmptyStack(stack * s){
    if(s->top == -1) return TRUE;
    else return FALSE;
}

bool isFullStack(stack * s){
    if(s->top + 1 == s->size) return TRUE;
    else return FALSE;
}
