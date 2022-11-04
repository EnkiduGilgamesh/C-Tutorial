/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \infix.h                                                                                   *
* Project: 11_Stack                                                                                *
* Created Date: Friday Oct 14th 2022, 9:22:47 am                                                   *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 28/10/2022 09:07:31                                                               *
* Modified By: Wenren Muyan                                                                        *
* --------------------------------------------------------------------------------                 *
* Copyright (c) 2022 - future Wenren Muyan                                                         *
* --------------------------------------------------------------------------------                 *
* HISTORY:                                                                                         *
* Date				By				Comments                                                       *
* --------------------------------------------------------------------------------                 *
***************************************************************************************************/

#ifndef __INFIX_H
#define __INFIX_H

#include "stack.h"

int compOper(const char a, const char b);                           // if a and b are the same priority, return 0; if a is higher, return 1; otherwise return -1.
int getPrio(const char op);                                         // if operator is *, /, %, return 1; +, -, return 0.
void exprInfix2Suffix(const char * infixExpr, const int exprSize, char * suffixExpr);
bool checkInfix(const char * infixExpr, const int exprSize);

int calcInfixSuffix(const char * suffixExpr);

#endif
