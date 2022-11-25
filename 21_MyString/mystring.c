/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \mystring.c                                                                                *
* Project: 21_MyString                                                                             *
* Created Date: Thursday Nov 24th 2022, 9:40:35 am                                                 *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 25/11/2022 04:39:56                                                               *
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
int findBF(const char * s, const char * sub){
    int i, j;
    int sLen = strlen(s), subLen = strlen(sub);
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
void genKMPNext(const char * s, const int sLen, int * next){
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

int findKMP(const char * s, const char * sub){        /* find 'sub' in 's' */
    int i, j;
    int sLen = strlen(s), subLen = strlen(sub);
    int * next = (int *)malloc(sizeof(int) * subLen);

    genKMPNext(sub, subLen, next);
   
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
void genBMBadChar(const char * s, const int sLen, int * badChar){
    int i, ascii;
    for(i = 0; i < CHAR_SET_SIZE; i++){
        badChar[i] = -1;                                        // initialize value with -1
    }
    for(i = 0; i < sLen; i++){
        ascii = (int)s[i];                                      // get the ASCII value
        badChar[ascii] = i;                                     // cover the initialized value with the position
    }
}


void genBMGoodFix(const char * s, const int sLen, int * goodFix){
    int i = sLen - 1, j = 0, b_i, b_j;
    for(b_i = 0; b_i < sLen - 1; b_i++) goodFix[b_i] = -1;
    while(j < i){
        b_i = i; b_j = j;
        while(b_j >= 0 && s[b_i] == s[b_j]){
            goodFix[b_i--] = b_j--;
        }
        j++;
    }

    for(int k = 0; k < sLen; k++) printf("%d, ", goodFix[k]);
    printf("\n");
}

int findBM(const char * s, const char * sub){
    int i, j;
    int sLen = strlen(s), subLen = strlen(sub);
    printf("%d, %d", sLen, subLen);
    int * badChar = (int *)malloc(sizeof(int) * CHAR_SET_SIZE);
    int * goodFix = (int *)malloc(sizeof(int) * subLen);
    genBMBadChar(sub, subLen, badChar);
    genBMGoodFix(sub, subLen, goodFix);
    for(i = j = subLen - 1; i < sLen;){
        while(j >= 0 && s[i] == s[j]){
            i--; j--;
        };
        if(j < 0) return i++;
        else{
            i += (subLen - 1 - j + subLen - 1 - \
                (badChar[(int)s[i]] > goodFix[j] ? goodFix[j] : badChar[(int)s[i]]));
            j = subLen - 1;
        }
    }

    return -1;
}
