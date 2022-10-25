/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \infix.h                                                                                   *
* Project: 11_Stack                                                                                *
* Created Date: Friday Oct 14th 2022, 9:22:47 am                                                   *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 25/10/2022 10:29:14                                                               *
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

// void expr2long(const char * expr, const int exprSize, stack * operands, stack * operators);
// void expr2float(const char * expr, const int exprSize, stack * operands, stack * operators);
int compOper(const char a, const char b);                           // if a and b are the same priority, return 0; if a is higher, return 1; otherwise return -1.
int getPrio(const char op);                                         // if operator is *, /, %, return 1; +, -, return 0.
void exprInfix2Suffix(const char * infixExpr, const int exprSize, char * suffixExpr);
void calcInfixSuffix(const char * infixExpr);

#endif
