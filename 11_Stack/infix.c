/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \infix.c                                                                                   *
* Project: 11_Stack                                                                                *
* Created Date: Thursday Oct 20th 2022, 8:02:14 pm                                                 *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 25/10/2022 10:54:26                                                               *
* Modified By: Wenren Muyan                                                                        *
* --------------------------------------------------------------------------------                 *
* Copyright (c) 2022 - future Wenren Muyan                                                         *
* --------------------------------------------------------------------------------                 *
* HISTORY:                                                                                         *
* Date				By				Comments                                                       *
* --------------------------------------------------------------------------------                 *
***************************************************************************************************/


#include "infix.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//typedef char elemStack;

int getPrio(const char op){
    if(op == '*' || op == '/' || op == '%') return 1;
    else if(op == '+' || op == '-') return 0;
    else return -1;
}

int compOper(const char a, const char b){
    int prioA = getPrio(a), prioB = getPrio(b);
    return prioA - prioB;
}

void exprInfix2Suffix(const char * infixExpr, const int exprSize, char * suffixExpr){
    stack * operands;
    initStack(operands, exprSize);
    int j = 0;
    for(int i = 0; i < exprSize; i++){
        if(infixExpr[i] >= '0' && infixExpr[i] <= '9') suffixExpr[j++] = infixExpr[i];
        else if(infixExpr[i] == '(') pushStack(operands, infixExpr[i]);
        else if(infixExpr[i] == ')'){
            while(getStackTop(operands) != '('){
                suffixExpr[j++] = getStackTop(operands);
                popStack(operands);
                suffixExpr[j] = '\0';
                printf("%s\n", suffixExpr);
            }
            popStack(operands);
        }
        else{
            if(isEmptyStack(operands)) pushStack(operands, suffixExpr[i]);
            while(compOper(infixExpr[i], getStackTop(operands))<=0){
                suffixExpr[j++] = getStackTop(operands);
                popStack(operands);
                //suffixExpr[j] = '\0';
                //printf("%s\n", suffixExpr);
            }
            pushStack(operands, infixExpr[i]);
        }
    }
    printStack(operands);
    printf("\n%d\n", lenStack(operands));
    while(!isEmptyStack(operands)){ 
        suffixExpr[j++] = getStackTop(operands);
        popStack(operands);
    }
    suffixExpr[j] = '\0';
}

