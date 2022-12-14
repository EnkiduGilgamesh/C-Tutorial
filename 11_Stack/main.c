/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \main.c                                                                                    *
* Project: 11_Stack                                                                                *
* Created Date: Thursday Oct 13th 2022, 8:46:50 pm                                                 *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 28/10/2022 09:04:4                                                                *
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
#include <string.h>
#include "infix.h"

#define MAXLEN 20

int main(){
    /*int list[8] = {1, 2, 3, 4, 5, 6, 7, 8};

    stack * s = (stack *)malloc(sizeof(stack));
    initStack(s, 10);

    stack * s1 = initFromArray(list, 8, 10);
    stack * s2 = initFromStack(s1, 10);

    printf("top=%d, size=%d\n", s1->top, s1->size);
    printf("top=%d, size=%d\n", s2->top, s2->size);

    printStack(s1);
    printf("\n");
    printStack(s2);

    pushStack(s1, 9);
    popStack(s1);
    pushStack(s1, 9);
    printStack(s1);
    printf("\n%d\n", getStackTop(s1));*/

    //hanoi(8, 'a', 'b', 'c');

    typedef char elemStack;

    char * infix = (char *)malloc(sizeof(char)*MAXLEN);

    scanf("%s", infix);
    
    int size = strlen(infix);
    
    if(checkInfix(infix, size)){
        char * suffix = (char *)malloc(sizeof(char)*MAXLEN);
        exprInfix2Suffix(infix, size, suffix);
        printf("%s\n", suffix);
    }

    system("pause");
    return 0;
}
