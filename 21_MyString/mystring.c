/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \mystring.c                                                                                *
* Project: 21_MyString                                                                             *
* Created Date: Thursday Nov 24th 2022, 9:40:35 am                                                 *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 24/11/2022 09:01:14                                                               *
* Modified By: Wenren Muyan                                                                        *
* --------------------------------------------------------------------------------                 *
* Copyright (c) 2022 - future Wenren Muyan                                                         *
* --------------------------------------------------------------------------------                 *
* HISTORY:                                                                                         *
* Date				By				Comments                                                       *
* --------------------------------------------------------------------------------                 *
***************************************************************************************************/


#include <string.h>
#include <stdlib.h>
#include "mystring.h"

// BF
int findBF(char * s, int sLen, char * sub, int subLen){
    int i, j;
    for(i = 0; i < sLen; i++){
        if(sLen - i < subLen) return -1;
        int pos = i;
        for(j = 0; j < subLen;){
            if(s[pos++] != sub[j++]) break;
            if(j == subLen) return i;
        }
    }
    return -1;
}

// KMP
void genKMPNext(int * next, char * s, int sLen){
    int i = 0, j = -1;

    next[0] = -1;
    while(i < sLen - 1){
        /**/
        while(j >= 0 && s[i] != s[j])
            /*  */
            j = next[j];
        i++; j++;
        if(s[i] == s[j]) 
            next[i] = next[j];
        else next[i] = j;
    }
}

int findKMP(char * s, int sLen, char * sub, int subLen){        /* find 'sub' in 's' */
    int i, j;
    int * next = (int *)malloc(sizeof(int) * subLen);

    genKMPNext(next, sub, subLen);

    // for(int k = 0; k < subLen; k++) printf("%d, ", next[k]);
    // printf("\n");
   
    for(i = 0, j = 0; i < subLen && j < sLen;){
        if(sub[i] == s[j]){
            i++; j++;
        }
        else if(next[i] >= 0) i = next[i];
        else{
            i = 0; j++;
        }
    }

    if(i >= subLen) return j-subLen;
    else            return -1;                                  /* search failed */
}

// BM
void genBMBadChar(char * s, int sLen, int * badchar){
    int i, ascii;
    for(i = 0; i < CHAR_SET_SIZE; i++){
        badchar[i] = -1;                                        // initialize value with -1
    }
    for(i = 0; i < sLen; i++){
        ascii = (int)s[i];                                      // get the ASCII value
        badchar[ascii] = i;                                     // cover the initialized value with the position
    }
}



void genBMGoodFix(char * s, int sLen, int * sufFix, bool * prefix){
    int i, j, k;
    for(i = 0; i < sLen; i++){                                  // initialize the suffix and prefix
        sufFix[i] = -1;
        // prefix[i] = FALSE;
    }
    for(i = 0; i < sLen - 1; i++){                              // b[0,i]
        j = i;
        k = 0;                                                  // 公共后缀子串长度(模式串尾部取k个出来，分别比较)
        while(j >= 0 && s[j] == s[m-1-k]){                      // 与b[0,m-1]求公共后缀子串
            j--;
            k++;
            suffix[k] = j + 1;
            // 相同后缀子串长度为k时，该子串在b[0,i]中的起始下标
            // (如果有多个相同长度的子串，被赋值覆盖，存较大的)
        }
        if(j == -1)                                 //查找到模式串的头部了
            prefix[k] = TRUE;                       //如果公共后缀子串也是模式串的前缀子串
    }
}
