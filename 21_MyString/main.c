/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \main.c                                                                                    *
* Project: 21_MyString                                                                             *
* Created Date: Thursday Nov 24th 2022, 11:58:25 am                                                *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 25/11/2022 10:54:25                                                               *
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
#include "mystring.h"

int main(){
    char s[] = "AABBABABAABABAAB";
    char sub[] = "ABABAABAB";
    char good[] = "abcdefeghde";
    int len = strlen(good);
    int * goodSufFix = (int *)malloc(sizeof(int) * len);

    //int pos = findBF(s, strlen(s), sub, strlen(sub));

    //printf("%d\n", pos);

    genBMGoodFix(good, len, goodSufFix);

    return 0;
}