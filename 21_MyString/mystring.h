/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \mystring.h                                                                                *
* Project: 21_MyString                                                                             *
* Created Date: Thursday Nov 24th 2022, 9:15:39 am                                                 *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 24/11/2022 09:01:33                                                               *
* Modified By: Wenren Muyan                                                                        *
* --------------------------------------------------------------------------------                 *
* Copyright (c) 2022 - future Wenren Muyan                                                         *
* --------------------------------------------------------------------------------                 *
* HISTORY:                                                                                         *
* Date				By				Comments                                                       *
* --------------------------------------------------------------------------------                 *
***************************************************************************************************/


#ifndef __MYSTRING_H
#define __MYSTRING_H

#define CHAR_SET_SIZE 256                                             // character set numbers, here is ASCII

typedef enum{FALSE, TRUE} bool;

// BF
int findBF(char * s, int sLen, char * sub, int subLen);

// KMP
void genKMPNext(int * next, char * s, int sLen);                      // generate next array in KMP algorithm
int findKMP(char * s, int sLen, char * sub, int subLen);              // main function

// BM TODO: 
void genBMBadChar(char * s, int sLen, int * badchar);
void genBMGoodFix(char * s, int sLen, int * suffix, bool * prefix);


#endif
