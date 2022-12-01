/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \main.c                                                                                    *
* Project: 21_MyString                                                                             *
* Created Date: Thursday Nov 24th 2022, 11:58:25 am                                                *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 1/12/2022 09:21:43                                                                *
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
#include <time.h>
#include "mystring.h"

int main(){
    char s[] = "ASDHKSAFHGHKVJDBXVASDYUSGCXBVGEWRUYGFBVJHDVJXGAKSFHCKXZBVJCBXJVBJHSGDFHDJSKDFNKJBVJCXBJHGAABBABABAABABAAB";
    char sub[] = "ABABAABAB";
    char good[] = "abcdefeghde";
    char subgood[] = "cde";
    // int len = strlen(good);
    // int * goodSufFix = (int *)malloc(sizeof(int) * len);

    time_t t;
    time(&t);
    printf("Time: %s\n", ctime(&t));
    int pos = findBF(s, sub);
    printf("%d\n", pos);
    time(&t);
    printf("Time: %s\n", ctime(&t));
    pos = findKMP(s, sub);
    printf("%d\n", pos);
    printf("Time: %s\n", ctime(&t));
    pos = findBM(s, sub);
    printf("%d\n", pos);
    printf("Time: %s\n", ctime(&t));

    // genBMGoodFix(good, len, goodSufFix);

    return 0;
}