/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \infix.c                                                                                   *
* Project: 11_Stack                                                                                *
* Created Date: Thursday Oct 20th 2022, 8:02:14 pm                                                 *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 3/11/2022 09:08:12                                                                *
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
    stack * operators;
    initStack(operators, exprSize);
    int j = 0;
    for(int i = 0; i < exprSize; i++){
        if(infixExpr[i] >= '0' && infixExpr[i] <= '9') suffixExpr[j++] = infixExpr[i];
        else if(infixExpr[i] == '(') pushStack(operators, infixExpr[i]);
        else if(infixExpr[i] == ')'){
            while(getStackTop(operators) != '('){
                suffixExpr[j++] = getStackTop(operators);
                popStack(operators);
            }
            popStack(operators);
        }
        else{
            while(1){
                if(isEmptyStack(operators)){
                    pushStack(operators, infixExpr[i]);
                    break;
                }
                else if(getStackTop(operators) == '('){
                    pushStack(operators, infixExpr[i]);
                    break;
                }
                else{
                    if(compOper(infixExpr[i], getStackTop(operators)) <= 0){
                        suffixExpr[j++] = getStackTop(operators);
                        popStack(operators);
                        continue;
                    }
                    else{
                        pushStack(operators, infixExpr[i]);
                        break;
                    }
                }
            }
        }
    }

    while(!isEmptyStack(operators)){ 
        suffixExpr[j++] = getStackTop(operators);
        popStack(operators);
    }
    suffixExpr[j] = '\0';
}               // TODO: minus number and number bigger than 10

bool checkInfix(const char * infixExpr, const int exprSize){
    stack * brackets;
    initStack(brackets, exprSize);

    for (int i = 0; i < exprSize; i++){
        if(infixExpr[i] == '(') pushStack(brackets, infixExpr[i]);
        else if(infixExpr[i] == ')'){
            if(isEmptyStack(brackets)){
                printf("The expression is valid!\n");
                return FALSE;
            }
            else popStack(brackets);
        }
        else continue;
    }

    if(!isEmptyStack(brackets)){
        printf("The expression is valid!\n");
        return FALSE;
    }

    return TRUE;
}                       // TODO: more functions. valid symbol, valid

int calcInfixSuffix(const char * suffixExpr, const int exprSize){
    typedef int elemStack;
    stack * curOperands;
    initStack(curOperands, exprSize);

    int holder = 0;
    pushStack(curOperands, holder);                 // The first number is minus TODO: minus number in brackets

    int res = 0, charop = 0;

    for(int i = 0; i < exprSize; i++){
        if(suffixExpr[i] >= '0' && suffixExpr[i] <= '9'){
            charop = suffixExpr[i] - '0';
            pushStack(curOperands, charop);
            continue;
        }
        else{
            /* get operands */
            int o2 = getStackTop(curOperands);
            popStack(curOperands);
            int o1 = getStackTop(curOperands);
            popStack(curOperands);
            switch(suffixExpr[i]){
                case '+':
                    res = o1 + o2;
                    pushStack(curOperands, res);
                    break;
                case '-':
                    res = o1 + o2;
                    pushStack(curOperands, res);
                    break;
                case '*':
                    res = o1 * o2;
                    pushStack(curOperands, res);
                    break;
                case '/':
                    res = o1 / o2;
                    pushStack(curOperands, res);
                    break;
                case '%':
                    res = o1 % o2;
                    pushStack(curOperands, res);
                    break;
            }
        }
        
    }

    return getStackTop;
}
