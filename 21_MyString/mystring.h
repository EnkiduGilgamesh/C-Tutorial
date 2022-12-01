/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \mystring.h                                                                                *
* Project: 21_MyString                                                                             *
* Created Date: Thursday Nov 24th 2022, 9:15:39 am                                                 *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 1/12/2022 09:18:26                                                                *
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
int findBF(const char * s, const char * sub);

// KMP
void genKMPNext(const char * s, const int sLen, int * next);          // generate next array in KMP algorithm
int findKMP(const char * s, const char * sub); 

// BM
void genBMBadChar(const char * s, const int sLen, int * badchar);
void genBMGoodFix(const char * s, const int sLen, int * goodSufFix);
int findBM(const char * s, const char * sub);

#endif
